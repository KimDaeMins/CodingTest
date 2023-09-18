#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int storey) {
    int answer = 0;
    
    while(storey)
    {
        int count = storey % 10;
        int next = storey / 10 % 10 ;
        if(count > 5 || (count == 5 && next >= 5))
        {
            answer += 10  - count;
            storey += 10;
        }
        else
            answer += count;
        
        storey /= 10;
    }
    return answer;
}