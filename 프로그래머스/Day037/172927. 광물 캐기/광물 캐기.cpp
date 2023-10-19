#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;


int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;   
    
    int numpick = 0;
    for(int i =0 ; i < 3; ++i)
    {
       numpick += picks[i];
    }
    priority_queue<pair<int, int>> pq;
    unordered_map<string, int> um;
    um.emplace("diamond", 100);
    um.emplace("iron", 10);
    um.emplace("stone", 1);
    int mineCount = 0;
    int value = 0;
    for(int i = 0; i < minerals.size(); ++i)
    {
        if(numpick == 0)
            break;
        
        value += um[minerals[i]];
        ++mineCount;
        
        if(mineCount == 5)
        {
            pq.push(pair<int, int>(value, mineCount));
            mineCount = 0;
            value = 0;
            --numpick;
        }
    }
    if(mineCount > 0)
        pq.push(pair<int, int>(value, mineCount));
    
    while(!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();
        
        if(picks[0] > 0)
        {
            --picks[0];
            answer += p.second;
        }
        else if(picks[1] > 0)
        {
            --picks[1];
            int dia = (p.first / 100);
            answer += dia * 5 + p.second - dia;
        }
        else if( picks[2] > 0)
        {
            --picks[2];
            int dia = p.first / 100;
            p.first %= 100;
            int iron = p.first / 10;
            answer += dia * 25 + iron * 5 + p.second - dia - iron;
        }
    }
    return answer;
}