#include <bits/stdc++.h>

int n = 0;  // 1<= n <= 3
int inputVal = 0;
vector<int> scvVec, visitVec;

int damage[6][3] = {
    {1, 9, 3},
    {1, 3, 9},
    {3, 1, 9},
    {3, 9, 1},
    {9, 1, 3},
    {9, 3, 1},
};

void BFS(int startIdx) {
    queue<int> q;
    q.push(scvVec[startIdx]);
    visitVec[startIdx] = 1;
    // int damage = 9;
    while (q.size()) {
        int curHp = q.front();
        q.pop();

        for (int i = 0; i < 6; i++) {
            damage[i];
        }
        for (int i = 0; i < scvVec.size(); i++) {
            if (i == startIdx) {
                continue;
            }
            visitVec[startIdx] = 1;
            q.push(i);
            visitVec[startIdx] = 0;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> inputVal;
        scvVec.push_back(inputVal);
    }

    return 0;
}

/*


*/