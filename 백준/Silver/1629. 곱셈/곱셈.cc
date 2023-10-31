#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll lPow(ll a, ll b, ll c) {
    if (b == 1) {
        return a % c;
    }

    ll val = lPow(a, b / 2, c);
    val = (val * val) % c;
    if (b & 1) {
        val = (val * a) % c;
    }
    return val;
}

int main() {
    long long a = 0, b = 0, c = 0, answer = 0;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c;
    cout << lPow(a, b, c) << "\n";

    return 0;
}