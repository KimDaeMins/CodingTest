#include <string>
#include <vector>
#include <queue>
using namespace std;
int moveY[4] = {-1, 0, 1, 0};
int moveX[4] = {0, 1, 0, -1};
enum Dir {상, 우, 하, 좌};
vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    vector<vector<char>> Xs;
    Xs.resize(park.size());
    queue<pair<Dir, int>> moves;
    pair<int, int> dog;
    for(int i = 0; i < park.size(); ++i)
    {
        for(int j = 0; j < park[i].size(); ++j)
        {
            Xs[i].push_back(park[i][j]);
            
            if(park[i][j] == 'S')
                dog = pair<int,int>(i, j);
        }
    }
    
    for(int i = 0; i < routes.size(); ++i)
    {
        if(routes[i][0] == 'N')
            moves.push(pair<Dir,int>(상, stoi(routes[i].substr(2))));
        else if(routes[i][0] == 'E')
            moves.push(pair<Dir,int>(우, stoi(routes[i].substr(2))));
        else if(routes[i][0] == 'S')
            moves.push(pair<Dir,int>(하, stoi(routes[i].substr(2))));
        else if(routes[i][0] == 'W')
            moves.push(pair<Dir,int>(좌, stoi(routes[i].substr(2))));
    }
    
    while(!moves.empty())
    {
        pair<Dir, int> p = moves.front();
        moves.pop();
        pair<int, int> shadowDog = dog;
        bool move = true;
        
        int endPosX = shadowDog.first + moveY[p.first] * p.second;
        int endPosY = shadowDog.second + moveX[p.first] * p.second;
        if(endPosX < 0 || endPosX >= Xs.size()
          ||endPosY < 0 || endPosY >= Xs[0].size())
            continue;
        
        for(int i = 0; i < p.second; ++i)
        {
            shadowDog.first += moveY[p.first];
            shadowDog.second += moveX[p.first];
            
            if(Xs[shadowDog.first][shadowDog.second] == 'X')
            {
                move = false;
                break;
            }
        }
        
        if(move == true)
        {
            dog = shadowDog;
        }
    }
    answer.push_back(dog.first);
        answer.push_back(dog.second);
    return answer;
}