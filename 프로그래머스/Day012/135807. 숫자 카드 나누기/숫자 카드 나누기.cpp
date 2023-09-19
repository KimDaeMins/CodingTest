#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int gcd(int a, int b)
{
    while(b)
    {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
int check(vector<int> a , vector<int> b)
{
    sort(a.begin(), a.end());
	int diviser= a[0];
	
    for (int i = 0; i < a.size(); ++i)
	{
		diviser = gcd(a[i], diviser);
    }
	
    vector<int> v;
    if(diviser != 1)
		v.push_back(diviser);
    for (int i = 2; i <= sqrt(diviser); ++i)
	{
		if (diviser % i == 0)
		{
			v.push_back(i);
			v.push_back(diviser / i);
		}
	}
    sort(v.begin(), v.end(), greater<int>());
    
    for(int i = 0; i < v.size(); ++i)
    {
        int j = 0;
        for(; j < b.size(); ++j)
        {
            if(b[j] % v[i] == 0)
                break;
        }
        if(j == b.size())
            return v[i];
    }
    return 0;
}
int solution(vector<int> arrayA, vector<int> arrayB) {
	 int answer;
    answer = max(check(arrayA, arrayB), check(arrayB, arrayA));
	return answer;
}