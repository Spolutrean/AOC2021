#include <iostream>
#include <vector>

using namespace std;

void firstPart() {
    vector<int> arr(9, 0);
    string s;
    cin >> s;
    for (char c : s) {
        if (c != ',') {
            ++arr[c - '0'];
        }
    }

    for(int step = 0; step < 80; ++step) {
        vector<int> newArr(9, 0);
        for(int i = 0; i < arr.size(); ++i) {
            if (i == 0) {
                newArr[6] += arr[0];
                newArr[8] += arr[0];
            } else {
                newArr[i - 1] +=arr[i];
            }
        }

        swap(arr, newArr);
    }

    int ans = 0;
    for(int x : arr) {
        ans += x;
    }

    cout << ans;
}

void secondPart() {
    vector<long long int> arr(9, 0);
    string s;
    cin >> s;
    for (char c : s) {
        if (c != ',') {
            ++arr[c - '0'];
        }
    }

    for(int step = 0; step < 256; ++step) {
        vector<long long int> newArr(9, 0);
        for(int i = 0; i < arr.size(); ++i) {
            if (i == 0) {
                newArr[6] += arr[0];
                newArr[8] += arr[0];
            } else {
                newArr[i - 1] +=arr[i];
            }
        }

        swap(arr, newArr);
    }

    long long int ans = 0;
    for(long long int x : arr) {
        ans += x;
    }

    cout << ans;
}

int main() {
    secondPart();

    return 0;
}
