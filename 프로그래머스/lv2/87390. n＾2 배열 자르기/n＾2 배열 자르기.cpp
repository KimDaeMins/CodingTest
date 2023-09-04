#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    //123223333   1234 2234 3334 4444  n = 4  7번째를 나타낸다면 
    int mincount = left / n + 1;
    int added = left % n;
    
    for(long long i = left; i < right + 1; ++i)
    {
        int mincount = i / n + 1;
        answer.push_back(max(int(i % n + 1), mincount));
    }
    return answer;
}