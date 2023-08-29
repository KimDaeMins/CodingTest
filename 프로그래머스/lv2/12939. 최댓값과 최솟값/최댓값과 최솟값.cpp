#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    priority_queue<int, vector<int>, greater<int>> pq;
    
    int start = 0;
    int end = 0;
    while(end < s.size())
    {
        end = s.find(" ", start);
        pq.push(stoi(s.substr(start, end)));
        start = end + 1;
    }
    int last;
    answer += to_string(pq.top());
    answer += " ";
    while(!pq.empty())
    {
        last = pq.top();
        pq.pop();
    }
    answer += to_string(last);
    return answer;
}