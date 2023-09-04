#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int allNum = 0;
    unordered_map<string, int> m;
     unordered_map<string, int> temp;
    for(int i = 0; i < want.size(); ++i)
    {
        m[want[i]] = number[i];
        allNum += number[i];
    }
    
    for(int i = 0; i <= discount.size() - allNum; ++i)
    {
        temp = m;
        for(int j = i; j < i + allNum; ++j)
        {
            --temp[discount[j]];
        }
        
        bool check = true;
        for(auto p : temp)
        {
            if(p.second != 0)
            {
                check = false;
                break;
            }
        }
        if(check)
            answer++;
    }
    return answer;
}