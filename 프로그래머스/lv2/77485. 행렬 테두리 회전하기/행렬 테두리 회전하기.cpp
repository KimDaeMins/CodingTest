#include <string>
#include <vector>
#include <cmath>
using namespace std;
//10000*100*4 400만 -> 가능
//내일하자
//이론은뭐냐? 직접채우고 직접돌려 그게편해 라는 이론
int xMove[4] = { 1, 0, -1, 0 };
int yMove[4] = { 0, 1, 0, -1 };
enum Dir
{
    RIGHT, DOWN, LEFT, UP
};
int dir = RIGHT;
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    vector<vector<int>> v;
    v.resize(rows, vector<int>());
    for(auto& a : v)
        a.resize(columns);
    
    int input = 1;
    for(int i = 0; i < v.size(); ++i)
    {
        for(int j = 0; j < v[0].size(); ++j)
        {
            v[i][j] = input++;
        }
    }
    for(int i = 0; i < queries.size(); ++i)
    {
        int yMin = queries[i][0] - 1;
        int xMin = queries[i][1] - 1;
        int yMax = queries[i][2] - 1;
        int xMax = queries[i][3] - 1;
        
        int yNow = yMin;
        int xNow = xMin;
        int before = v[yNow][xNow];
        int minCount = before;
        dir = Dir::RIGHT;
        while(true)
        {
            yNow += yMove[dir];
            xNow += xMove[dir];
            
            if(yNow < yMin)
            {
                break;
            }
            else if(yNow > yMax)
            {
                yNow -= yMove[dir];
                xNow -= xMove[dir];
                ++dir;
            }
             else if(xNow < xMin)
            {
                yNow -= yMove[dir];
                xNow -= xMove[dir];
                ++dir;
            }
             else if(xNow > xMax)
            {
                yNow -= yMove[dir];
                xNow -= xMove[dir];
                ++dir;
            }
            else
            {
                minCount = min(v[yNow][xNow], minCount);
                int temp = before;
                before = v[yNow][xNow];
                v[yNow][xNow] = temp;
            }
        }
        answer.push_back(minCount);
    }
    
    return answer;
}