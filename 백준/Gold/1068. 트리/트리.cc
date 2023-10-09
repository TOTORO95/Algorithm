#include <bits/stdc++.h>

using namespace std;

const size_t maxSize = 52;
int n = 0, rootNode = 0, removeNode = 0, cnt = 0;  // 0 <= n <= 50
vector<vector<int>> treeMat(maxSize);

void dfs(int node) {
    if (treeMat[node].empty() || (treeMat[node].size() == 1 && treeMat[node].front() == removeNode)) {
        cnt++;
        return;
    }

    for (auto leaf : treeMat[node]) {
        if (leaf == removeNode) {
            continue;
        }
        dfs(leaf);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        treeMat.reserve(maxSize);
    }

    int parentNd = 0;
    for (int i = 0; i < n; i++) {
        cin >> parentNd;
        if (parentNd == -1) {
            rootNode = i;
            continue;
        }
        treeMat[parentNd].emplace_back(i);
    }
    cin >> removeNode;

    if (removeNode != rootNode) {
        // cout << "DFS돌입 rootNode = " << rootNode;
        dfs(rootNode);
    }

    cout << cnt;
    return 0;
}