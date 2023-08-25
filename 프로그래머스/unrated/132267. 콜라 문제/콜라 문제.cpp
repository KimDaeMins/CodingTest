#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    
    while(n >= a)
    {
        int reward = n / a * b;
        n = reward + n % a;
        answer += reward;
    }
    return answer;
}