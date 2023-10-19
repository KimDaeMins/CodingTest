#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//맵사이즈 = 얼마나 연결되어있는지
//vector<map<다음녀석, 나>> 횟수;
//다음녀석만 들고있어도 되지않나?
//횟수만 들고있어도 되지않나?
int solution(vector<int> cards) {
    int answer = 0;
    vector<int> counts;
    
    int index = 0;
    counts.push_back(0);
    for(int i = 0; i < cards.size(); ++i)
    {
        int next = i;
        while(true)
        {
            if(cards[next] != 0)
            {
                int now = next;
                next = cards[now] - 1;
                cards[now] = 0;
                ++counts[index];
            }
            else
            {
                if(counts[index] > 0)
                {
                    counts.push_back(0);
                    ++index;
                }
                break;
            }
        }
    }
    
    if(counts.size() > 1)
    {
        sort(counts.begin(), counts.end(), greater<int>());
        answer = counts[0] * counts[1];
    }
    return answer;
}