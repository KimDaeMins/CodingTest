#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int a = 0;
    int b = x;
    while(b)
    {
        a += b % 10;
        b /= 10;
    }
    
    if(x % a)
        answer = false;
    return answer;
}