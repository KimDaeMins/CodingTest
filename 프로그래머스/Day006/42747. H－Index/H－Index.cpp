#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end());
    
    int citSize = citations.size();
    for(int i = 0; i < citSize; ++i)
    {
        int H_Index = citSize - i;
        if(citations[i] >= H_Index) return H_Index;
        //나머지 논문이 h번 이하 인용되었다는건 특정인덱스의 크기만 대충 판단해도 알 수 있는 부분이구나
    }
    
    return answer;
}