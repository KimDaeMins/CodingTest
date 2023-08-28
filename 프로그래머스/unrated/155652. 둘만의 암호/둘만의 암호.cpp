#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    bool skips[26] = {};
    for(char c : skip) 
        skips[c - 'a'] = true;
    
    for(char c : s)
    {
        int idx = index;
        while(idx)
        {
            do
            {
                ++c;
             if(c > 'z')
                 c -= 26;
            }while(skips[c - 'a']);
            --idx;
        }
        answer += c;
    }
    return answer;
}