#include <bits/stdc++.h>

using namespace std;

const int maxSize = 1504;
int r = 0, c = 0, cntTime = 0;
array<array<int, maxSize>, maxSize> fieldMat, visitSwanMat, visitWaterMat;
array<int, 4> dirY = {1, 0, -1, 0};
array<int, 4> dirX = {0, 1, 0, -1};
bool flag = false;

queue<pair<int, int>> swanQ, waterQ, water_TempQ, swan_TempQ;
void printMat(const array<array<int, maxSize>, maxSize>& mat) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}
void queueClear(queue<pair<int, int>>& q) {
    queue<pair<int, int>> emptyQ;
    swap(q, emptyQ);
}

void BFS() {  // 물 체크
    while (waterQ.size()) {
        pair<int, int> curPos = waterQ.front();
        waterQ.pop();

        for (int i = 0; i < 4; i++) {
            pair<int, int> nextPos = {curPos.first + dirY[i], curPos.second + dirX[i]};
            if (nextPos.first < 0 || nextPos.first >= r || nextPos.second < 0 || nextPos.second >= c) {
                continue;
            }

            if (visitWaterMat[nextPos.first][nextPos.second]) {
                continue;
            }
            if (fieldMat[nextPos.first][nextPos.second] == 1) {
                visitWaterMat[nextPos.first][nextPos.second] = 1;
                fieldMat[nextPos.first][nextPos.second] = 0;
                water_TempQ.push(nextPos);
                continue;
            }
        }
    }
}

bool meetSwan() {  // 백조 만남 체크
    while (swanQ.size()) {
        auto curPos = swanQ.front();
        swanQ.pop();

        for (int i = 0; i < 4; i++) {
            pair<int, int> nextPos(curPos.first + dirY[i], curPos.second + dirX[i]);
            if (nextPos.first < 0 || nextPos.first >= r || nextPos.second < 0 || nextPos.second >= c) {
                continue;
            }
            if (visitSwanMat[nextPos.first][nextPos.second]) {
                continue;
            }

            visitSwanMat[nextPos.first][nextPos.second] = 1;
            auto nextTile = fieldMat[nextPos.first][nextPos.second];
            if (nextTile == 0) {
                swanQ.push(nextPos);
            } else if (nextTile == 1) {
                swan_TempQ.push(nextPos);
            } else if (nextTile == 2) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> r >> c;
    char inputVal = ' ';

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> inputVal;
            if (inputVal == '.') {
                waterQ.push({i, j});
                fieldMat[i][j] = 0;
                visitWaterMat[i][j] = 1;
            } else if (inputVal == 'X') {
                fieldMat[i][j] = 1;
            } else {  // 백조
                waterQ.push({i, j});
                visitWaterMat[i][j] = 1;
                if (swanQ.empty()) {
                    swanQ.push({i, j});
                } else {
                    fieldMat[i][j] = 2;
                }
            }
        }
    }

    while (!meetSwan()) {
        BFS();
        waterQ = water_TempQ;
        swanQ = swan_TempQ;
        queueClear(water_TempQ);
        queueClear(swan_TempQ);
        cntTime++;
    }

    cout << cntTime;

    return 0;
}