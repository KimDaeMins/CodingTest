#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    //가로는 긴것중에 긴거
    //세로는 짧은것중에 긴거.
    
    int g = 0;
    int s = 0;
    
    for(auto& vec : sizes)
    {
        int Long = max(vec[0], vec[1]);
        int Short = min(vec[0], vec[1]);
        
        g = max(g, Long);
        s = max(s, Short);
    }
    answer = g * s;
    return answer;
}