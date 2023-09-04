#include <string>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    deque<pair<int, int>> DQ;
    
    for(int i = 0; i < progresses.size(); ++i)
        DQ.push_back(pair(progresses[i], speeds[i]));
    
    
    while(!DQ.empty()) {
        for(int i = 0; i < DQ.size(); ++i) {
        DQ[i].first += DQ[i].second;
        }
       
        int Count = 0;
        while(!DQ.empty() && DQ.front().first >= 100) {
            ++Count;
            DQ.pop_front();
        }
        
        if(Count)
            answer.push_back(Count);
    }
    
    return answer;
}