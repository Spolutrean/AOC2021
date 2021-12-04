#include <iostream>
#include <vector>

using namespace std;

int strToInt(const string& s) {
    int res = 0;
    for(char i : s) {
        res *= 2;
        res += i - '0';
    }

    return res;
}

pair<int, int> calcRate(const vector<string> &v, int bit) {
    int count0 = 0, count1 = 0;
    for(auto & number : v) {
        count0 += number[bit] == '0';
        count1 += number[bit] == '1';
    }

    return {count0, count1};
}

bool checkMatrix(vector<vector<int>> m) {
    bool hasVertical = false, hasHorizontal = false;
    for(int i = 0; i < 5; ++i) {
        bool thisVertical = true;
        bool thisHorizontal = true;
        for(int j = 0; j < 5; ++j) {
            thisVertical &= (m[i][j] == -1);
            thisHorizontal &= (m[j][i] == -1);
        }

        hasVertical |= thisVertical;
        hasHorizontal |= thisHorizontal;
    }

    return hasVertical || hasHorizontal;
}

void firstPart() {
    int k = 100;
    vector<vector<vector<int>>> matrixes (k, vector<vector<int>> (5, vector<int> (5)));

    string s_nums;
    cin >> s_nums;
    s_nums += ",";
    vector<int> nums;
    int cur_Number = 0;
    for (char c : s_nums) {
        if (c >= '0' && c <= '9') {
            cur_Number *= 10;
            cur_Number += c - '0';
        } else {
            nums.push_back(cur_Number);
            cur_Number = 0;
        }
    }

    for (int mn = 0; mn < k; ++mn) {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                cin >> matrixes[mn][i][j];
            }
        }
    }

    for (int num : nums) {
        for(auto &m : matrixes) {
            int sum = 0;
            for(int i = 0; i < 5; ++i) {
                for(int j = 0; j < 5; ++j) {
                    if (m[i][j] == num) {
                        m[i][j] = -1;
                    }

                    if (m[i][j] != -1) {
                        sum += m[i][j];
                    }
                }
            }

            if (checkMatrix(m)) {
                cout << sum * num;
                return;
            }
        }
    }
}

void secondPart() {
    int k = 100;
    vector<vector<vector<int>>> matrixes (k, vector<vector<int>> (5, vector<int> (5)));

    string s_nums;
    cin >> s_nums;
    s_nums += ",";
    vector<int> nums;
    int cur_Number = 0;
    for (char c : s_nums) {
        if (c >= '0' && c <= '9') {
            cur_Number *= 10;
            cur_Number += c - '0';
        } else {
            nums.push_back(cur_Number);
            cur_Number = 0;
        }
    }

    for (int mn = 0; mn < k; ++mn) {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                cin >> matrixes[mn][i][j];
            }
        }
    }
    vector<int> history;

    for (int num : nums) {
        for(auto &m : matrixes) {
            if (checkMatrix(m)) continue;

            int sum = 0;
            for(int i = 0; i < 5; ++i) {
                for(int j = 0; j < 5; ++j) {
                    if (m[i][j] == num) {
                        m[i][j] = -1;
                    }

                    if (m[i][j] != -1) {
                        sum += m[i][j];
                    }
                }
            }

            if (checkMatrix(m)) {
                history.push_back(sum * num);
            }
        }
    }

    cout << history.back();
}

int main() {
    secondPart();

    return 0;
}
