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
       string word;
       cin >> word;

       scanf("\n");

       int rulesCount = 100;
       map<pair<char, char>, char> rules;
       for(int i = 0; i < rulesCount; ++i) {
           char r1, r2, t;
           scanf("%c%c -> %c", &r1, &r2, &t);
           if (i != rulesCount-1) {
               scanf("\n");
           }
           rules[{r1, r2}] = t;
       }

       for(int step = 0; step < 10; ++step) {
           string newWord;
           newWord += word[0];
           for(int i = 1; i < word.size(); ++i) {
               newWord += rules[{ newWord.back(), word[i]}];
               newWord += word[i];
           }

           word = newWord;
           cout << word << "\n";
       }

       map<char, int> counters;
       for(char c : word) {
           counters[c]++;
       }
       int mx = -1;
       int mn = 1e9;
       for(pair<char, int> p : counters) {
           mx = max(mx, p.second);
           mn = min(mn, p.second);
       }

       cout << mx - mn;
    }
};

struct SecondPart {
    void solve() {
        string word;
        cin >> word;

        scanf("\n");

        int rulesCount = 100;
        map<pair<char, char>, char> rules;
        for(int i = 0; i < rulesCount; ++i) {
            char r1, r2, t;
            scanf("%c%c -> %c", &r1, &r2, &t);
            if (i != rulesCount-1) {
                scanf("\n");
            }
            rules[{r1, r2}] = t;
        }

        map<pair<char, char>, long long int> pairs;
        map<char, long long int> counters;
        for(int i = 0; i < word.size(); ++i) {
            counters[word[i]]++;

            if (i > 0) {
                pairs[{word[i - 1], word[i]}]++;
            }
        }

        for(int step = 0; step < 40; ++step) {
            map<pair<char, char>, long long int> newPairs;
            map<char, long long int> newCounters;

            for(const auto & p : pairs) {
                char l = p.first.first, r = p.first.second;
                long long int count = p.second;

                char m = rules[{l, r}];
                newPairs[{l, m}] += count;
                newPairs[{m, r}] += count;
                newCounters[l] += count;
                newCounters[m] += 2 * count;
                newCounters[r] += count;
            }

            counters = newCounters;
            pairs = newPairs;
        }

        counters[word[0]]++;
        counters[word.back()]++;

        long long int mx = -1;
        long long int mn = 1e18;
        for(auto & p : counters) {
            long long int count = p.second / 2ll;
            mx = max(mx, count);
            mn = min(mn, count);
        }

        cout << mx - mn;
    }
};

int main() {
//    FirstPart fp;
//    fp.solve();

    SecondPart sp;
    sp.solve();

    return 0;
}
