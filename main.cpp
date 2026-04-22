#include <bits/stdc++.h>
using namespace std;

struct Student {
    string id;
    string name;
    int score;
    size_t add_idx; // insertion order index
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Student> students;
    students.reserve(10000);
    unordered_map<string, size_t> id_to_idx;
    unordered_map<string, size_t> name_to_idx;

    int cmd;
    while (cin >> cmd) {
        if (cmd == 1) {
            string id, name;
            int score;
            if (!(cin >> id >> name >> score)) {
                break;
            }
            if (id_to_idx.find(id) != id_to_idx.end()) {
                cout << "FAILED\n";
                continue;
            }
            Student st{ id, name, score, students.size() };
            id_to_idx[id] = students.size();
            name_to_idx[name] = students.size();
            students.push_back(std::move(st));
            cout << "SUCCESS\n";
        } else if (cmd == 2) {
            if (!students.empty()) {
                for (const auto &st : students) {
                    cout << st.id << ' ' << st.name << ' ' << st.score << '\n';
                }
            }
        } else if (cmd == 3) {
            string id;
            if (!(cin >> id)) break;
            auto it = id_to_idx.find(id);
            if (it != id_to_idx.end()) {
                const Student &st = students[it->second];
                cout << st.id << ' ' << st.name << ' ' << st.score << '\n';
            }
        } else if (cmd == 4) {
            string name;
            if (!(cin >> name)) break;
            auto it = name_to_idx.find(name);
            if (it != name_to_idx.end()) {
                const Student &st = students[it->second];
                cout << st.id << ' ' << st.name << ' ' << st.score << '\n';
            }
        } else if (cmd == 5) {
            if (!students.empty()) {
                vector<size_t> idx(students.size());
                iota(idx.begin(), idx.end(), 0);
                sort(idx.begin(), idx.end(), [&](size_t a, size_t b){
                    return students[a].id < students[b].id;
                });
                for (size_t i : idx) {
                    const Student &st = students[i];
                    cout << st.id << ' ' << st.name << ' ' << st.score << '\n';
                }
            }
        } else if (cmd == 6) {
            if (!students.empty()) {
                vector<size_t> idx(students.size());
                iota(idx.begin(), idx.end(), 0);
                stable_sort(idx.begin(), idx.end(), [&](size_t a, size_t b){
                    return students[a].score > students[b].score;
                });
                for (size_t i : idx) {
                    const Student &st = students[i];
                    cout << st.id << ' ' << st.name << ' ' << st.score << '\n';
                }
            }
        } else if (cmd == 7) {
            cout << "END\n";
            return 0;
        } else {
            // Unknown command, ignore line
            string line;
            getline(cin, line);
        }
    }

    return 0;
}

