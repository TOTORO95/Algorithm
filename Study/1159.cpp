#include <bits/stdc++.h>

using namespace std;

int main() {
    // 1 ≤ N ≤ 150
    int n = 0;
    cin >> n;
    string answer;

    vector<int> playerVec(26, 0);
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        playerVec[name[0] - 'a']++;
    }

    for (int i = 0; i < playerVec.size(); i++) {
        if (playerVec[i] >= 5) {
            answer.push_back(i + 'a');
        }
    }
    if (answer.empty()) {
        cout << "PREDAJA" << endl;
    } else {
        cout << answer << endl;
    }
    return 0;
}