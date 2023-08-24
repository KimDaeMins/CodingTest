#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> a;
    while(n)
    {
        a.push_back(n % 3);
        n /= 3;
    }
    //0121
    std::reverse(a.begin(), a.end());
    //1210
    int num = 1;
    for(int i = 0; i < a.size(); ++i)
    {
        answer += a[i] * num;
        num *= 3;
    }
    return answer;
}