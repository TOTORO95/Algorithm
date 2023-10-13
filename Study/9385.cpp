#include <bits/stdc++.h>

using namespace std;

int main() {
    int categoryNum = 0, costumeNum = 0;
    vector<vector<string>> fationVec(categoryNum, vector<string>());
    string cloth;

    cin >> categoryNum;

    for (int i = 0; i < categoryNum; i++) {
        cin >> costumeNum;
        for (int j = 0; j >> costumeNum; j++) {
            cin >> cloth;
            fationVec[i].push_back(cloth);
        }
    }
    return 0;
}