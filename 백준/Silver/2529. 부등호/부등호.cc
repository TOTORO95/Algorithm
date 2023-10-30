#include <bits/stdc++.h>

using namespace std;

const int maxSize = 15;
int k = 2;  // 2 <= k <= 9
array<char, maxSize> fieldArr;
array<int, maxSize> visitArr;
string answer;
string maxStr = "", minStr = "999999999";

void DFS(int curPos) {
    if (answer.length() == k + 1) {
        maxStr = max(maxStr, answer);
        minStr = min(minStr, answer);
        return;
    }
    for (int i = 9; i >= 0; i--) {
        if (visitArr[i]) {
            continue;
        }
        char curCh = char(i + '0');
        if (!answer.size()) {
            answer.push_back(curCh);
            visitArr[i] = 1;
            DFS(curPos + 1);
            visitArr[i] = 0;
            answer.pop_back();
        } else {
            if (fieldArr[curPos - 1] == '>') {
                if (curCh < answer[curPos - 1]) {
                    answer.push_back(curCh);
                    visitArr[i] = 1;
                    DFS(curPos + 1);
                    visitArr[i] = 0;
                    answer.pop_back();
                }
            } else {
                if (curCh > answer[curPos - 1]) {
                    answer.push_back(curCh);
                    visitArr[i] = 1;
                    DFS(curPos + 1);
                    visitArr[i] = 0;
                    answer.pop_back();
                }
            }
        }
    }
}

int main() {
    cin >> k;
    char inputCh = ' ';
    for (int i = 0; i < k; i++) {
        cin >> inputCh;
        fieldArr[i] = inputCh;
    }
    DFS(0);
    cout << maxStr << "\n";
    cout << minStr << "\n";

    return 0;
}