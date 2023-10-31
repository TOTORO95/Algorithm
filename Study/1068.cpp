#include <bits/stdc++.h>

using namespace std;

const int maxSize = 50;
int n = 0, val = 0, rootNode = -2, eraseNode = -2;  // n <=50;
vector<int> adjVec[54];

int DFS(int curNode) {
    int ret = 0;
    int childCnt = 0;
    for (auto childNode : adjVec[curNode]) {
        if (childNode == eraseNode) {
            continue;
        }
        ret += DFS(childNode);
        childCnt++;
    }

    if (childCnt == 0) {
        return 1;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (size_t i = 0; i < n; i++) {
        cin >> val;
        if (val == -1) {
            rootNode = i;
            continue;
        }
        adjVec[val].emplace_back(i);
    }
    cin >> eraseNode;

    if (rootNode == eraseNode) {
        cout << 0;
    } else {
        cout << DFS(rootNode);
    }

    return 0;
}