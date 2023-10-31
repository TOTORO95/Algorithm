#include <bits/stdc++.h>

using namespace std;

const int maxSize = 24;
int r = 0, c = 0;  // 1 <= r,c <= 20;

array<array<char, maxSize>, maxSize> fieldMat;
array<char, 'Z' - 'A'> visitArr;
array<int, 4> dirY = {-1, 0, 1, 0};
array<int, 4> dirX = {0, 1, 0, -1};
int maxCnt = 0;
void DFS(pair<int, int> curPos, int depth) {
    maxCnt = max(maxCnt, depth);

    for (int i = 0; i < 4; i++) {
        pair<int, int> nextPos = {curPos.first + dirY[i], curPos.second + dirX[i]};
        if (nextPos.first < 0 || nextPos.first >= r || nextPos.second < 0 || nextPos.second >= c) {
            continue;
        }
        if (visitArr[fieldMat[nextPos.first][nextPos.second] - 'A']) {
            continue;
        }

        visitArr[fieldMat[nextPos.first][nextPos.second] - 'A'] = 1;
        DFS(nextPos, depth + 1);
        visitArr[fieldMat[nextPos.first][nextPos.second] - 'A'] = 0;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;
    char inputCh = ' ';
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> inputCh;
            fieldMat[i][j] = inputCh;
        }
    }

    set<char> chSet;
    visitArr[fieldMat[0][0] - 'A'] = 1;
    DFS({0, 0}, 1);
    cout << maxCnt << "\n";

    return 0;
}