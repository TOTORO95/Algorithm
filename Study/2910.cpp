#include <bits/stdc++.h>

using namespace std;

int n = 0; // 1<= n <= 1000
int c = 0; // 1<- c <= 1000000000
typedef pair<int, pair<int, int>> pp;
unordered_map<int, pair<int, int>> sequenceMap;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> c;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        auto ret = sequenceMap.insert({temp, {i, 1}});
        if (ret.second) {
            continue;
        } else {
            ret.first->second.second++;
        }
    }

    vector<pp> sequenceVec(sequenceMap.begin(), sequenceMap.end());
    sort(sequenceVec.begin(), sequenceVec.end(),
         [](pair<int, pair<int, int>> l, pair<int, pair<int, int>> r) {
             if (l.second.second == r.second.second) {
                 return l.second.first < r.second.first;
             }
             return l.second.second > r.second.second;
         });

    for (auto sequenceNo : sequenceVec) {
        for (int i = 0; i < sequenceNo.second.second; i++) {
            cout << sequenceNo.first << " ";
        }
    }
    return 0;
}
