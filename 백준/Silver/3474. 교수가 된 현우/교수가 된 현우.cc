#include <bits/stdc++.h>

using namespace std;
int t = 0, testCase = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    cin >> t;
    for (int i = 0; i < t; i++) {
        int val = 0;
        cin >> testCase;
        while (testCase >= 5) {
            testCase /= 5;
            val += testCase;
        }
        cout << val << "\n";
    }

    return 0;
}