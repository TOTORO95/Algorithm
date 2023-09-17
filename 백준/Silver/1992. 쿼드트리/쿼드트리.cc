#include <bits/stdc++.h>

using namespace std;

int n = 0; // 1 <= n <= 64
string fixel;
array<array<char, 64>, 64> fieldMap;

string quad(int cY, int cX, int size) {
    char curCh = fieldMap[cY][cX];
    if (size == 1) {
        return string(1, curCh);
    }

    string quadStr = "";
    int divSize = size * 0.5;
    for (int nY = cY; nY < cY + size; nY++) {
        for (int nX = cX; nX < cX + size; nX++) {
            if (curCh != fieldMap[nY][nX]) {
                quadStr += '(';
                quadStr += quad(cY, cX, divSize);
                quadStr += quad(cY, cX + divSize, divSize);
                quadStr += quad(cY + divSize, cX, divSize);
                quadStr += quad(cY + divSize, cX + divSize, divSize);
                quadStr += ')';
                return quadStr;
            }
        }
    }
    return string(1, curCh);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> fixel;
        for (int j = 0; j < fixel.length(); j++) {
            fieldMap[i][j] = fixel[j];
        }
    }

    cout << quad(0, 0, n) << "\n";

    return 0;
}