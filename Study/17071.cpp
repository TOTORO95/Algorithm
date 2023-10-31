#include <bits/stdc++.h>

using namespace std;

const int maxSize = 500000;
int n = 0, k = 0;  // 0 <= n,k <= 500,000
array<array<int, maxSize>, 2> visitArr;

void BFS() {
    int targetPos = k, time = 1;
    bool flag = false;
    queue<int> q;
    visitArr[0][n] = 1;
    q.push(n);

    while (q.size()) {
        targetPos += time;
        if (targetPos > maxSize) {
            break;
        }
        if (visitArr[time & 1][targetPos]) {  // 수빈이가 방문 한적이있다면 왓다갔다로 가능
            flag = true;
            break;
        }

        int qSize = q.size();
        for (int i = 0; i < qSize; i++) {
            int curX = q.front();
            q.pop();
            for (int nextX : {curX + 1, curX - 1, curX * 2}) {
                if (nextX < 0 || nextX > maxSize) {
                    continue;
                }
                if (visitArr[time & 1][nextX]) {
                    continue;
                }
                visitArr[time & 1][nextX] = visitArr[!(time & 1)][nextX] + 1;

                if (nextX == targetPos) {
                    flag = true;
                    break;
                }
                q.push(nextX);
            }
            if (flag) {
                break;
            }
        }
        if (flag) {
            break;
        }
        time++;
    }
    if (flag) {
        cout << time << "\n";
    } else {
        cout << "-1\n";
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    if (n == k) {
        cout << 0 << "\n";
        return 0;
    }
    BFS();

    return 0;
}