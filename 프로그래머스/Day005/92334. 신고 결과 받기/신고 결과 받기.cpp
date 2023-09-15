#include <string>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    unordered_map<string, int> reports;
    unordered_map<string, set<string>> indexs;
    
    for(int i = 0; i < report.size() ; ++i)
    {
        int findIndex = report[i].find(" ");
        string a = report[i].substr(0, findIndex);
        string b = report[i].substr(findIndex + 1);
        
        indexs[a].insert(b);
    }
    
    for(auto p : indexs)
    {
        for(string str : p.second)
        {
            reports[str]++;
        }
    }
    
    for(string str : id_list)
    {
        int a = 0;
        for(string s : indexs[str])
        {
            if(reports[s] >= k)
                ++a;
        }
        answer.push_back(a);
    }
    
    
    return answer;
}