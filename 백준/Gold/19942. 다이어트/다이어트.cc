#include <bits/stdc++.h>

using namespace std;

int n = 0;  // 3 <= n <= 15
const int INF = 99999999;
int minP = 0, minF = 0, minS = 0, minV = 0, minCost = INF;

typedef struct nutrient {
    // 0 <= val <= 500
    int mp;
    int mf;
    int ms;
    int mv;
    int cost;
} nutrient;
array<nutrient, 18> nutrientArr;
map<int, vector<vector<int>>> answerMap;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> minP >> minF >> minS >> minV;

    for (int i = 0; i < n; i++) {
        cin >> nutrientArr[i].mp >> nutrientArr[i].mf >> nutrientArr[i].ms >> nutrientArr[i].mv >> nutrientArr[i].cost;
    }
    int totP, totF, totS, totV, totCost;
    for (int i = 0; i < (1 << n); i++) {
        totP = totF = totS = totV = totCost = 0;
        vector<int> combiVec;

        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                combiVec.push_back(j + 1);
                totP += nutrientArr[j].mp;
                totF += nutrientArr[j].mf;
                totS += nutrientArr[j].ms;
                totV += nutrientArr[j].mv;
                totCost += nutrientArr[j].cost;
            }
        }

        if (totP >= minP && totF >= minF && totS >= minS && totV >= minV) {
            if (totCost <= minCost) {
                minCost = totCost;
                answerMap[totCost].push_back(combiVec);
            }
        }
    }

    if (minCost == INF) {
        cout << -1 << "\n";
    } else {
        cout << minCost << "\n";
        sort(answerMap[minCost].begin(), answerMap[minCost].end());

        for (auto idx : answerMap[minCost][0]) {
            cout << idx << " ";
        }
    }

    return 0;
}