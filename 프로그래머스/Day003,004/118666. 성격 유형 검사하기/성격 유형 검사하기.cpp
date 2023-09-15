#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int Score[26] = {}; 
    vector<int> words = {'R' - 'A', 'T' - 'A',
                         'C' - 'A', 'F' - 'A',
                         'J' - 'A', 'M' - 'A',
                         'A' - 'A', 'N' - 'A'};
    for(int i = 0; i < choices.size(); ++i)
    {
        int c = choices[i] - 4;
        if(c < 0)
        {
            Score[survey[i][0] - 'A'] += -c;
        }
        else
        {
            Score[survey[i][1] - 'A'] += c;
        }
    }
    
    for(int i = 0; i < words.size() ; i += 2)
    {
        if (Score[words[i]] >= Score[words[i + 1]])
        {
            answer += char(words[i] + 'A');
        }
        else
        {
            answer += char(words[i + 1] + 'A');
        }
    }
    return answer;
}