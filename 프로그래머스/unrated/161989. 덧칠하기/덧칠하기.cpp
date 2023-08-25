#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 1;
    //빈공간의 섹션이 있잖아.
    //빈공간~ + 4까지는 칠해진다고
    
    int nowRoller = section[0];
    for(int i = 1; i < section.size(); i++)
    {
        if(section[i] >= nowRoller + m)
        {
            nowRoller = section[i];
            ++answer;
        }
    }
    
    return answer;
}