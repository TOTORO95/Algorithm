#include <bits/stdc++.h>

using namespace std;

int main() {
    string word;
    cin >> word;

    int chSize = int('z' - 'a');
    vector<int> charVec(chSize + 1, 0);

    for (int i = 0; i < word.size(); i++) {
        charVec[word[i] - 'a']++;
    }

    for (auto ch : charVec) {
        cout << ch << " ";
    }
}