#include <bits/stdc++.h>

using namespace std;

int main() {
    int categoryNum = 0, costumeNum = 0;
    string name, category;

    cin >> categoryNum;
    for (int i = 0; i < categoryNum; i++) {
        map<string, int> fationMap;
        int answer = 1;
        cin >> costumeNum;
        for (int j = 0; j < costumeNum; j++) {
            cin >> name >> category;
            auto ret = fationMap.insert({category, 1});
            if (!ret.second) {
                fationMap[category]++;
            }
        }

        for (auto cloth : fationMap) {
            answer = (cloth.second + 1) * answer;
        }

        answer--;
        cout << answer << "\n";
    }
    return 0;
}