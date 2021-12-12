#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

struct FirstPart {
    map<string, vector<string>> g;
    map<string, bool> used;
    vector<string> currentPath;
    vector<vector<string>> paths;

    bool isUnlimitedVertex(string v) {
        return v[0] >= 'A' && v[0] <= 'Z';
    }

    void rec(string v) {
        if (v == "end") {
            paths.push_back(currentPath);
            return;
        }

        for (auto to: g[v]) {
            if (used[to]) continue;

            if (!isUnlimitedVertex(to)) {
                used[to] = true;
            }
            currentPath.push_back(to);
            rec(to);
            currentPath.pop_back();
            used[to] = false;
        }
    }

    void solve() {
        int k = 23;

        for (int q = 0; q < k; ++q) {
            string s;
            cin >> s;
            string left, right;
            bool isLeft = true;
            for (char c: s) {
                if (c == '-') {
                    isLeft = false;
                } else {
                    if (isLeft) {
                        left += c;
                    } else {
                        right += c;
                    }
                }
            }

            g[left].push_back(right);
            g[right].push_back(left);
        }

        currentPath.emplace_back("start");
        used["start"] = true;
        rec("start");

        for (auto &path: paths) {
            for (auto &v: path) {
                cout << v << " ";
            }
            cout << "\n";
        }

        cout << paths.size();
    }
};

struct SecondPart {
    map<string, vector<string>> g;
    vector<string> currentPath;
    map<string, int> usedCount;
    vector<vector<string>> paths;

    bool isUnlimitedVertex(string v) {
        return v[0] >= 'A' && v[0] <= 'Z';
    }

    void rec(const string& v) {
        if (v == "end") {
            paths.push_back(currentPath);
            return;
        }

        for (const auto& to: g[v]) {
            if (to == "start") continue;

            usedCount[to]++;
            currentPath.push_back(to);

            int mx = -1;
            int cntIllegal = 0;
            for(pair<string, int> element : usedCount) {
                string vertex = element.first;
                int count = element.second;

                if (isUnlimitedVertex(vertex)) continue;

                cntIllegal += count >= 2;
                mx = max(mx, count);
            }

            if (mx <= 2 && cntIllegal <= 1) {
                rec(to);
            }

            usedCount[to]--;
            currentPath.pop_back();
        }
    }

    void solve() {
        int k = 23;

        for (int q = 0; q < k; ++q) {
            string s;
            cin >> s;
            string left, right;
            bool isLeft = true;
            for (char c: s) {
                if (c == '-') {
                    isLeft = false;
                } else {
                    if (isLeft) {
                        left += c;
                    } else {
                        right += c;
                    }
                }
            }

            g[left].push_back(right);
            g[right].push_back(left);
        }

        usedCount["start"] = 1;
        currentPath.emplace_back("start");
        rec("start");

//        for (auto &path: paths) {
//            for (auto &v: path) {
//                cout << v << " ";
//            }
//            cout << "\n";
//        }

        cout << paths.size();
    }
};

int main() {
//    FirstPart fp;
//    fp.solve();

    SecondPart sp;
    sp.solve();

    return 0;
}
