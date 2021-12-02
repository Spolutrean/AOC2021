#include <iostream>
#include <vector>

using namespace std;

void firstPart() {
    int depth = 0;
    int horizontal = 0;

    for (int i = 0; i < 1000; ++i) {
        string s;
        int x;
        cin >> s >> x;
        if (s == "forward") {
            horizontal += x;
        } else if (s == "down") {
            depth += x;
        } else {
            depth -= x;
        };
    }

    cout << horizontal * depth;
}

void secondPart() {
    int depth = 0;
    int horizontal = 0;
    int aim = 0;

    for (int i = 0; i < 1000; ++i) {
        string s;
        int x;
        cin >> s >> x;
        if (s == "forward") {
            horizontal += x;
            depth += aim * x;
        } else if (s == "down") {
            aim += x;
        } else {
            aim -= x;
        };
    }

    cout << horizontal * depth;
}

int main() {
    secondPart();

    return 0;
}
