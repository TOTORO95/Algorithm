#include <bits/stdc++.h>

using namespace std;

int n; // 1 <= n <= 100
string word, ret;
vector<string> answerVec;

void cvtFunc() {
    while (ret.size()) {
        if (*ret.begin() == '0') {
            ret.erase(ret.begin());
        } else {
            break;
        }
    }
    if (ret.empty()) {
        ret = "0";
    }
    answerVec.push_back(ret);
    ret = "";
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> word;
        ret = "";
        for (int j = 0; j < word.size(); j++) {
            if (word[j] >= '0' && word[j] <= '9') {
                ret += word[j];
            } else if (ret.size()) {
                cvtFunc();
            }
        }
        if (ret.size())
            cvtFunc();
    }

    sort(answerVec.begin(), answerVec.end(), [](string a, string b) {
        if (a.size() == b.size()) {
            return a < b;
        }
        return a.size() < b.size();
    });

    for (auto answer : answerVec) {
        cout << answer << "\n";
    }
    return 0;
}