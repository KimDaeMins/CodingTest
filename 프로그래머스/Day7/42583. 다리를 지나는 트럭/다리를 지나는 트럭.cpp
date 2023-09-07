#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    queue<int> Bridge;
    queue<int> wait;
    for(int i = 0; i < bridge_length; ++i)
        Bridge.push(0);
    for(auto& INT : truck_weights)
        wait.push(INT);
    
    int nowWeight = 0;
    do {
        nowWeight -= Bridge.front();
        Bridge.pop();
        
        if(!wait.empty() && weight >= nowWeight + wait.front()) {
            Bridge.push(wait.front());
            nowWeight += wait.front();
            wait.pop();
        }
        else {
            Bridge.push(0);
        }
        ++answer;
    }while(nowWeight != 0);
    //다르게 사용한다면 남은차가 없을 때 마지막 이동시간은 무조건 다리길이니까
    //while문을 추가로 돌 필요가 없게끔 만들 수 있다는 점을 이용한 연산방식도 있다.
    return answer;
}