#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<bool>> visit;

int Dfs(int y, int x, vector<string>* pmaps)
{
    if(y >= visit.size() || y < 0)
        return 0;
    if(x >= visit[0].size() || x < 0)
        return 0;
    if(visit[y][x])
        return 0;
    if((*pmaps)[y][x] == 'X')
        return 0;
    
    visit[y][x] = true;
    
    int num = (*pmaps)[y][x] - '0';
   
    num += Dfs(y - 1 , x, pmaps);
    num += Dfs(y + 1 , x, pmaps);
    num += Dfs(y, x - 1, pmaps);
    num += Dfs(y, x + 1, pmaps);
    
    return num;
}
vector<int> solution(vector<string> maps) {
    vector<int> answer;
    visit.resize(maps.size(), vector<bool>());
    
    for(auto& a : visit)
    {
        a.resize(maps[0].size(), false);
    }

    for(int i = 0; i < visit.size(); ++i)
    {
        
        for(int j = 0; j < visit[0].size(); ++j)
        {
            int num = Dfs(i , j ,&maps);
            if(num != 0)
                answer.push_back(num);
        }
    }
    
    if(answer.empty())
        answer.push_back(-1);
    else
        std::sort(answer.begin(), answer.end());
    
    return answer;
}