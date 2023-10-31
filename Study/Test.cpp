#include <bits/stdc++.h>

using namespace std;

const int maxSize = 8;
int r = 3;  // 1 < r <= 5
int c = 4;  // 1 < c <= 5
int k = 6;  // 1 < k <= r*c

array<array<int, maxSize>, maxSize> fieldMat =
    {
        {{0, 0, 0, 0},
         {0, 1, 0, 0},
         {0, 0, 0, 0}}};

array<array<int, maxSize>, maxSize> visitMat =
    {
        {{0, 0, 0, 0},
         {0, 1, 0, 0},
         {0, 0, 0, 0}}};

array<int, 4> dirY = {-1, 0, 1, 0};
array<int, 4> dirX = {0, 1, 0, -1};
int cnt = 0;
pair<int, int> palyerPos, targetPos;
void DFS(pair<int, int> curPos, int depth) {
    if (curPos == targetPos) {
        if (depth == k) {
            ++cnt;
        }
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
    targetPos = {0, c - 1};
    palyerPos = {r - 1, 0};
    visitMat[palyerPos.first][palyerPos.second] = 1;
    DFS(palyerPos, 1);

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << fieldMat[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}