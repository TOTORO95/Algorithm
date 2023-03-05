#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    int mid = total/num;
    int m = num/2;
    int idx = 0;
    
    if(num&1) 
    {
        idx=mid-m;
    }
    else 
    {
        idx=mid-m+1;
    }
    
    for(int i=idx; i<=mid+m; i++)
    {
        answer.push_back(i);        
    }
    
    return answer;
}