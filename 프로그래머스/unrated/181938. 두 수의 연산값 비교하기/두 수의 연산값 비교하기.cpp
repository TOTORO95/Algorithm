#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    string first = to_string(a) + to_string(b);
    string second = to_string(2*a*b);
    
    int answer = max(stoi(first), stoi(second));
    return answer;
}