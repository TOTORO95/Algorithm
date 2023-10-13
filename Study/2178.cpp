#include <bits/stdc++.h>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n = 0, m = 0;
int cx = 0, cy = 0;

int main() {
    scanf("%d %d", &n, &m);
    vector<vector<int>> mazeMap(n, vector<int>(m, 0));
    vector<vector<int>> visited(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &mazeMap[i][j]);
        }
    }

    queue<pair<int, int>> q;
    visited[0][0] = 1;
    q.push({0, 0});
    while (q.size()) {
        tie(cy, cx) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
                continue;
            }
            if (mazeMap[ny][nx] == 0 || visited[ny][nx]) {
                continue;
            }

            visited[ny][nx] = visited[cy][cx] + 1;
            q.push({ny, nx});
        }
    }
    cout << visited[n - 1][m - 1];
    return 0;
}
