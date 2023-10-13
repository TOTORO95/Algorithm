#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int pokemonNum, problemNum;
    string name;
    map<string, int> nameMap;
    vector<string> nameVec(100004, "");

    cin >> pokemonNum >> problemNum;
    for (int i = 0; i < pokemonNum; i++) {
        cin >> name;
        // nameMap[name] = i+1; <- 기본생성자로 데이터 초기화 후 이후 값 삽입
        nameMap.insert({name, i + 1});
        nameVec[i + 1] = name;
    }

    for (int i = 0; i < problemNum; i++) {
        cin >> name;
        int nameNo = atoi(name.c_str());
        if (nameNo == 0) {
            cout << nameMap[name] << "\n";
        } else {
            cout << nameVec[nameNo] << "\n";
        }
    }

    return 0;
}
