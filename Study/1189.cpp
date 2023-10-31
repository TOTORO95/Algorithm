#include <bits/stdc++.h>

using namespace std;

const int maxSize = 8;
int r = 0;  // 1 < r <= 5
int c = 0;  // 1 < c <= 5
int k = 0;  // 1 < k <= r*c

array<array<int, maxSize>, maxSize> fieldMat, visitMat;

array<int, 4> dirY = {-1, 0, 1, 0};
array<int, 4> dirX = {0, 1, 0, -1};
int cnt = 0;
pair<int, int> palyerPos, targetPos;
void DFS(pair<int, int> curPos, int depth) {
    if (curPos == targetPos && depth == k) {
        ++cnt;
        return;
    }
    for (int i = 0; i < 4; ++i) {
        pair<int, int> nextPos(curPos.first + dirY[i], curPos.second + dirX[i]);

        if (nextPos.first < 0 || nextPos.first >= r ||
            nextPos.second < 0 || nextPos.second >= c) {
            continue;
        }
        if (visitMat[nextPos.first][nextPos.second]) {
            continue;
        }

        visitMat[nextPos.first][nextPos.second] = 1;
        DFS(nextPos, depth + 1);
        visitMat[nextPos.first][nextPos.second] = 0;
    }
}

int main() {
    cin >> r >> c >> k;
    char inputCh = ' ';
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> inputCh;
            fieldMat[i][j] = 0;
            if (inputCh == 'T') {
                fieldMat[i][j] = 1;
                visitMat[i][j] = 1;
            }
        }
    }
    targetPos = {0, c - 1};
    palyerPos = {r - 1, 0};
    visitMat[palyerPos.first][palyerPos.second] = 1;
    DFS(palyerPos, 1);
    cout << cnt << "\n";
    return 0;
}