#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    
    int i = 0;
    for(; i < s.size(); ++i)
    {
        char digit = s[i];
        if(digit < '0' || digit > '9')
        {
            answer = false;
            break;
        }
    }
    if(i != 4 && i != 6)
       answer = false;
        
    
    return answer;
}