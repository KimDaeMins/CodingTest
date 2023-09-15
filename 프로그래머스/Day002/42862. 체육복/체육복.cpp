#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    //어차피 왼쪽에서 오른쪽으로 찾으면 그게그거다는것... 그래서 그렇구만
    vector<int> v;
    v.resize(n + 2, 0);
    for(auto SIndex : lost)
        --v[SIndex];
    for(auto SIndex : reserve)
        ++v[SIndex];
    
    for(int i = 1; i < n + 1; ++ i)
    {
        if(v[i] == -1)
        {
            if(v[i - 1] == 1)
            {
                ++v[i];
                --v[i-1];
            }
            else if(v[i + 1] == 1)
            {
                ++v[i];
                --v[i+1];
            }
        }
    }
    
    for(auto& I : v)
        if(I != -1) ++answer;
    return answer - 2;
}