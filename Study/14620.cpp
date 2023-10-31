#include <bits/stdc++.h>

using namespace std;

const int maxSize = 24;
int n = 0;  // 6 <= n <= 10
array<array<int, maxSize>, maxSize> fieldMat, visitMat;

array<int, 4> dirY = {-1, 0, 1, 0};
array<int, 4> dirX = {0, 1, 0, -1};

int minVal = 99999999;

bool checkSeed(pair<int, int> curPos) {
    if (visitMat[curPos.first][curPos.second]) {
        return false;
    }
    for (int i = 0; i < 4; i++) {
        pair<int, int> nextPos(curPos.first + dirY[i], curPos.second + dirX[i]);
        if (nextPos.first < 0 || nextPos.first >= n ||
            nextPos.second < 0 || nextPos.second >= n) {
            return false;
        }
        if (visitMat[nextPos.first][nextPos.second]) {
            return false;
        }
    }
    return true;
}

int addFlower(pair<int, int> curPos) {
    visitMat[curPos.first][curPos.second] = 1;
    int val = fieldMat[curPos.first][curPos.second];
    for (int i = 0; i < 4; i++) {
        pair<int, int> nextPos(curPos.first + dirY[i], curPos.second + dirX[i]);
        val += fieldMat[nextPos.first][nextPos.second];
        visitMat[nextPos.first][nextPos.second] = 1;
    }
    return val;
}

void eraseFlower(pair<int, int> curPos) {
    visitMat[curPos.first][curPos.second] = 0;
    for (int i = 0; i < 4; i++) {
        pair<int, int> nextPos(curPos.first + dirY[i], curPos.second + dirX[i]);
        visitMat[nextPos.first][nextPos.second] = 0;
    }
}

void DFS(int cnt, int curVal) {
    if (cnt == 3) {
        minVal = min(minVal, curVal);
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pair<int, int> curPos(i, j);
            if (checkSeed(curPos)) {
                DFS(cnt + 1, curVal + addFlower(curPos));
                eraseFlower(curPos);
            }
        }
    }
}

int main() {
    cin >> n;
    int inputVal = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> fieldMat[i][j];
        }
    }
    DFS(0, 0);
    cout << minVal << "\n";
    return 0;
}