#include <bits/stdc++.h>

using namespace std;

const int maxSize = 52;
int n = 0, m = 0;  // 2 <= n >= 50 , 1 <= m <= 13
int val = -1, minVal = 9999999;
vector<pair<int, int>> chickenVec, homeVec;
vector<vector<int>> chickenComVec;

void combiFunc(int idx, vector<int> comVec) {
    if (comVec.size() == m) {
        chickenComVec.push_back(comVec);
        return;
    }

    for (int i = idx + 1; i < chickenVec.size(); i++) {
        comVec.push_back(i);
        combiFunc(i, comVec);
        comVec.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    chickenVec.reserve(maxSize);
    homeVec.reserve(maxSize);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> val;

            if (val == 1) {
                homeVec.push_back({i, j});
            } else if (val == 2) {
                chickenVec.push_back({i, j});
            }
        }
    }
    combiFunc(-1, vector<int>());
    for (int i = 0; i < chickenComVec.size(); i++) {
        int ret = 0;
        for (int j = 0; j < homeVec.size(); j++) {
            int minDist = 9999999;
            for (int k = 0; k < chickenComVec[i].size(); k++) {
                int dist = abs(homeVec[j].first - chickenVec[chickenComVec[i][k]].first) + abs(homeVec[j].second - chickenVec[chickenComVec[i][k]].second);
                minDist = min(minDist, dist);
            }
            ret += minDist;
        }
        minVal = min(ret, minVal);
    }
    cout << minVal << "\n";

    return 0;
}