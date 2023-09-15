#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    
    int aCount = 0;
    int bCount = 0;
    for(int i = 0; i < goal.size(); ++i)
    {
        if(cards1[aCount] == goal[i])
            ++aCount;
        else if(cards2[bCount] == goal[i])
            ++bCount;
        else
        {
            answer = "No";
            break;
        }
    }
    
    
    return answer;
}