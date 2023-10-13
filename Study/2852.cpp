#include <bits/stdc++.h>

using namespace std;

struct tm tm, endTm;

vector<pair<int, time_t>> timeVec;

int n = 0; // 1 <= n <- 100
string strTime;
int teamNo;
string print(int a) {
    string d = "00" + to_string(a / 60);
    string e = "00" + to_string(a % 60);
    return d.substr(d.size() - 2, 2) + ":" + e.substr(e.size() - 2, 2);
}
int changeToInt(string a) {
    return atoi(a.substr(0, 2).c_str()) * 60 + atoi(a.substr(3, 2).c_str());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    endTm.tm_min = 48;
    time_t endTime = mktime(&endTm);
    for (int i = 0; i < n; i++) {
        cin >> teamNo >> strTime;
        strptime(strTime.c_str(), "%M: %S", &tm);
        timeVec.push_back({teamNo, mktime(&tm)});
    }

    cout << endTime - timeVec[0].second << "\n";

    return 0;
}