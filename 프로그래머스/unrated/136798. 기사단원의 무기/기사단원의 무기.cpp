#include <iostream>

int sumOfDivisors(int n)
{
    int result = 0;
    for(int i=1;i * i<=n;i++)
    {
        if(n%i == 0)
        {
            ++ result;
            if(i != n / i)
                ++result;
        }
    }
	return result;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    int weapon = 0;
    for(int i = 1 ; i <= number; ++i)
    {
        weapon =  sumOfDivisors(i);
        if(weapon > limit)
            weapon = power;
        answer += weapon;
    }
    return answer;
}