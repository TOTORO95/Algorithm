#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int, int> obMap;
    map<int, int> ybMap;
    for (int& i : topping) {
        ybMap[i]++;
    }
    
    for(auto num : topping) {
        ybMap[num]--;
        obMap[num]++;
        
        if(ybMap[num] == 0) {
            ybMap.erase(num);
        }
        if(obMap.size() == ybMap.size()) {
            answer++;
        }
    }    
    
    return answer;
}