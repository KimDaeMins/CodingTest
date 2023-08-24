#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> a;
    while(n)
    {
        a.push_back(n % 10);
        n /= 10;
    }
    
    std::sort(a.begin(), a.end());
    int b = 1;
    for(int i = 0; i < a.size(); ++i)
    {
        answer += a[i] * b;
        b *= 10;
    }
    return answer;
}