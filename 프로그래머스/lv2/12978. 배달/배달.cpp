#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<vector<int>> graph;
vector<long> check;
void DFS(int now, long nowDis)
{
    check[now] = nowDis;

    for (int i = 0; i < graph.size(); ++i)
    {
        if (graph[now][i] != 10001 && check[i] > nowDis + graph[now][i])
        {
            DFS(i, nowDis + graph[now][i]);
        }
    }
    return;
}
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    for (int i = 0; i < N; ++i)
    {
        vector<int> a;
        a.resize(N, 10001);
        graph.push_back(a);
    }
    check.resize(N, K + 1);

    for (int i = 0; i < road.size(); ++i)
    {
        int minLoad = min(graph[road[i][0] - 1][road[i][1] - 1], road[i][2]);
        graph[road[i][0] - 1][road[i][1] - 1] = minLoad;
        graph[road[i][1] - 1][road[i][0] - 1] = minLoad;
    }

    DFS(0, 0);

    for (int i = 0; i < N; ++i)
    {
        if (check[i] <= K)
            answer++;
    }
    return answer;
}