#include <bits/stdc++.h>

using namespace std;

const int maxSize = 304;
int n = 0, m = 0, cntTime = 0;  // 1 <= n,m <= 300
array<array<int, maxSize>, maxSize> fieldMat, visitMat;
typedef struct Pos {
    int _y;
    int _x;
    void normalize() {
        _y += -1;
        _x += -1;
    };

    Pos(int y, int x) : _y(y), _x(x){};

} pos_t;
pos_t playerPos(0, 0), targetPos(0, 0);

array<int, 4> dirY = {-1, 0, 1, 0};
array<int, 4> dirX = {0, 1, 0, -1};
void BFS() {
    queue<pos_t> q;

    q.push(playerPos);
    visitMat[playerPos._y][playerPos._x] = cntTime;

    while (q.size()) {
        pos_t curPos = q.front();
        q.pop();
        if (visitMat[targetPos._y][targetPos._x] == 0) {
            return;
        }

        for (int j = 0; j < 4; j++) {
            pos_t nextPos(curPos._y + dirY[j], curPos._x + dirX[j]);

            if (nextPos._y < 0 || nextPos._y >= n || nextPos._x < 0 || nextPos._x >= m) {
                continue;
            }
            if (visitMat[nextPos._y][nextPos._x] == cntTime) {
                continue;
            }

            if (fieldMat[nextPos._y][nextPos._x] == 1) {
                fieldMat[nextPos._y][nextPos._x] = 0;
                visitMat[nextPos._y][nextPos._x] = cntTime;
                continue;
            }

            visitMat[nextPos._y][nextPos._x] = cntTime;
            q.push(nextPos);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    cin >> playerPos._y >> playerPos._x >> targetPos._y >> targetPos._x;
    playerPos.normalize();
    targetPos.normalize();
    char inputCh = ' ';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> inputCh;
            fieldMat[i][j] = inputCh - '0';
            if (inputCh == '*') {
                fieldMat[i][j] = 2;
            } else if (inputCh == '#') {
                fieldMat[i][j] = 3;
            }
        }
    }
    memset(&visitMat, -1, sizeof(visitMat));
    while (visitMat[targetPos._y][targetPos._x] == -1) {
        memset(&visitMat, -1, sizeof(visitMat));
        BFS();
        cntTime++;
    }
    cout << cntTime << "\n";
    return 0;
}