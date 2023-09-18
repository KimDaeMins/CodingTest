#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int dirY[4] = { -1, 0, 1, 0 };
int dirX[4] = { 0, 1, 0, -1 };
bool DFS(vector<string> place, bool check[][5], int posY, int posX, int depth)
{
    if (depth == 2)
    {
       return true;
    }

    check[posY][posX] = true;

    for (int i = 0; i < 4; ++i)
    {
        int nextY = posY + dirY[i];
        int nextX = posX + dirX[i];
        if (nextY < 0 || nextX < 0 || nextY >= 5 || nextX >= 5)
            continue;

        if (!check[nextY][nextX])
        {
            if (place[nextY][nextX] == 'P')
            {
                return false;
            }

            if (place[nextY][nextX] == 'O')
            {
                if (!DFS(place, check, nextY, nextX, depth + 1))
                    return false;
            }
        }
    }
    return true;
}
bool CheckKeepDistance(vector<string> place)
{
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (place[i][j] == 'P')
            {
                bool check[5][5] = {};
                if (!DFS(place, check, i, j, 0))
                    return false;
            }
        }
    }
    return true;
}
vector<int> solution(vector<vector<string>> places) {


    vector<int> answer;

    for (int i = 0; i < places.size(); ++i)
    {
        if (CheckKeepDistance(places[i]))
        {
            answer.push_back(1);
        }
        else
            answer.push_back(0);
    }
    return answer;
}