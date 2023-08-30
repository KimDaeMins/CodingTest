#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    long long dp[n + 1];
    //7칸일때 21개
    //6칸일때 13개
    //5칸일때 8개 
    //4칸일때 5개
    //3칸일때 3개
    //2칸일때 2개
    //1칸일때 1개
    //아놔 숫자 잘못세서 틀력네씨
    dp[1] = 1;
    dp[2] = 2;
    for(int i  = 3 ; i <= n; ++i)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1234567;
    }
    answer = dp[n];
    return answer;
}