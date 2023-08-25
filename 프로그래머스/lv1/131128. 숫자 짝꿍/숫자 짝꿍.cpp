#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    int a[10] = {};
    int b[10] = {};
    for(char c : X)
    {
        ++a[c - '0'];
    }
    for(char c : Y)
    {
        ++b[c - '0'];
    }
    
    for(int i = 9; i > 0; --i)
    {
        int count = min(a[i], b[i]);
        
        answer += string(count, (char)(i + '0'));
    }
    
    if(answer.empty())
    {
        if(min(a[0], b[0]))
            answer = "0";
        else
            answer = "-1";
    }
    else
    {
        int count = min(a[0], b[0]);
        
        answer += string(count, '0');
    }
    return answer;
}