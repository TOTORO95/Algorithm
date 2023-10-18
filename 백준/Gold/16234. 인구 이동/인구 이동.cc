#include <bits/stdc++.h>

using namespace std;

const int maxSize = 54;
int n = 0;         // 1 <= n <= 50
int l = 0, r = 0;  // 1 <= l <= r <= 100
int totalNum = 0;
int dirY[4] = {1, 0, -1, 0};
int dirX[4] = {0, 1, 0, -1};

array<array<int, maxSize>, maxSize> fielddMap, visitMap;
vector<pair<int, int>> calculVec;
bool enableMove(int curY, int curX, int nextY, int nextX) {
    int diffNum = abs(fielddMap[nextY][nextX] - fielddMap[curY][curX]);
    if (diffNum >= l && diffNum <= r) {
        return true;
    }
    return false;
}

void bfs(int y, int x) {
    queue<pair<int, int>> q;
    visitMap[y][x] = 1;
    calculVec.push_back({y, x});
    q.push({y, x});
    totalNum += fielddMap[y][x];

    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nextY = y + dirY[i];
            int nextX = x + dirX[i];

            if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n) {
                continue;
            }
            if (visitMap[nextY][nextX]) {
                continue;
            }
            if (enableMove(y, x, nextY, nextX)) {
                q.push({nextY, nextX});
                calculVec.push_back({nextY, nextX});
                totalNum += fielddMap[nextY][nextX];
                visitMap[nextY][nextX] = 1;
            }
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> l >> r;
    calculVec.reserve(n);
    int inputVal = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> inputVal;
            fielddMap[i][j] = inputVal;
        }
    }

    int dayCnt = 0;
    while (true) {
        bool flag = false;
        memset(&visitMap, 0, sizeof(visitMap));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visitMap[i][j]) {
                    continue;
                }
                calculVec.clear();
                bfs(i, j);
                if (calculVec.size() == 1) {
                    totalNum = 0;
                    continue;
                }

                int y = 0, x = 0;
                for (int i = 0; i < calculVec.size(); i++) {
                    tie(y, x) = calculVec[i];
                    fielddMap[y][x] = totalNum / calculVec.size();
                    flag = true;
                }
                totalNum = 0;
            }
        }
        if (!flag) {
            cout << dayCnt << "\n";
            break;
        }
        dayCnt++;
    }
    return 0;
}