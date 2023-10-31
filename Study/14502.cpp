#include <bits/stdc++.h>
using namespace std;

const int maxSize = 8; // 3<= N,M <= 8
array<array<int, maxSize>, maxSize> filedMap, visitMap;
vector<pair<int, int>> virusList, wallList;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
int n = 0, m = 0, answer = 0;

void virusDFS(int cy, int cx) {
    for (int i = 0; i < 4; i++) {
        int ny = cy + dy[i];
        int nx = cx + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m || visitMap[ny][nx] == 1 ||
            filedMap[ny][nx] == 1) {
            continue;
        }
        visitMap[ny][nx] = 1;
        virusDFS(ny, nx);
    }

    return;
}

int checkSafeZone() {
    fill(&visitMap[0][0], &visitMap[0][0] + maxSize * maxSize, 0);

    for (auto virus : virusList) {
        virusDFS(virus.first, virus.second);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visitMap[i][j] == 0 && filedMap[i][j] == 0) {
                cnt++;
            }
        }
    }

    return cnt;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> filedMap[i][j];
            if (filedMap[i][j] == 0) {
                wallList.push_back({i, j});
            }
            if (filedMap[i][j] == 2) {
                virusList.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < wallList.size(); i++) {
        for (int j = i + 1; j < wallList.size(); j++) {
            for (int k = j + 1; k < wallList.size(); k++) {
                filedMap[wallList[i].first][wallList[i].second] = 1;
                filedMap[wallList[j].first][wallList[j].second] = 1;
                filedMap[wallList[k].first][wallList[k].second] = 1;

                answer = max(answer, checkSafeZone());

                filedMap[wallList[i].first][wallList[i].second] = 0;
                filedMap[wallList[j].first][wallList[j].second] = 0;
                filedMap[wallList[k].first][wallList[k].second] = 0;
            }
        }
    }

    cout << answer << "\n";
    return 0;
}
