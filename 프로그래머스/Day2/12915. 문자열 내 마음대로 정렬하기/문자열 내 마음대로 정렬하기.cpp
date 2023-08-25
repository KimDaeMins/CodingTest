#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    map<char, priority_queue<string, vector<string>, greater<string>>> temp;
    for(int i = 0; i < strings.size(); ++i)
    {
        temp[strings[i][n]].push(strings[i]);
    }
    for(auto& pq : temp)
    {
        while(!pq.second.empty())
        {
            answer.push_back(pq.second.top());
            pq.second.pop();
        }
    }
    return answer;
}