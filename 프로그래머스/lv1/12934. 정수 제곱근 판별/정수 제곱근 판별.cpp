#include <string>
#include <vector>
#include <cmath>
#include <math.h>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    double a = std::sqrt(n);
    if(a != (int)a)
    {
        answer = -1;
    }
    else
    {
        answer = powl(a + 1 , 2);
    }
    
    
    return answer;
}