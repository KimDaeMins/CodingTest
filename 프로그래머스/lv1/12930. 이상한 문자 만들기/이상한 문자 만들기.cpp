#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int count = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == ' ')
        { 
            count = 0;
            continue;
        }
        
        if(count % 2 == 0)
            s[i] = std::toupper(s[i]);
        else
            s[i] = std::tolower(s[i]);
        ++count;
    }
    answer = s;
    return answer;
}