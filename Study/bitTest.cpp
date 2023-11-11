#include <bits/stdc++.h>

using namespace std;

int main() {
    int s = 19;
    int idx = 0;
    cin >> idx;
    s |= (1 << idx);

    cout << s << "\n";

    return 0;
}