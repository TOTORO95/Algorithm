#include <bits/stdc++.h>

using namespace std;
int n = 0, k = 0;  // 0 <= n,m <= 100,000
const int maxSize = 200004;
array<int, maxSize> visitArr, trace;

void BFS() {
    queue<pair<int, int>> q;
    q.push({n, 1});
    visitArr[n] = 1;

    int curPos = 0, curDepth = 0;
    while (q.size()) {
        tie(curPos, curDepth) = q.front();
        q.pop();
        if (curPos == k) {
            break;
        }

        for (int nextPos : {curPos * 2, curPos - 1, curPos + 1}) {
            if (nextPos >= 0 && nextPos < maxSize) {
                if (visitArr[nextPos]) {
                    continue;
                }
                visitArr[nextPos] = curDepth + 1;
                trace[nextPos] = curPos;
                q.push({nextPos, curDepth + 1});
            }
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    BFS();
    vector<int> answer;
    for (int i = k; i != n; i = trace[i]) {
        answer.push_back(i);
    }
    answer.push_back(n);
    cout << visitArr[k] - 1 << "\n";
    
    for (auto itr = answer.rbegin(); itr != answer.rend(); itr++) {
        cout << *itr << " ";
    }

    return 0;
}