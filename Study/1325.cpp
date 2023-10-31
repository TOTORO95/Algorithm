#include <bits/stdc++.h>

using namespace std;
int n = 0, m = 0, maxVal = -1;  // n<= 10000, m<=100000

vector<vector<int>> adjVec;
vector<int> visitVec;
vector<int> maxDP;

int DFS(int curIdx) {
    visitVec[curIdx] = 1;
    int ret = 1;

    for (auto nextIdx : adjVec[curIdx]) {
        if (visitVec[nextIdx]) {
            continue;
        }
        ret += DFS(nextIdx);
    }

    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    int memSize = n + 4;
    visitVec.resize(memSize, 0);
    adjVec.resize(memSize, vector<int>());
    maxDP.resize(memSize, 0);

    int a = 0, b = 0;
    for (size_t i = 0; i < m; i++) {
        cin >> a >> b;
        adjVec[b].push_back(a);
    }

    for (size_t i = 0; i <= n; i++) {
        memset(&visitVec[0], 0, sizeof(visitVec[0]) * visitVec.size());
        maxDP[i] = DFS(i);
        maxVal = max(maxVal, maxDP[i]);
    }

    for (size_t i = 0; i < maxDP.size(); i++) {
        if (maxVal == maxDP[i]) {
            cout << i << " ";
        }
    }

    return 0;
}