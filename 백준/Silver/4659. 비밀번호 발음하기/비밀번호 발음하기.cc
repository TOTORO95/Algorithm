#include <bits/stdc++.h>

using namespace std;

string inputVal = "";

set<char> gatherSet = {'a', 'e', 'i', 'o', 'u'};

bool checkFunc(string input) {
    pair<int, int> cntVal = {2, 0};
    int gatherCnt = 0;
    pair<char, int> prevCnt, curCnt;
    for (int i = 0; i < input.length(); i++) {
        curCnt = {input[i], 1};

        if (prevCnt.first != curCnt.first) {
            prevCnt = curCnt;
        } else {
            prevCnt.second++;
            curCnt = prevCnt;
        }

        auto itr = gatherSet.find(input[i]); // 모음 검사
        if (itr != gatherSet.end()) {
            gatherCnt++;
            if (cntVal.first == 0) {
                cntVal.second++;
            } else {
                cntVal = {0, 1};
            }
        } else { // 자음 검사
            if (cntVal.first == 1) {
                cntVal.second++;
            } else {
                cntVal = {1, 1};
            }
        }
        if (curCnt.second >= 2) { // 연속된 값 검사
            if (curCnt.first == 'e' || curCnt.first == 'o') {
                if (curCnt.second >= 3) {
                    return false;
                }
            } else {
                return false;
            }
        }
        if (cntVal.second >= 3) {
            return false;
        }
    }

    if (gatherCnt <= 0) {
        return false;
    }
    return true;
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        cin >> inputVal;
        if (inputVal == "end") {
            break;
        }
        bool enable = checkFunc(inputVal);
        if (enable) {
            cout << "<" << inputVal << "> is acceptable.\n";
        } else {
            cout << "<" << inputVal << "> is not acceptable.\n";
        }
    }

    return 0;
}