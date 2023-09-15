#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    
    int dot = 0;
    dot = d / k + 1;
    long long longd = (long long)d * d;
    //원모양이여야되네?
    for (long long i = 0; i < dot; ++i)
    {
        long long lineA = i * k* i * k;

        int j = sqrt((longd - lineA));
        answer += j / k + 1;
    }
    return answer;
}