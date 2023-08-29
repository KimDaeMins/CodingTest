#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    vector<int> dayCheck;
    unordered_map<char, int> map;
    for(string a : terms)
    {
        map.emplace(a[0], stoi(a.substr(2)));
    }
    for(string a : privacies)
    {
        int y = stoi(a.substr(0, 4));
        int m = stoi(a.substr(5, 2));
        int d = stoi(a.substr(8, 2));
        char t = a[11];
        dayCheck.push_back((y - 2000) * 12 * 28 + m * 28 + d + map[t] * 28 - 1);
    }
    int y = stoi(today.substr(0, 4));
    int m = stoi(today.substr(5, 2));
    int d = stoi(today.substr(8, 2));
    int now = (y - 2000) * 12 * 28 + m * 28 + d;
    
    for(int i = 0; i < dayCheck.size(); ++i)
    {
        if(dayCheck[i] < now)
        {
            answer.push_back(i + 1);
        }
    }
    return answer;
}