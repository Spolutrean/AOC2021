#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

map<char, char> pairs = {
        {'(', ')'},
        {'[', ']'},
        {'{', '}'},
        {'<', '>'}
};

void firstPart() {
    map<char, int> points = {
            {')', 3},
            {']', 57},
            {'}', 1197},
            {'>', 25137}
    };

    int k = 102;
    int ans = 0;
    for(int i = 0; i < k; ++i) {
        string s;
        cin >> s;
        vector<char> stack;
        for(char & c : s) {
            if (c == '(' || c == '[' || c == '{' || c == '<') {
                stack.push_back(c);
            } else {
                char front = stack.back();
                if (pairs[front] == c) {
                    stack.pop_back();
                } else {
                    ans += points[c];
                    break;
                }
            }
        }
    }

    cout << ans;
}


void secondPart() {
    map<char, int> points = {
            {')', 1},
            {']', 2},
            {'}', 3},
            {'>', 4}
    };

    int k = 102;
    vector<long long int> completionPoints;
    for(int i = 0; i < k; ++i) {
        string s;
        cin >> s;
        vector<char> stack;
        bool ok = true;
        for(char & c : s) {
            if (c == '(' || c == '[' || c == '{' || c == '<') {
                stack.push_back(c);
            } else {
                char front = stack.back();
                if (pairs[front] == c) {
                    stack.pop_back();
                } else {
                    ok = false;
                    break;
                }
            }
        }

        if(!ok) {
          continue;
        }

        long long int completionScore = 0;
        while(!stack.empty()) {
            completionScore *= 5;
            char correctBrace = pairs[stack.back()];
            stack.pop_back();
            completionScore += points[correctBrace];
        }

        completionPoints.push_back(completionScore);
    }

    sort(completionPoints.begin(), completionPoints.end());

    cout << completionPoints[completionPoints.size() / 2];
}

int main() {
    secondPart();

    return 0;
}
