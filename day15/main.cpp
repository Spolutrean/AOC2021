#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;



struct FirstPart {
    void solve() {
       int n = 100;
       vector<string> field;
       for(int i = 0; i < n; ++i) {
           string s;
           cin >> s;
           field.push_back(s);
       }

       vector<vector<int>> dist(n, vector<int>(field[0].size(), 0));
       for(int i = 0; i < n; ++i) {
           for(int j = 0; j < field[i].size(); ++j) {
               if (i == 0 && j == 0) {
                   dist[i][j] = 0;
                   continue;
               }

               int minPathBefore = 1e9;
               if (i >= 1) {
                   minPathBefore = min(minPathBefore, dist[i - 1][j]);
               }
               if (j >= 1) {
                   minPathBefore = min(minPathBefore, dist[i][j - 1]);
               }

               dist[i][j] = field[i][j] - '0' + minPathBefore;
           }
       }

       cout << dist[n - 1].back();
    }
};

struct SecondPart {
    int elementAt(int i, int j, const vector<string>& field) {
        int n = field.size();
        int m = field[0].size();

        int iBlock = i / n;
        int jBlock = j / m;

        int c = field[i % n][j % m] - '0';
        int result = ((c - 1 + iBlock + jBlock) % 9) + 1;

        return result;
    }

    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};

    void solve() {
        int n = 100;
        vector<string> field;
        for(int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            field.push_back(s);
        }

        int coefficient = 5;
        vector<vector<int>> dist(coefficient * n, vector<int>(coefficient * field[0].size(), 1e9));

        set<pair<int, pair<int,int>>> queue;
        dist[0][0] = 0;
        queue.insert({0, {0, 0}});

        while(!queue.empty()) {
            pair<int, pair<int,int>> f = *queue.begin();
            queue.erase(queue.begin());

            int x = f.second.first;
            int y = f.second.second;

            for(int d = 0; d < 4; ++d) {
                int toX = x + dx[d];
                int toY = y + dy[d];

                if (toX < 0 || toX >= dist.size() || toY < 0 || toY >= dist[0].size()) {
                    continue;
                }

                int curDist = dist[toX][toY];
                int newDist = dist[x][y] + elementAt(toX, toY, field);
                if (newDist < curDist) {
                    dist[toX][toY] = newDist;
                    queue.insert({newDist, {toX, toY}});
                }
            }
        }

        cout << dist.back().back();
    }
};

int main() {
//    FirstPart fp;
//    fp.solve();

    SecondPart sp;
    sp.solve();

    return 0;
}
