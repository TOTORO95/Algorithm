#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);

    string str;

    cin >> str;
    int a = 0;
    for (int i = 0; i < 10; i++) {
        a = atoi(str.c_str()) + i;
        cout << a << "\n";
    }
}