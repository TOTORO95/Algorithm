#include <bits/stdc++.h>

using namespace std;

bool checkFunc(string str, stack<char> chSt) {
    bool checkVaild = true;
    for (int i = 0; i < str.length(); i++) {
        char curCh = str[i];
        if (curCh == '(' || curCh == '[') {
            chSt.push(curCh);
        }

        if (curCh == ')') {
            if (!chSt.empty() && chSt.top() == '(') {
                chSt.pop();
            } else {
                checkVaild = false;
            }
        }

        if (curCh == ']') {
            if (!chSt.empty() && chSt.top() == '[') {
                chSt.pop();
            } else {
                checkVaild = false;
            }
        }

        if (!checkVaild) {
            break;
        }
    }

    while (!chSt.empty()) {
        chSt.pop();
        checkVaild = false;
    }

    return checkVaild;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    stack<char> chStack;
    while (true) {
        getline(cin, str);
        if (str == ".") {
            return 0;
        }
        if (checkFunc(str, chStack)) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }

    return 0;
}