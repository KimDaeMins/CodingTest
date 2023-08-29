#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    answer.resize(players.size());
    unordered_map<string, int> m;
    for(int i = 0; i < players.size(); ++i)
    {
        m.emplace(players[i], i);
    }
    
    for(int i = 0; i < callings.size(); ++i)
    {
        //인덱스추출
        int index = m[callings[i]];
        int index2 = index - 1;
        
        //player에서 순위바꾸고
        string temp = players[index];
        players[index] = players[index2];
        players[index2] = temp;
        
        //map에 적용
        m[players[index2]]--;
        m[players[index]]++;
    }
    for(auto p : m)
    {
        answer[p.second] = p.first;
    }
    return answer;
}