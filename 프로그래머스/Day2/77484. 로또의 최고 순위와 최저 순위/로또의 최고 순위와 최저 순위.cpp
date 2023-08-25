#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    bool wins[46] = {};
    for(int a : win_nums)
    {
        wins[a] = true;
    }
    
    int win = 0;
    int erase = 0;
    for(int a : lottos)
    {
        if(a == 0)
            ++erase;
        if(wins[a])
            ++win;
    }
    answer.push_back(min(6, 7 - erase - win));
    answer.push_back(min(6, 7 - win));
    return answer;
}