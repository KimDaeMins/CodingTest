#include <string>
#include <vector>

using namespace std;
//조합문제 0~199
bool tm[200] = {};
void combi(vector<int>num, int start, vector<int> a, int n)
{
    if(a.size() == 2)
    {
        tm[num[a[0]] + num[a[1]]] = true;
        return;
    }
    
    for(int i = start + 1; i < n; ++i)
    {
        a.push_back(i);
        combi(num, i, a, n);
        a.pop_back();
    }
    return;
}
vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    vector<int> a;
    combi(numbers, -1,a, numbers.size());
    
    for(int i =0; i < 200; ++i)
    {
        if(tm[i])
            answer.push_back(i);
    }
    return answer;
}