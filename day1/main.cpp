#include <iostream>
#include <vector>

using namespace std;

void firstPart() {
    vector<int> arr;
    for (int i = 0; i < 2000; ++i) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    int ans = 0;
    for(int i = 1; i < arr.size(); ++i) {
        ans += arr[i] > arr[i - 1];
    }

    cout << ans;
}

void secondPart() {
    vector<int> arr;
    for (int i = 0; i < 2000; ++i) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    int ans = 0;
    for(int i = 3; i < arr.size(); ++i) {
        ans += arr[i] > arr[i - 3];
    }

    cout << ans;
}

int main() {
    secondPart();

    return 0;
}
