#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <math.h>
using namespace std;

bool isPrime(unordered_map<int, bool>* _pm, int _num)
{
    if((*_pm)[_num])
        return false;
    
    (*_pm)[_num] = true;
    
    if ( _num < 2) return false;
    
    int CheckMax = sqrt(_num);
    for(int i = 2; i <= CheckMax; ++i)
    {
        if(_num % i == 0) return false;
    }
    
    return true;
}

int solution(string numbers) {
    int answer = 0;
    unordered_map<int, bool> m;
    
    sort(numbers.begin(), numbers.end());
    
    do{
        for(int i = 0; i < numbers.size(); ++i)
        {
            if(isPrime(&m, stoi(numbers.substr(0, i + 1))))
            {
                ++answer;
            }
        }
    }while(next_permutation(numbers.begin(), numbers.end()));
    
    return answer;
}