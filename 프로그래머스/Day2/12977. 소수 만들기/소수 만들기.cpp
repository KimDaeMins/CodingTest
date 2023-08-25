#include <vector>
#include <iostream>
using namespace std;

bool isPrime(int num) {
if (num <= 1) {
return false;
}
if (num <= 3) {
    return true;
}

if (num % 2 == 0 || num % 3 == 0) {
    return false;
}

for (int i = 5; i * i <= num; i += 6) {
    if (num % i == 0 || num % (i + 2) == 0) {
        return false;
    }
}

return true;
}

int combi(vector<int> nums, int start, vector<int> a, int n)
{
    if(a.size()  == 3)
    {
        if(isPrime(nums[a[0]] + nums[a[1]] + nums[a[2]]))
            return 1;
        return 0;
    }
    int answer = 0;
    for(int i = start + 1; i < n; ++i)
    {
        a.push_back(i);
        answer += combi(nums, i, a, n);
        a.pop_back();
    }
    return answer;
}
int solution(vector<int> nums) {
    int answer = -1;
    vector<int> a; 
    answer = combi(nums, -1, a, nums.size());
    
    return answer;
}