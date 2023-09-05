#include <string>
#include <vector>

using namespace std;

//조합을 이용하면 될것같은데..
//조합을 이용하기가 애매한게 + or -거든
//그래서 전부 +인경우랑 하나씩 - 해가는 경우를 나타내야하는데
//그럼 하나를 -할때마다 1번씩 순회를 해야한다는거임
//그래서 도서관에서 하는 방식으로다가 한번 해볼까 싶음 근데이게 참 애매하네
//도서관방식은 중복이 가능해서 좋지못함 이게나은듯
int Combi(int start, int k, vector<int>& numbers,int count, int checkNum)
{
    if(count == k)
    {
        if(checkNum == 0)
            return 1;
        return 0;
    }
    
    int num = 0;
    for(int i = start + 1; i < numbers.size(); ++i)
    {
        num += Combi(i, k, numbers, count + 1, checkNum - numbers[i] * 2);
    }
    return num;
}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    int checkNum = -target;
    for(int a : numbers)
    {
        checkNum += a;
    }
    for(int i = 0; i < numbers.size(); ++i)
    {
        answer += Combi(-1, i + 1, numbers, 0, checkNum);
    }
    return answer;
}