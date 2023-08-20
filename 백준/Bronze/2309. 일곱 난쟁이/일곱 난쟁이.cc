#include <bits/stdc++.h>

using namespace std;

void findDwarf(const vector<int> &dwarf, int depth, vector<int> heightVec,
               vector<int> &answer) {
    if (heightVec.size() == 7) {
        if (accumulate(heightVec.begin(), heightVec.end(), 0) == 100) {
            answer.assign(heightVec.begin(), heightVec.end());
        }
        return;
    }

    for (int i = depth + 1; i < dwarf.size(); i++) {
        heightVec.push_back(dwarf[i]);
        findDwarf(dwarf, i, heightVec, answer);
        heightVec.pop_back();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> dwarf(9);
    vector<int> answer(7);

    for (int i = 0; i < 9; i++) {
        cin >> dwarf[i];
    }

    sort(dwarf.begin(), dwarf.end());
    findDwarf(dwarf, -1, {}, answer);

    for (auto height : answer) {
        cout << height << endl;
    }
}
