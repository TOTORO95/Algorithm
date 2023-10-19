#include <bits/stdc++.h>

using namespace std;

const int maxSize = 1004;
int r = 0, c = 0;  // 1 <= r,c <= 1000
array<array<char, maxSize>, maxSize> fieldMap;
array<array<int, maxSize>, maxSize> pVisitMap, fVisitMap;
pair<int, int> playerPos;
vector<pair<int, int>> fireVec;

int dirY[4] = {1, 0, -1, 0};
int dirX[4] = {0, 1, 0, -1};

void BFS(bool player) {
    array<array<int, maxSize>, maxSize>* ptrVisitMap = nullptr;

    if (player) {
        ptrVisitMap = &pVisitMap;
    } else {
        ptrVisitMap = &fVisitMap;
    }

    queue<pair<int, int>> q;
    if (!player) {
        for (int i = 0; i < fireVec.size(); i++) {
            q.push(fireVec[i]);
            (*ptrVisitMap)[fireVec[i].first][fireVec[i].second] = 1;
        }
    } else {
        q.push(playerPos);
        (*ptrVisitMap)[playerPos.first][playerPos.second] = 1;
    }
    int curY = 0, curX = 0;

    while (q.size()) {
        tie(curY, curX) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextY = curY + dirY[i];
            int nextX = curX + dirX[i];

            if (nextY < 0 || nextY >= r || nextX < 0 || nextX >= c) {
                continue;
            }

            if ((*ptrVisitMap)[nextY][nextX] > 0) {
                continue;
            }

            if (fieldMap[nextY][nextX] == '#') {
                continue;
            }
            if (player && fieldMap[nextY][nextX] == 'f') {
                continue;
            }

            q.push({nextY, nextX});
            (*ptrVisitMap)[nextY][nextX] = (*ptrVisitMap)[curY][curX] + 1;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> r >> c;
    fireVec.reserve(c);
    char inputVal;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> inputVal;
            fieldMap[i][j] = inputVal;
            if (fieldMap[i][j] == 'J') {
                playerPos = {i, j};
            }
            if (fieldMap[i][j] == 'F') {
                fireVec.push_back({i, j});
            }
        }
    }

    BFS(true);
    BFS(false);

    int cnt = 999999;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (pVisitMap[i][j] == 0 || fieldMap[i][j] == '#') {
                continue;
            }

            if (i == 0 || i == r - 1 || j == 0 || j == c - 1) {
                if (pVisitMap[i][j] < fVisitMap[i][j]) {
                    cnt = min(cnt, pVisitMap[i][j]);
                } else if (fVisitMap[i][j] == 0) {
                    cnt = min(cnt, pVisitMap[i][j]);
                }
            }
        }
    }
    if (cnt == 999999) {
        cout << "IMPOSSIBLE"
             << "\n";
    } else {
        cout << cnt << "\n";
    }
    return 0;
}