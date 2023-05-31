#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
typedef  pair<int,vector<int>> fatigueInfo;
int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    map<string,int> mineralMap = {
        {"diamond"  , 25},
        {"iron"     , 5},
        {"stone"    , 1}
    };
    map<int,int> damageMap = {
        {0, 25},
        {1, 5},
        {2, 1}
    };
    int shovel = 0;
    for(auto pick : picks) {
        shovel+= pick;
    }
    
    vector<fatigueInfo> infoVec;
    fatigueInfo info = {0,vector<int>()};
    
    for(int i=1; i<minerals.size()+1; i++) {
        info.first += mineralMap[minerals.at(i-1)];
        info.second.push_back(mineralMap[minerals.at(i-1)]);

        if(i == minerals.size()) {
            infoVec.push_back(info);
            break;
        }
        
        if(i%5==0 && i!=0) {
            infoVec.push_back(info);            
            info.first = 0;
            info.second.clear();
        }
        if(infoVec.size() == shovel) {
            break;
        }
    };
    
    sort(infoVec.begin(), infoVec.end(), [](pair<int,vector<int>>prev, pair<int,vector<int>>next){
        return prev.first  > next.first;
    });

    int mineIdx = 0;
   
    for(int idx=0; idx<picks.size(); idx++) {
        
        int pick = picks.at(idx);
        while(pick>0) {
            if(mineIdx < infoVec.size()) {
                for(auto fatigue : infoVec[mineIdx].second) {
                    answer += ceil((float)fatigue/(float)damageMap[idx]);
                }                
            }
            pick--;
            mineIdx++;         
        }
        
    
    }
        
        
        
        
    
    return answer;
}