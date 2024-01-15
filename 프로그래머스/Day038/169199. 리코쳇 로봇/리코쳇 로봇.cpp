#include <string>
#include <vector>
#include <queue>

using namespace std;

//1. g에 도달할 수 없는 경우'
//1-1. g주변에 벽이 하나도 없다.
//1-2. g주변에 벽이 4개가있다.(끝벽포함)
//이걸 먼저 제외하고

//R에서부터 시작 END좌표를 구한 후 맵에 저장 - 부딫힌 벽의 반대로는 가지않는다
//종착지가 이미 도달했던 곳이라면 가지않는다.
//이렇게 구분해서 최종 도착지를 판정한다.

int dy[4] = { -1, 0 , 1, 0 };
int dx[4] = { 0, 1 , 0, -1 };

typedef pair<int, int> p;

int solution(vector<string> board) {
	int answer = 0;

	int boardY = board.size();
	int boardX = board[0].length();

	vector<vector<int>> visit;
	vector<vector<bool>> moveable;
	p endPos;
	p startPos;

	visit.resize(boardY, vector<int>());
	moveable.resize(boardY, vector<bool>());


	//최초 맵 설정
	for (int i = 0; i < boardY; ++i)
	{
		visit[i].resize(boardX, 0);
		moveable[i].resize(boardX, true);
		for (int j = 0; j < boardX; ++j)
		{
			if (board[i][j] == 'R')
			{
				visit[i][j] = 0;
				startPos.first = i;
				startPos.second = j;
			}
			else if (board[i][j] == 'G')
			{
				endPos.first = i;
				endPos.second = j;
			}
			else if (board[i][j] == 'D')
			{
				moveable[i][j] = false;
			}
		}
	}


	//깊이는 어따넣을건데...
	queue<p> q;

	q.emplace(startPos.first, startPos.second);

	while (!q.empty())
	{
		p np = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = np.first;
			int nx = np.second;
			while (true)
			{
				ny += dy[i];
				nx += dx[i];

				if (ny < 0 || ny >= boardY || nx < 0 || nx >= boardX
					|| moveable[ny][nx] == false)
				{
					ny -= dy[i];
					nx -= dx[i];
					if (np.first == ny && np.second == nx)
						break;

					if (visit[ny][nx] == 0)
					{
						if (endPos.first == ny && endPos.second == nx)
							return visit[np.first][np.second] + 1;

						visit[ny][nx] = visit[np.first][np.second] + 1;
						q.emplace(ny, nx);
					}

					break;
				}
			}
		}
	}
	return -1;
}