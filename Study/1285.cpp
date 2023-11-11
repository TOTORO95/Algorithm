#include <bits/stdc++.h>

using namespace std;
int n = 0;  // 0 <= n <= 20
array<int, 23> coinArr;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    string inputStr;

    for (int i = 0; i < n; i++) {
        int tempVal = 1;
        cin >> inputStr;
        for (int j = 0; j < inputStr.size(); j++) {
            if (inputStr[j] == 'T') {
                coinArr[i] |= tempVal;
            }
            tempVal = tempVal << 1;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << coinArr[i] << "\n";
    }
    return 0;
}