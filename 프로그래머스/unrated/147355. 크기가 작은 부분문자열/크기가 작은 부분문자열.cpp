#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    for(int i =0 ; i < t.size() - p.size() + 1; ++i)
    {
        string snum = t.substr(i, p.size());
        unsigned long long num = stoull(snum);
        unsigned long long pnum = stoull(p);
        if(num <= pnum)
        {
            answer += 1;
        }
        
    }
    return answer;
}