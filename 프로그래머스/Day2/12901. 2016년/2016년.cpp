#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    //1.윤년이뭔지
    //2.각 개월의 일수.
    int days[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int count = 0;
    for(int i = 1; i < a; ++i)
    {
        count += days[i];
    }
    count +=  b;
    string results[7] = {"THU","FRI","SAT","SUN","MON","TUE","WED"};
    answer = results[count % 7];
    return answer;
}