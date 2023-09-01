#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    vector<int> chVec('Z' + 1, 0);
    cin.tie(NULL);

    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        chVec[str[i]]++;
    }

    int oddNum = 0;
    string answer;
    for (int i = 'Z'; i >= 'A'; i--) {
        if (chVec[i] == 0) {
            continue;
        }
        if (chVec[i] & 1) {
            oddNum++;
            answer.insert(answer.begin() + answer.length() / 2, char(i));
            chVec[i]--;
        }
        if (oddNum > 1) {
            cout << "I'm Sorry Hansoo";
            return 0;
        }

        for (int cnt = chVec[i]; cnt > 0; cnt -= 2) {
            answer.insert(answer.begin(), char(i));
            answer.insert(answer.end(), char(i));
        }
    }
    cout << answer << "\n";

    return 0;
}