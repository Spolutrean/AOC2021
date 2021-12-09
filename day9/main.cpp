#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n, m;

bool onField(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};



void firstPart() {
    int k = 100;
    vector<string> field;
    for(int i = 0; i < k; ++i) {
        string s;
        cin >> s;
        field.push_back(s);
    }

    n = field.size();
    m = field[0].size();

    int ans = 0;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            bool lowest = true;

            for(int direction = 0; direction < 4; ++direction) {
                int x = i + dx[direction];
                int y = j + dy[direction];
                if (!onField(x, y)) continue;

                lowest &= field[i][j] < field[x][y];
            }

            if(lowest) {
                ans += (field[i][j] - '0' + 1);
            }
        }
    }

    cout << ans;
}

vector<vector<bool>> used;
int traverseBasins(int x, int y, const vector<string>& field) {
    used[x][y] = true;
    int sum = 1;
    for(int direction = 0; direction < 4; ++direction) {
        int toX = x + dx[direction];
        int toY = y + dy[direction];
        if(!onField(toX, toY) || used[toX][toY]) continue;

        char c = field[x][y];
        char toC = field[toX][toY];
        if (toC > c && toC != '9') {
            sum += traverseBasins(toX, toY, field);
        }
    }

    return sum;
}

void secondPart() {
    int k = 100;
    vector<string> field;
    for(int i = 0; i < k; ++i) {
        string s;
        cin >> s;
        field.push_back(s);
    }

    n = field.size();
    m = field[0].size();

    used = vector<vector<bool>>(n, vector<bool>(m, false));

    vector<int> basins;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            bool lowest = true;

            for(int direction = 0; direction < 4; ++direction) {
                int x = i + dx[direction];
                int y = j + dy[direction];
                if (!onField(x, y)) continue;

                lowest &= field[i][j] < field[x][y];
            }

            if (lowest) {
                basins.push_back(traverseBasins(i, j, field));
            }
        }
    }

    sort(basins.rbegin(), basins.rend());

    cout << basins[0] * basins[1] * basins[2];
}

int main() {
    secondPart();

    return 0;
}
