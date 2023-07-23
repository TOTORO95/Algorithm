#include <iostream>
#include <string>
#include <vector>

using namespace std;


void hanoi(vector<vector<int>>& answer, int n, int start,int sub, int dest) {
    if(n<=1) {
        answer.push_back({start,dest});
        return;
    }
    
    hanoi(answer, n-1, start, dest, sub);
    answer.push_back({start,dest});
    hanoi(answer, n-1, sub, start, dest );    
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(answer, n, 1, 2, 3);
    return answer;
}