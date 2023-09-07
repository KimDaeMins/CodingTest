#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
//큐 네개를 준비한다
//하나는 왼쪽으로 하나는 오른쪽으로 돌린다.
//그게편하긴하지? ㅋㅋ

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    
    int qSize = queue1.size();
    long long qCount[2] = {};
    for(int i = 0; i < qSize; ++i)
    {
        qCount[0] += queue1[i];
        queue2.push_back(queue1[i]);
        qCount[1] += queue2[i];
        queue1.push_back(queue2[i]);
    }
    
    int Count = 0;
    int leftIndex = 0;
    int leftSize = qSize * 2;
    int rightIndex = 0;
    int rightSize = qSize * 2;
    
    while(leftIndex < leftSize && rightIndex < rightSize)
    {
        if(qCount[0] == qCount[1])
        {
            answer = Count;
            break;
        }
        
        Count++;
        if(qCount[0] > qCount[1])
        {
            int a = queue1[leftIndex++];
            qCount[0] -= a;
            qCount[1] += a;
        }
        else
        {
            int a = queue2[rightIndex++];
            qCount[1] -= a;
            qCount[0] += a;
        }
    }
    if(qCount[0] == qCount[1])
    {
        answer = Count;
    }
    return answer;
}