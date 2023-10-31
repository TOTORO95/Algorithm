#include <bits/stdc++.h>

using namespace std;

const int maxSize = 54;
array<array<char, maxSize>, maxSize> fieldMap;
array<array<int, maxSize>, maxSize> visitMap;
int n = 0, m = 0;

int dirY[4] = {1, 0, -1, 0};
int dirX[4] = {0, 1, 0, -1};
int maxDist = 0;

void bfs(int y, int x) {
    memset(&visitMap, 0, sizeof(visitMap));

    visitMap[y][x] = 1;
    queue<pair<int, int>> q;
    q.push({y, x});

    while (q.size()) {
        int curY = 0, curX = 0;
        tie(curY, curX) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nextY = curY + dirY[i];
            int nextX = curX + dirX[i];

            if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) {
                continue;
            }
            if (visitMap[nextY][nextX] || fieldMap[nextY][nextX] == 'W') {
                continue;
            }
            q.push({nextY, nextX});
            visitMap[nextY][nextX] = visitMap[curY][curX] + 1;
            maxDist = max(maxDist, visitMap[nextY][nextX]);
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    string temp = "";
    for (int i = 0; i < n; i++) {
        cin >> temp;
        for (int j = 0; j < m; j++) {
            fieldMap[i][j] = temp[j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (fieldMap[i][j] == 'W') {
                continue;
            }
            bfs(i, j);
        }
    }
    cout << maxDist - 1 << "\n";

    return 0;
}