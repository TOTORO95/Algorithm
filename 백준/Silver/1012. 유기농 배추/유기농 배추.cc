#include <bits/stdc++.h>

using namespace std;

array<array<int, 50>, 50> fieldMap;
vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void DFS(pair<int, int> pos) {
    fieldMap[pos.first][pos.second] = 0;

    for (int i = 0; i < 4; i++) {
        pair<int, int> nextPos = {pos.first + dirs[i].first,
                                  pos.second + dirs[i].second};
        if (nextPos.first < 0 || nextPos.first >= 50 || nextPos.second < 0 ||
            nextPos.second >= 50 ||
            fieldMap[nextPos.first][nextPos.second] == 0) {
            continue;
        }
        DFS(nextPos);
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    int testCase, n, m, cabbageNum, x, y;
    cin >> testCase;

    for (int i = 0; i < testCase; i++) {
        cin >> n >> m >> cabbageNum;
        memset(&fieldMap, 0, sizeof(fieldMap));
        int answer = 0;
        for (int j = 0; j < cabbageNum; j++) {
            cin >> x >> y;
            fieldMap[y][x] = 1;
        }
        for (int y = 0; y < 50; y++) {
            for (int x = 0; x < 50; x++) {
                if (fieldMap[y][x] == 1) {
                    DFS({y, x});
                    answer++;
                }
            }
        }
        cout << answer << "\n";
    }

    return 0;
}