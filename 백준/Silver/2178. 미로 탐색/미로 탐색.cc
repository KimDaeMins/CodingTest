#include <vector>
#include <queue>
#include <iostream>
#include <string>

using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int Solution(int N, int M, vector<vector<int>> v)
{
	//N = 세로	
	//M = 가로
	queue<pair<int, int>> q;
	vector<vector<int>> visit;
	visit.resize(N);
	for(int i = 0; i < N; ++i)
	{
		visit[i].resize(M, 0);
	}
	q.emplace(0, 0);
	visit[0][0] = 1;
	
	while (!q.empty())
	{
		const pair<int, int> p = q.front();
		q.pop();
		if(p.first == N - 1 && p.second == M - 1)
			break;
		for (int i = 0; i < 4; ++i)
		{
			if(p.second + dx[i] < 0 || p.second + dx[i] >= M
				||p.first + dy[i] < 0 || p.first + dy[i] >= N)
					continue;
			if(visit[p.first + dy[i]][p.second + dx[i]] != 0)
				continue;
			if(v[p.first + dy[i]][p.second + dx[i]] == 0)
				continue;
			
			visit[p.first + dy[i]][p.second + dx[i]] = visit[p.first][p.second] + 1;
			q.emplace(p.first +dy[i], p.second + dx[i]);
		}
	}
	return visit[N - 1][M - 1];
}

int main()
{
	int a = 0;
	cin >> a;
	int b = 0;
	cin >> b;
	
	vector<vector<int>> c;

	c.resize(a);
	for (int i = 0; i < a; ++i)
	{
		string d;
		cin >> d;
		c[i].resize(b);
		for(int j = 0; j < b; ++j)
		{
			c[i][j] = d[j] - '0';
		}
	}
	cout << Solution(a, b, c) << endl;
	return 0;
}
