#include <string>
#include <vector>
#include <cmath>
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
        ++a;
        answer = a * a;
    }
    
    
    return answer;
}