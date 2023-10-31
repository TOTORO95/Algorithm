#include <bits/stdc++.h>

using namespace std;

const int maxSize = 1028;
int maxLength = 0;
int k = 0;  // 1 <= k <=10

array<int, maxSize> fieldArr;
vector<vector<int>> levelVec;

void makeTree(int l, int r, int level) {
    int mid = (l + r) / 2;
    levelVec[level].push_back(fieldArr[mid]);

    if (l == r) {
        return;
    }
    makeTree(l, mid - 1, level + 1);
    makeTree(mid + 1, r, level + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> k;
    maxLength = pow(2, k) - 1;
    levelVec.resize(k, vector<int>());
    int inputNum = 0;
    for (int i = 0; i < maxLength; i++) {
        cin >> inputNum;
        fieldArr[i] = inputNum;
    }

    makeTree(0, maxLength - 1, 0);

    for (int i = 0; i < levelVec.size(); i++) {
        for (int j = 0; j < levelVec[i].size(); j++) {
            cout << levelVec[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}