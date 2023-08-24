#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, temp, psum[100001], ret = numeric_limits<int>::min();
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> temp;
        psum[i] = psum[i - 1] + temp;
    }
    
    for (int i = k; i <= n; i++) {
        ret = max(ret, psum[i] - psum[i - k]);
    }
    cout << ret << endl;

    return 0;
}
