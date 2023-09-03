#include <bits/stdc++.h>

using namespace std;

int main() {

    int material = 0, cost = 0, answer = 0;
    cin.tie(NULL);

    cin >> material >> cost;

    vector<int> materialVec(material, 0);
    for (int i = 0; i < material; i++) {
        cin >> materialVec[i];
    }

    for (int i = 0; i < materialVec.size(); i++) {
        for (int j = i + 1; j < materialVec.size(); j++) {
            if (materialVec[i] + materialVec[j] == cost) {
                answer++;
            }
        }
    }
    cout << answer << "\n";
}