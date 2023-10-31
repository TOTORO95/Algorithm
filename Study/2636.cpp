#include <bits/stdc++.h>

using namespace std;

const int maxSize = 102;
int n = 0, m = 0;
array<array<int, maxSize>, maxSize> fieldMap, visitMap;
int dirY[4] = {0, 1, 0, -1};
int dirX[4] = {1, 0, -1, 0};

int checkField() {
    int remainCheese = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (fieldMap[i][j] == 1) {
                remainCheese++;
            }
        }
    }
    return remainCheese;
}

void dfs(int col, int row) {
    visitMap[col][row] = 1;
    if (fieldMap[col][row] == 1) {
        fieldMap[col][row] = 0;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int ny = col + dirY[i];
        int nx = row + dirX[i];

        if (ny >= 0 && ny < n && nx >= 0 && nx < m && visitMap[ny][nx] == 0) {
            dfs(ny, nx);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    int remainCheese = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> fieldMap[i][j];
            if (fieldMap[i][j] == 1) {
                remainCheese++;
            }
        }
    }

    int cntHour = 0;
    int prevCnt = 0;
    while (remainCheese > 0) {
        fill(&visitMap[0][0], &visitMap[0][0] + maxSize * maxSize, 0);
        dfs(0, 0);
        prevCnt = remainCheese;
        remainCheese = checkField();
        cntHour++;
    }

    cout << cntHour << "\n"
         << prevCnt;

    return 0;
}