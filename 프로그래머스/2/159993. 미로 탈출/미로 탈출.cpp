#include <string>
#include <vector>

using namespace std;

//Dfs도 좋지만 이전에 갔던 곳은 가지않는방식으로 BFS를 짜는것도 좋았을 것 같다
//너비우선탐색이라 이전에 방문했던것보다 늦게 들어가면 더 느리단 소리니까
//그게 더 효율적이긴했을듯
int dirX[4] = { 0, 1, 0, -1 };
int dirY[4] = { -1, 0 , 1, 0 };
void Dfs(int nowX, int nowY, int endX, int endY, int depth, vector<vector<int>>& map)
{
	if (map[endY][endX] <= depth)
		return;

	map[nowY][nowX] = depth;

	for (int i = 0; i < 4; ++i)
	{
		int nextX = nowX + dirX[i];
		int nextY = nowY + dirY[i];
		int nextDepth = depth + 1;
		if (nextX < 0 || nextX >= map[0].size() || nextY < 0 || nextY >= map.size())
			continue;
		if (map[nextY][nextX] != 99999 && map[nextY][nextX] <= nextDepth)
			continue;
		if (map[nextY][nextX] == -1)
			continue;

		Dfs(nextX, nextY, endX, endY, nextDepth, map);
	}
}
int solution(vector<string> maps) {
	int answer = 0;
	vector<vector<int>> m;
	vector<vector<int>> m2;
	//두개를 만들거임
	int startX;
	int startY;
	int leverX;
	int leverY;
	int endX;
	int endY;

	for (int i = 0; i < maps.size(); ++i)
	{
		vector<int> a(maps[i].length());
		for (int j = 0; j < maps[i].length(); ++j)
		{
			char c = maps[i][j];

			if (c == 'O')
			{
				a[j] = 99999;
			}
			else if (c == 'X')
			{
				a[j] = -1;
			}
			else if (c == 'S')
			{
				a[j] = 99999;
				startX = j;
				startY = i;
			}
			else if (c == 'L')
			{
				a[j] = 99999;
				leverX = j;
				leverY = i;
			}
			else
			{
				a[j] = 99999;
				endX = j;
				endY = i;
			}
		}
		//하나로 줄일 방법이 있을 것 같긴 한데 그니까 다하고 복붙하는 방식으로.. ㅇㅇ.. 
		m.push_back(a);
		m2.push_back(a);
	}

	Dfs(startX, startY, leverX, leverY, 0, m);
	int StoL = m[leverY][leverX];
	if (StoL != 99999)
	{
		Dfs(leverX, leverY, endX, endY, 0, m2);
		int LtoE = m2[endY][endX];
		if (LtoE != 99999)
		{
			answer += StoL + LtoE;
		}
		else
			answer = -1;
	}
	else
		answer = -1;

	return answer;
}