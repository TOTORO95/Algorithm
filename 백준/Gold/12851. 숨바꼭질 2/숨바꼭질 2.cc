#include <bits/stdc++.h>

using namespace std;

const int maxSize = 100004;
int n = 1, k = 4;  // 0 <= n, k <= 100000
array<pair<int, int>, maxSize> visitArr;

void BFS() {
    pair<int, int> curNode = {n, 1};
    queue<pair<int, int>> q;
    q.push(curNode);
    visitArr[curNode.first] = {1, 1};

    while (q.size()) {
        curNode = q.front();
        q.pop();

        for (int nextPos : {curNode.first - 1, curNode.first + 1, curNode.first * 2}) {
            if (nextPos >= 0 && nextPos < maxSize) {  // 범위 체크
                if (visitArr[k].first != 0) {
                    if (curNode.second > visitArr[k].first) {
                        break;
                    }
                }

                if (visitArr[nextPos].first) {  // 방문 O
                    if (visitArr[nextPos].first == curNode.second + 1) {
                        visitArr[nextPos].second += visitArr[curNode.first].second;
                    }
                } else {                                           // 방문 X
                    visitArr[nextPos].first = curNode.second + 1;  // Depth
                    visitArr[nextPos].second += visitArr[curNode.first].second;
                    q.push({nextPos, curNode.second + 1});
                }
            }
        }
    }
    cout << visitArr[k].first - 1 << "\n";
    cout << visitArr[k].second << "\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    visitArr.fill({0, 0});
    cin >> n >> k;
    if (n == k) {
        cout << "0\n";
        cout << "1\n";
        return 0;
    }
    BFS();
    return 0;
}