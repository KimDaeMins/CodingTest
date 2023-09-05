#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int, int> leftmap;
    map<int, int> rightmap;
    for(int a  : topping)
    {
        rightmap[a]++;
    }
    
    for(int i = 0; i < topping.size(); ++i)
    {
        int t = topping[i];
        leftmap[t]++;
        rightmap[t]--;
        if(rightmap[t] == 0)
        {
            rightmap.erase(t);
        }
        if(leftmap.size() == rightmap.size())
            answer++;
    }
    return answer;
}