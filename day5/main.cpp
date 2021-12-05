#include <iostream>
#include <vector>

using namespace std;

void firstPart() {
    int k = 500;
    vector<vector<int>> matrix(1000, vector<int>(1000, 0));
    for (int l = 0; l < k; ++l) {
        int x1, y1, x2, y2;
        scanf("%d,%d -> %d,%d", &x1, &y1, &x2, &y2);

        if (x1 == x2 || y1 == y2) {
            int curX = x1, curY = y1;
            while(curX != x2 || curY != y2) {
                matrix[curX][curY]++;

                if (curX < x2) curX++;
                else if (curX > x2) curX--;

                if (curY < y2) curY++;
                else if (curY > y2) curY--;
            }

            matrix[curX][curY]++;
        }
    }

    int ans = 0;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            ans += matrix[i][j] > 1;
        }
    }

    cout << ans;
}

void secondPart() {
    int k = 500;
    vector<vector<int>> matrix(1000, vector<int>(1000, 0));
    for (int l = 0; l < k; ++l) {
        int x1, y1, x2, y2;
        scanf("%d,%d -> %d,%d", &x1, &y1, &x2, &y2);

        int curX = x1, curY = y1;
        while(curX != x2 || curY != y2) {
            matrix[curX][curY]++;

            if (curX < x2) curX++;
            else if (curX > x2) curX--;

            if (curY < y2) curY++;
            else if (curY > y2) curY--;
        }

        matrix[curX][curY]++;

    }

    for(int i = 0; i < 10; ++i) {
        for(int j = 0; j < 10; ++j) {
            if (matrix[i][j] > 1) {
                cout << "x";
            } else {
                cout << ".";
            }
        }
        cout << "\n";
    }

    int ans = 0;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            ans += matrix[i][j] > 1;
        }
    }

    cout << ans;
}

int main() {
    secondPart();

    return 0;
}
