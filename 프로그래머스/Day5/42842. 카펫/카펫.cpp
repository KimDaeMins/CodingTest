#include <string>
#include <vector>

//1개일땐 8개, 2개일땐 10개, 3개일땐 12개 4개일땐 14개 or 12개
//가로 세로간의 공식이 있지않을까?
//가로가 몇이냐 세로가 몇이냐의 공식인거니까..
//가로*2 + 세로*2 + 4 = 갈색갯수.
//가로 * 세로 = 노랑갯수
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    //만약 노랑갯수가 16이면 4,4도되고 8,2 도 되고, 16,1 도 됨.
    //근데 이건 배수의 문제지 24면 6, 4도되고, 8, 3도되고 12,2 도되고, 24, 1도된다는거
    //노랑갯수를 1~노랑갯수까지 나눴을 때 나머지가 없는 수.
    for(int i = 1; i <= yellow && yellow / i >= i; ++i)
    {
        if(yellow % i == 0 && (yellow / i) * 2 + i * 2 + 4 == brown)
        {
            answer.push_back(yellow/i + 2);
            answer.push_back(i + 2);
            break;
        }
    }
    return answer;
}