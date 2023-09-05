#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isPrime(unsigned long long num)
{
    if( num <= 1)
    {
        return false;
    }
    
    for(long long i = 2; i * i <= num; ++i)
        if(num % i == 0)
            return false;
    return true;
}
int solution(int n, int k) {
    int answer = 0;

    string a;

    while (n)
    {
        a.insert(0, to_string(n % k));
        n /= k;
    }

    long start = 0;
    long end = 0;
    while (end != std::string::npos)
    {
        end = a.find('0', start);
        unsigned long long num = 0;
        if(start != end && start != a.size())
            num = stoull(a.substr(start, end - start));
    
        start = end + 1;


        if (isPrime(num))
            answer++;
    }
    return answer;
}