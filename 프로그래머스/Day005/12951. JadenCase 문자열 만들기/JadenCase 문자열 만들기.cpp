#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int start = 0;
    int end = 0;
    
    bool before = true;
    for(int i = 0; i < s.size(); ++i)
    {
        if(before)
        {
            before = false;
            if(!isdigit(s[i]) && islower(s[i]))
            {
                s[i] = toupper(s[i]);
            }
        }
        else if(!isdigit(s[i]))
        {
            s[i] = tolower(s[i]);
        }
        
        if(s[i] == ' ')
            before = true;
    }
    answer = s;
    return answer;
}