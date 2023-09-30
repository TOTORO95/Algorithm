#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 0;
    string str;
    stack<char> chStack;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        bool checkVaild = true;
        for (int j = 0; j < str.length(); j++) {
            char curCh = str[j];
            if (curCh == ')') {
                if (!chStack.empty() && chStack.top() != curCh) {
                    chStack.pop();
                } else {
                    checkVaild = false;
                    break;
                }
            } else {
                chStack.push(str[j]);
            }
        }

        if (chStack.empty() && checkVaild) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

        while (!chStack.empty()) {
            chStack.pop();
        }
    }
    return 0;
}