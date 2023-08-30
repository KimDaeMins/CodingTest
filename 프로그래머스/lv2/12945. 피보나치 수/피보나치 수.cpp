#include <string>
#include <vector>

using namespace std;

int Fibo(int n )
{
    if(n == 1 || n == 0)
        return n;
    
    return Fibo(n - 1) + Fibo(n - 2);
}
int solution(int n) {
    int answer = 0;
    long long a[100001];
    
    a[0] = 0;
    a[1] = 1;
    
    for(int i = 2; i  <= n; ++i)
    {
        a[i] = (a[i - 1] + a[i - 2]) % 1234567;
    }
    answer = a[n];
    return answer;
}