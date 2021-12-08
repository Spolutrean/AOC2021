#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void firstPart() {
    int k = 200;
    int ans = 0;
    for(int q = 0; q < k; ++q) {
        vector<string> input(10);
        for (auto &s: input) {
            cin >> s;
        }

        string del;
        cin >> del;

        vector<string> query(4);
        for (auto &s: query) {
            cin >> s;
        }

        for (auto &s: query) {
            ans += s.size() == 2 || s.size() == 4 || s.size() == 3 || s.size() == 7;
        }
    }

    cout << ans;
}

string decode(string perm, string toDecode) {
    string decoded;
    for (char c : toDecode) {
        decoded += perm[c - 'a'];
    }

    sort(decoded.begin(), decoded.end());

    return decoded;
}

void secondPart() {
    vector<string> alph = {"abcefg", "cf", "acdeg", "acdfg", "bcdf", "abdfg", "abdefg", "acf", "abcdefg", "abcdfg"};

    int k = 200;
    int ans = 0;
    for(int q = 0; q < k; ++q) {
        vector<string> input(10);
        for (auto &s: input) {
            cin >> s;
        }

        string del;
        cin >> del;

        vector<string> query(4);
        for (auto &s: query) {
            cin >> s;
        }

        string perm = "abcdefg";
        do {
            bool ok = true;
            for(int i = 0; i <= 9; ++i) {
                string decoded = decode(perm, input[i]);

                bool found = false;
                for(const string& num : alph) {
                    found |= num == decoded;
                }

                ok &= found;
            }

            if (ok) {
                break;
            }
        } while(next_permutation(perm.begin(), perm.end()));

        int number = 0;
        for(int i = 0; i < 4; ++i) {
            string decoded = decode(perm, query[i]);
            for(int digit = 0; digit <= 9; ++digit) {
                if (alph[digit] == decoded) {
                    number *= 10;
                    number += digit;
                    break;
                }
            }
        }

        cout << number << "\n";
        ans += number;
    }

    cout << ans;
}

int main() {
    secondPart();

    return 0;
}
