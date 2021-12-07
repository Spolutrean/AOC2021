#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calcPriceFirstPart(vector<int>& arr, int x) {
    int ans = 0;

    for(auto& el : arr) {
        ans += abs(x - el);
    }

    return ans;
}

void firstPart() {
    string s;
    cin >> s;

    vector<int> arr;
    s += ',';
    int cur = 0;
    for(char c : s) {
        if (c >= '0' && c <= '9') {
            cur *= 10;
            cur += c - '0';
        }
        else {
            arr.push_back(cur);
            cur = 0;
        }
    }

    sort(arr.begin(), arr.end());
    cout << min(calcPriceFirstPart(arr, arr[arr.size() / 2]), calcPriceFirstPart(arr, arr[arr.size() / 2]));
}

int calcPriceSecondPart(vector<int>& arr, int x) {
    int ans = 0;

    for(auto& el : arr) {
        int d = abs(x - el);
        ans += (d * (d + 1)) / 2;
    }

    return ans;
}

void secondPart() {
    string s;
    cin >> s;

    vector<int> arr;
    s += ',';
    int cur = 0, sum = 0;
    for(char c : s) {
        if (c >= '0' && c <= '9') {
            cur *= 10;
            cur += c - '0';
        }
        else {
            arr.push_back(cur);
            sum += cur;
            cur = 0;
        }
    }

    cout << min(calcPriceSecondPart(arr, ceil(1. * sum / arr.size())),
                calcPriceSecondPart(arr, floor(1. * sum / arr.size())));
}

int main() {
    secondPart();

    return 0;
}
