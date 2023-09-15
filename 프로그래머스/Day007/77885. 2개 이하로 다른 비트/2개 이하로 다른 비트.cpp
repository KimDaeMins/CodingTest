#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;
// 7과 6의 차이점이 뭘까?
// 7 >> 1 = 3
// 6 >> 1 = 3
//
vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    unordered_map<int, long long> m;
     m[0] = 1;
    for (int i = 1; i < 1000000; ++i)
    {
         m[i] = m[i - 1] * 2;
     }
    for(int i = 0; i < numbers.size(); ++i)
    {
        long long num = numbers[i];
        long long count = 0;
        while(num)
        {
            if(num >> 1 == (num - 1) >> 1)//마지막숫자가 1인경우 카운트증가
            {
                ++count;
                num >>= 1;
            }
            else//0인경우
            {
                if(count == 0)
                    answer.push_back(numbers[i] +   m[count]);
                else
                    answer.push_back(numbers[i] + m[count]- m[count - 1]);
                break;
            }
        }
        if(answer.size() - 1 != i)
        {
            answer.push_back((numbers[i] << 1) + 1 - m[count - 1]);
        }
    }
    
    return answer;
}