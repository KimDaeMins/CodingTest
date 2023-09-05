#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

//1. 서로 연결된 전력망을 하나 만든다. -> 멀티셋이였나? 셋배열을 이용함
int LinkNum(vector<set<int>> _graph, int _n, int _wireNumber)
{
    int length = 0;
    queue<int> q;
    q.push(_wireNumber);
    
   vector<bool> Visit(_n);
    Visit[_wireNumber] = true;
    
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        ++length;
        
        for(auto& Link : _graph[front])
        {
            if(Visit[Link])
                continue;
            
            q.push(Link);
            Visit[Link] = true;
        }
    }
    return length;
}
int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    
    vector<set<int>> graph;
    graph.resize(n + 1);
    
    //서로 연결된 와이어들을 셋에 담아뒀음.
    for(auto& wire : wires)
    {
        graph[wire[0]].insert(wire[1]);
        graph[wire[1]].insert(wire[0]);
    }
    
    for(auto& wire : wires)
    {
        graph[wire[0]].erase(wire[1]);
        graph[wire[1]].erase(wire[0]);
        
        //체크한다 무엇을? 이 선이 끊어졌을 때 이 두놈을 기준으로 나온 송전탑 갯수의 차이의 최솟값을
        answer = min(answer, abs(LinkNum(graph ,n, wire[0]) - LinkNum(graph, n, wire[1])));
        
        graph[wire[0]].insert(wire[1]);
        graph[wire[1]].insert(wire[0]);
    }
    
    
    
    
    
    return answer;
}