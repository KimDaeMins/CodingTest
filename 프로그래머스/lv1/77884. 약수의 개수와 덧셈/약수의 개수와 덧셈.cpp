#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    
    for(int i = left; i <= right; ++i)
    {
        int count = 0;
        for(int j = 1; j <= i; ++j)
        {
            if(!(i % j))
                ++count;
        }
        answer += count & 1 ? -i : i;
            
    }
    return answer;
}