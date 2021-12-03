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

void firstPart() {
    vector<string> v;
    for(int i = 0; i < 1000; ++i) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    string res1, res2;
    for(int bit = 0; bit < v[0].size(); ++bit) {
        pair<int, int> p = calcRate(v, bit);
        int count0 = p.first, count1 = p.second;

        res1 += (char)((int)(count0 > count1) + '0');
        res2 += (char)((int)(count0 < count1) + '0');
    }

    cout << strToInt(res1) * strToInt(res2);
}

void secondPart() {
    vector<string> v;
    for(int i = 0; i < 1000; ++i) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    int res1, res2;
    int bit = 0;
    vector<string> v1(v);
    while(v1.size() > 1 && bit < v[0].size()) {
        pair<int, int> rate = calcRate(v1, bit);
        char neededChar = (char)((rate.first > rate.second ? 0 : 1) + '0');
        vector<string> tmp;
        for(auto & number : v1) {
            if (number[bit] == neededChar) {
                tmp.push_back(number);
            }
        }

        v1 = tmp;
        bit++;
    }
    res1 = strToInt(v1[0]);


    bit = 0;
    vector<string> v2(v);
    while(v2.size() > 1 && bit < v[0].size()) {
        pair<int, int> rate = calcRate(v2, bit);
        char neededChar = (char)((rate.first <= rate.second ? 0 : 1) + '0');
        vector<string> tmp;
        for(auto & number : v2) {
            if (number[bit] == neededChar) {
                tmp.push_back(number);
            }
        }

        v2 = tmp;
        bit++;
    }
    res2 = strToInt(v2[0]);

    cout << res1 * res2;
}

int main() {
    secondPart();

    return 0;
}
