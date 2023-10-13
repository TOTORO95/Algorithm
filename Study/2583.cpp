#include <bits/stdc++.h>

using namespace std;

int m = 0, n = 0, k = 0;
array<int, 4> dirY = {0, 1, 0, -1}, dirX = {1, 0, -1, 0};
array<array<int, 104>, 104> filedMap;
vector<int> answer;
int DFS(int cY, int cX, int ret) {
    filedMap[cY][cX] = 1;
    for (int i = 0; i < 4; i++) {
        int nY = cY + dirY[i];
        int nX = cX + dirX[i];

        if (nY < 0 || nY >= m || nX < 0 || nX >= n) {
            continue;
        }

        if (filedMap[nY][nX] == 0) {
            ret = DFS(nY, nX, ret + 1);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n >> k;

    int x1, x2, y1, y2;

    for (int i = 0; i < k; i++) {
        cin >> x1 >> y1 >> x2 >> y2;

        for (int row = y1; row < y2; row++) {
            for (int col = x1; col < x2; col++) {
                filedMap[row][col]++;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (filedMap[i][j] == 0) {
                answer.push_back(DFS(i, j, 1));
            }
        }
    }
    sort(answer.begin(), answer.end());
    cout << answer.size() << "\n";
    for (auto ret : answer) {
        cout << ret << " ";
    }

    return 0;
}