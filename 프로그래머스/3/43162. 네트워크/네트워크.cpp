#include <string>
#include <vector>
#include <iostream>
using namespace std;

void DFS(int visitNode, vector<int>& visitVec, const vector<vector<int>>& computers)
{
    for(int idx = 0; idx<computers[visitNode].size(); ++idx)
    {     
        if(visitVec[idx] == 0 && computers[visitNode][idx])
        {        
            visitVec[idx] = 1;
            DFS(idx, visitVec, computers);
        }
    }   
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<int> VisitVec(computers.size(), 0);
    
    for(int visitNode = 0; visitNode < computers.size() ; visitNode++)
    {
        if(VisitVec[visitNode] == 0)
        {
            DFS(visitNode, VisitVec, computers);    
            answer++;
        }
    }
    
    return answer;
}