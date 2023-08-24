#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = -1;
    long n = num;
    for(int i = 0 ;  i < 500; ++i)
    {
        if(n == 1)
        {
            answer = i;
            break;
        }
        
        if(n % 2)
        {
            n = n * 3 + 1;
        }
        else
        {
            n /= 2;
        }
    }
    
    return answer;
}