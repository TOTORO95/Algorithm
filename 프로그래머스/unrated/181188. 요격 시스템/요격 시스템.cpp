#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> missile;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(), targets.end());
    vector<missile> interceptVec;  
    for( auto target : targets ) {
        bool isCollsion = false; 
        for( auto& intercept : interceptVec ) {            
            if( intercept.first <= target.at(0) && intercept.second > target.at(0) ) {
                intercept.first = target.at(0);
                isCollsion = true;
            }

            if( intercept.first < target.at(1) && intercept.second >= target.at(1) ) {
                intercept.second = target.at(1);
                isCollsion = true;
            }

            if( isCollsion ) {
                break; 
            }            
        }

        if( !isCollsion ) {
            interceptVec.push_back({target.at(0),target.at(1)});
        }
    }
    answer = interceptVec.size();    
    return answer;
}