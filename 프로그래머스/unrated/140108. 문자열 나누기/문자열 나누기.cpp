#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    char firstWord = s[0];
    int WordCount = 1;
    int index = 1;
    while(index != s.size())
    {
        if(firstWord == s[index])
            ++WordCount;
        else
            --WordCount;
        
        if(WordCount == 0)
        {
            ++answer;
            
            if(index + 1 == s.size())
                return answer;
            firstWord = s[++index];
            WordCount = 1;
        }
        ++index;
    }
     ++answer;
    return answer;
}