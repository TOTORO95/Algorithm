#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int answer = 0;
    
    int n = common[common.size()-1];
    int n1 = common[common.size()-2];
    int n2 = common[common.size()-3];

    int value = n-n1;
    int value2 = n1-n2;
    
    if( value == value2 )
    {
        answer = common.back() + value;
    }
    else
    {
        answer = common.back() * (value/value2);
    }
    
    return answer;
}