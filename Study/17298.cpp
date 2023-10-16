#include <bits/stdc++.h>

using namespace std;

int n = 0, val = 0; // 1 <= n <= 1000000
stack<pair<int, int>> valStack;
// idx보다 오른쪽에 있고 커야함
// 큰수중 가장 왼쪽
vector<int> answerVec;
// vector<int> temp = {3, 5, 2, 7};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    answerVec.resize(n, -1);
    for (int i = 0; i < n; i++) {
        cin >> val;
        // val = temp[i];
        if (valStack.empty() || valStack.top().first >= val) {
            valStack.push({val, i});
            continue;
        }

        while (valStack.size() && valStack.top().first < val) {
            answerVec[valStack.top().second] = val;

            valStack.pop();
        }

        valStack.push({val, i});
    }

    for (auto answer : answerVec) {
        cout << answer << " ";
    }

    return 0;
}