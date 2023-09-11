#include <bits/stdc++.h>

using namespace std;

int n; // 2 < n < 100
const int maxSize = 101;
int answer = 1, maxVal = 0;
array<array<int, maxSize>, maxSize> heightMat;
array<array<int, maxSize>, maxSize> tempMat;
array<int, 4> dirY = {0, 1, 0, -1};
array<int, 4> dirX = {1, 0, -1, 0};

void DFS(int cy, int cx, int hegiht) {
    tempMat[cy][cx] = 0;
    for (int i = 0; i < 4; i++) {
        int ny = cy + dirY[i];
        int nx = cx + dirX[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n) {
            continue;
        }
        if (tempMat[ny][nx] > hegiht) {
            DFS(ny, nx, hegiht);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> heightMat[i][j];
        }
    }

    for (int height = 1; height < maxSize; height++) {
        copy(heightMat.begin(), heightMat.end(), tempMat.begin());
        maxVal = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (tempMat[i][j] > height) {
                    DFS(i, j, height);
                    maxVal++;
                }
            }
        }
        answer = max(answer, maxVal);
    }
    cout << answer;
}