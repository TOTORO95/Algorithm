#include <iostream>
#include <queue>
#include <string>

using namespace std;

int row, col;
int answer = 999999;
char arr[1001][1001] = {};
int visitMap[1001][1001] = {
    0,
};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue<pair<int, int>> q;
queue<pair<int, int>> fire_q;

void bfs(int start_y, int start_x) {
    q.push(make_pair(start_y, start_x));
    visitMap[start_y][start_x] = 1;

    while (!q.empty()) {
        // 불이 움직여야함. 불은 비워지든 안비워지든 상관이없다.
        int cur_fire_cnt = fire_q.size();
        for (int i = 0; i < cur_fire_cnt; i++) {
            int cur_x, cur_y;
            cur_y = fire_q.front().first;
            cur_x = fire_q.front().second;
            fire_q.pop();
            for (int j = 0; j < 4; j++) {
                int next_x, next_y;
                next_y = cur_y + dy[j];
                next_x = cur_x + dx[j];

                if (arr[next_y][next_x] == '.') {
                    fire_q.push(make_pair(next_y, next_x));
                    arr[next_y][next_x] = 'F';
                }
            }
        }
        // 사방으로 돌진.
        int cur_x, cur_y;
        cur_y = q.front().first;
        cur_x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int next_x, next_y;
            next_y = cur_y + dy[i];
            next_x = cur_x + dx[i];

            // 벽을 넘어 밖으로 나가면 출력.
            if (next_y >= col || next_x >= row || next_x < 0 || next_y < 0) {
                if (visitMap[cur_y][cur_x] < answer) {
                    answer = visitMap[cur_y][cur_x];
                }
            }

            if (arr[next_y][next_x] == '.' && visitMap[next_y][next_x] == 0) {
                q.push(make_pair(next_y, next_x));
                visitMap[next_y][next_x] = visitMap[next_y][next_x] + 1;
            }
        }
    }
}

int main() {
    int start_x, start_y;
    cin >> col >> row;
    for (int i = 0; i < col; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < row; j++) {
            arr[i][j] = str[j];
            if (str[j] == 'F') {
                fire_q.push(make_pair(i, j));
            } else if (str[j] == 'J') {
                start_y = i;
                start_x = j;
            }
        }
    }

    bfs(start_y, start_x);

    if (answer == 999999) {
        cout << "IMPOSSIBLE";
    } else
        cout << answer;

    return 0;
}