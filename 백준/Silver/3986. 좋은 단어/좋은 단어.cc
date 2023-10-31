#include <bits/stdc++.h>

using namespace std;

/*
    단어의 수 1<= N <=100
    A,B로 이루어진 단어  길이 2 <= word <= 100000
    모든 단어길이의 합 1000000 이하
*/
int main() {

    int n = 0, answer = 0;
    string word;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> word;
        stack<char> wordStack;
        for (char ch : word) {
            if (wordStack.size() && ch == wordStack.top()) {
                wordStack.pop();
            } else {
                wordStack.push(ch);
            }
        }
        if (wordStack.size() == 0) {
            answer++;
        }
    }
    cout << answer << "\n";
    return 0;
}