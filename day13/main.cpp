#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

vector<vector<bool>> fold(vector<vector<bool>> field, bool byX, int position) {
    int ySize = field.size();
    int xSize = field[0].size();

    int newYSize = ySize;
    int newXSize = xSize;
    if (byX) newXSize = position;
    else newYSize = position;
    vector<vector<bool>> newField(newYSize, vector<bool>(newXSize, false));

    for(int y = 0; y < ySize; ++y) {
        for(int x = 0; x < xSize; ++x) {
            if (byX && x == position || !byX && y == position) {
                continue;
            }

            int newX = x;
            int newY = y;

            if (byX && x > position) {
                newX = position - (x - position);
            } else if (!byX && y > position) {
                newY = position - (y - position);
            }

            //cout << newY << " " << newX << " " << y << " " << x << "\n";
            newField[newY][newX] = newField[newY][newX] || field[y][x];
        }
    }


    return newField;
}

struct FirstPart {
    void solve() {
        vector<pair<int,int>> points;
        int maxY = 0, maxX = 0;
        int pointsCount = 923, commandsCount = 12;
        //int pointsCount = 18, commandsCount = 1;

        for(int i = 0; i < pointsCount; ++i) {
            int x, y;
            scanf("%d,%d\n", &x, &y);

            points.emplace_back(y, x);
            maxY = max(maxY, y);
            maxX = max(maxX, x);
        }

        maxY++;
        maxX++;

        vector<vector<bool>> field(maxY, vector<bool>(maxX, false));
        for(auto & point : points) {
            field[point.first][point.second] = true;
        }

        for(int command = 0; command < commandsCount; ++command) {
            string trash;
            cin >> trash >> trash >> trash;

            bool byX = trash[0] == 'x';
            int position = 0;
            for(char & c : trash) {
                if (c >= '0' && c <= '9') {
                    position *= 10;
                    position += c - '0';
                }
            }

            field = fold(field, byX, position);

            if (command == commandsCount - 1) {
                for (auto &i: field) {
                    for (auto &&cell: i) {
                        cout << (cell ? '*' : '.');
                    }
                    cout << "\n";
                }
                cout << "\n";
            }

            break;
        }

        int ans = 0;
        for(auto & i : field) {
            for(auto && cell : i) {
                ans += cell;
            }
        }

        cout << ans;
    }
};

struct SecondPart {
    void solve() {
        vector<pair<int,int>> points;
        int maxY = 0, maxX = 0;
        int pointsCount = 923, commandsCount = 12;
        //int pointsCount = 18, commandsCount = 1;

        for(int i = 0; i < pointsCount; ++i) {
            int x, y;
            scanf("%d,%d\n", &x, &y);

            points.emplace_back(y, x);
            maxY = max(maxY, y);
            maxX = max(maxX, x);
        }

        maxY++;
        maxX++;

        vector<vector<bool>> field(maxY, vector<bool>(maxX, false));
        for(auto & point : points) {
            field[point.first][point.second] = true;
        }

        for(int command = 0; command < commandsCount; ++command) {
            string trash;
            cin >> trash >> trash >> trash;

            bool byX = trash[0] == 'x';
            int position = 0;
            for(char & c : trash) {
                if (c >= '0' && c <= '9') {
                    position *= 10;
                    position += c - '0';
                }
            }

            field = fold(field, byX, position);

            if (command == commandsCount - 1) {
                for (auto &i: field) {
                    for (auto &&cell: i) {
                        cout << (cell ? '*' : '.');
                    }
                    cout << "\n";
                }
                cout << "\n";
            }
        }
    }
};

int main() {
    FirstPart fp;
    fp.solve();

    SecondPart sp;
    sp.solve();

    return 0;
}
