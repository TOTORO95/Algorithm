#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool checkWord(const vector<string>& phoneticWord, string str)
{
    int idx = 0;
    bool enable = true;
    while( enable && idx < str.length() )
    {
        for( auto word : phoneticWord )
        {
            auto checkWord = str.substr(idx, word.length());
            if( checkWord == word )
            {
                idx += word.length();
                enable = true;
                break;
            }
            else
            {
                enable = false;   
            }
        }        
    }
    return enable;
}
int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> phoneticWord = {"aya", "ye", "woo", "ma"};
    for( auto str : babbling )
    {
        if(checkWord(phoneticWord, str))
        {
            answer++;
        }
    }
    
    return answer;
}