#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string word, start, end;

    cin >> n;
    cin >> word;

    start = word.substr(0, word.find('*', 0));
    end = word.substr(word.find('*') + 1);

    for (int i = 0; i < n; i++) {
        string fileName;
        cin >> fileName;
        if (fileName.length() < start.length() + end.length()) {
            cout << "NE" << endl;
        } else {
            if (fileName.substr(0, start.size()) == start &&
                fileName.substr(fileName.size() - end.size()) == end) {
                cout << "DA" << endl;
            } else {
                cout << "NE" << endl;
            }
        }
    }

    return 0;
}