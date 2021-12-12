#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int n, m;

vector<int> dx = {0,  0,  1, 1, 1, -1, -1, -1};
vector<int> dy = {1, -1, -1, 0, 1, -1,  0,  1};

bool onField(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void firstPart() {
    n = m = 10;

    vector<string> field;
    for(int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        field.push_back(s);
    }

    int ans = 0;
    for(int step = 0; step < 100; ++step) {
        vector<vector<bool>> flashed(n, vector<bool>(m, false));

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                field[i][j]++;
            }
        }

        bool changed;
        do {
            changed = false;
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j) {
                    if (!flashed[i][j] && field[i][j] > '9') {
                        flashed[i][j] = true;
                        ans++;
                        for(int dir = 0; dir < 8; ++dir) {
                            int x = i + dx[dir];
                            int y = j + dy[dir];
                            if (!onField(x, y)) continue;

                            field[x][y]++;
                            changed = true;
                        }
                    }
                }
            }
        } while(changed);

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if (field[i][j] > '9') {
                    field[i][j] = '0';
                }
                cout << field[i][j];
            }
            cout << "\n";
        }
        cout << "\n";
    }

    cout << ans;
}


void secondPart() {
    n = m = 10;

    vector<string> field;
    for(int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        field.push_back(s);
    }

    int ans = 0;
    for(int step = 0;; ++step) {
        vector<vector<bool>> flashed(n, vector<bool>(m, false));

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                field[i][j]++;
            }
        }

        bool changed;
        do {
            changed = false;
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j) {
                    if (!flashed[i][j] && field[i][j] > '9') {
                        flashed[i][j] = true;
                        ans++;
                        for(int dir = 0; dir < 8; ++dir) {
                            int x = i + dx[dir];
                            int y = j + dy[dir];
                            if (!onField(x, y)) continue;

                            field[x][y]++;
                            changed = true;
                        }
                    }
                }
            }
        } while(changed);

        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if (field[i][j] > '9') {
                    field[i][j] = '0';
                    cnt++;
                }
                cout << field[i][j];
            }
            cout << "\n";
        }

        cout << "\n";

        if(cnt == n * m) {
            cout << step + 1;
            return;
        }
    }
}

int main() {
    secondPart();

    return 0;
}
