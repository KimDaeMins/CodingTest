#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    //1.앞에서부터 읽는다
    //2.영단어일때 뭔지 확인한다
    //3.지운다
    string temp = "";
    for(int i = 0; i < s.size(); )
    {
        if(isdigit(s[i]))
        {
            temp += s[i];
            ++i;
        }
        else if(s[i] == 'z')
        {
            temp += '0';
            i += 4;
        }
          else if(s[i] == 'o')
        {
            temp += '1';
              i += 3;
        }
          else if(s[i] == 't')
        {
            if(s[i + 1] == 'w')
            {
              temp += '2';
                i+=3;
            }
              else
              {
                  temp += '3';
                  i+=5;
              }
        }
          else if(s[i] == 'f')
        {
            if(s[i+1] == 'o')
            {
                temp += '4';
            }
              else 
              {
                  temp += '5';
              }
              i += 4;
        }
        else if(s[i] == 's')
        {
             if(s[i + 1] == 'i')
            {
              temp += '6';
                i+=3;
            }
              else
              {
                  temp += '7';
                  i+=5;
              }
        }
        else if(s[i] == 'e')
        {
            temp += '8';
            i+=5;
        }
        else if(s[i] == 'n')
        {
            temp += '9';
            i+=4;
        }
    }
    answer = stoi(temp);
    return answer;
}