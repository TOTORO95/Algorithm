#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    int ax = r1, bx = r2;
    for(int i=0; i<r2; i++) {
        while(pow(bx,2) + pow(i,2) > pow(r2,2) && bx>0) {
            --bx;
        }
        while(pow(ax,2) + pow(i,2) >= pow(r1,2) && ax>0) {
            --ax;
        }
        answer += bx-ax;
    }
    
    return answer = answer*4;
}
