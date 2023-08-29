#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    //i중 가장 작은값은 0에
    //i중 가장 큰 값은 2에
    //j중 가장 작은값은 1에
    //j중 가장 큰값은 3에
    answer.push_back(100);
        answer.push_back(100);
        answer.push_back(0);
        answer.push_back(0);
    for(int i = 0; i < wallpaper.size() ; ++i)
    {
        bool isshap = false;
        for(int j = 0; j < wallpaper[i].size(); ++j)
        {
            if(wallpaper[i][j] == '#')
            {
                isshap = true;
                answer[1] = min(answer[1], j);
                answer[3] = max(answer[3], j + 1);
            }
        }
        if(isshap)
        {
            answer[0] = min(answer[0], i);
            answer[2] = i + 1;
        }
        
    }
    return answer;
}