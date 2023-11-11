#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, peopleArr[28], ret = INF, comp[28], visited[28];
vector<int> adj[28];
pair<int, int> dfs(int here, int value) {
    visited[here] = 1;
    pair<int, int> ret = {1, peopleArr[here]};
    for (int there : adj[here]) {
        if (comp[there] != value) continue;
        if (visited[there]) continue;
        pair<int, int> _temp = dfs(there, value);
        ret.first += _temp.first;
        ret.second += _temp.second;
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> peopleArr[i];
    }
    int inputSize = 0;
    for (int i = 1; i <= n; i++) {
        cin >> inputSize;
        int inputVal = 0;
        for (int j = 0; j < inputSize; j++) {
            cin >> inputVal;
            adj[i].push_back(inputVal);
            adj[inputVal].push_back(i);
        }
    }

    for (int i = 1; i < (1 << n); i++) {
        fill(comp, comp + 11, 0);
        fill(visited, visited + 11, 0);
        int idx1 = -1, idx2 = -1;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                comp[j + 1] = 1;
                idx1 = j + 1;
            } else
                idx2 = j + 1;
        }
        pair<int, int> comp1 = dfs(idx1, 1);
        pair<int, int> comp2 = dfs(idx2, 0);
        if (comp1.first + comp2.first == n) ret = min(ret, abs(comp1.second - comp2.second));
    }
    cout << (ret == INF ? -1 : ret) << "\n";
}