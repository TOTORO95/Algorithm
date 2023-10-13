#include <bits/stdc++.h>

using namespace std;

int main() {
    string str, reverStr;
    cin >> str;

    reverStr = str;
    reverse(reverStr.begin(), reverStr.end());

    if (reverStr == str) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}