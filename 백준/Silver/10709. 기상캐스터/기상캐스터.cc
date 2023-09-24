#include <bits/stdc++.h>

using namespace std;

int h, w; // 1 <= h,w <= 100
array<array<int, 100>, 100> fieldArr;
void DFS(int y, int x, int depth) {
    fieldArr[y][x] = depth;

    cout << fieldArr[y][x] << " ";
    int nextX = x + 1;

    if (nextX >= w) {
        return;
    }

    if (fieldArr[y][nextX] == 0) {
        DFS(y, nextX, 0);
    } else if (fieldArr[y][nextX] == -1 && depth >= 0) {
        DFS(y, nextX, depth + 1);
    } else {
        DFS(y, nextX, -1);
    }
    return;
}

int main() {
    cin >> h >> w;
    char temp;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> temp;
            if (temp == '.') {
                fieldArr[i][j] = -1;
            } else {
                fieldArr[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < h; i++) {
        DFS(i, 0, fieldArr[i][0]);
        cout << "\n";
    }

    return 0;
}