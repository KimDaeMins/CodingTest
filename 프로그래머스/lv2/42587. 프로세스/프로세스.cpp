#include <string>
#include <vector>
#include <deque>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    int LocationIndex = location;
    int DQSize = priorities.size();
    deque<int> DQ;
    for(auto& INT : priorities)
        DQ.push_back(INT);
    //1.회전시킨다. 근데 중요한 문서가 빠졌는지 확인하려면 전체순회를 해야하는거 아닌가?
    
    while(true) {
        int Front = DQ.front();
        try {
            for(auto& INT : DQ) {
                if(INT > Front) throw 0;
            }
            
            if(LocationIndex == 0) throw 1;
            else throw 2;
        }
        catch (int a) {
            switch(a) {
                case 0:
                    DQ.pop_front();
                    DQ.push_back(Front);
                    --LocationIndex;
                    if(LocationIndex < 0) LocationIndex = DQSize - 1;
                    break;
                case 1:
                    return answer;
                    break;
                case 2:
                    DQ.pop_front();
                    --LocationIndex;
                    --DQSize;
                    ++answer;
                    break;
            }
        }
    }
    return answer;
}