#include <iostream>
#include <cmath>;
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;

    int low = min(a, b);
    int high = max(a, b);
    
    
    while(low + low % 2 != high)
    {
        answer++;
        low = low % 2 + low / 2;
        high = high % 2 + high / 2;
    }
    
    return answer;
}