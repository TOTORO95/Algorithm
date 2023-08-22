#include <bits/stdc++.h>
using namespace std;

int a, b, c, startTime, endTime;
vector<int> parkVec(100, 0);
int sum;
int main() {
    cin >> a >> b >> c;
    for (int i = 0; i < 3; i++) {
        cin >> startTime >> endTime;
        for (int j = startTime; j < endTime; j++) {
            parkVec[j]++;
        }
    }

    for (auto val : parkVec) {
        if (val == 1) {
            sum += val * a;
        } else if (val == 2) {
            sum += val * b;
        } else if (val == 3) {
            sum += val * c;
        }
    }

    cout << sum << '\n';
    return 0;
}