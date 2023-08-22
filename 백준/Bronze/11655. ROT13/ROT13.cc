#include <bits/stdc++.h>

using namespace std;

#define OFFSET_VAL 13
int main() {
    string word = "";
    getline(cin, word);

    for (int i = 0; i < word.size(); i++) {
        if (word[i] >= 'A' && word[i] <= 'Z') {
            if (word[i] + OFFSET_VAL > 'Z') {
                word[i] -= 26;
            }
            word[i] += OFFSET_VAL;
        } else if (word[i] >= 'a' && word[i] <= 'z') {
            if (word[i] + OFFSET_VAL > 'z') {
                word[i] -= 26;
            }
            word[i] += OFFSET_VAL;
        }
    }

    cout << word << endl;
}