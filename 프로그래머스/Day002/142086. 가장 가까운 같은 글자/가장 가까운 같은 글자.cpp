#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int arr['z' - 'a' + 1];
    std::fill(arr, arr + ('z' - 'a' + 1), -1);
    
    for(int i = 0; i < s.size(); ++i)
    {
        if(arr[s[i] - 'a'] == -1)
            answer.push_back(-1);
        else
           answer.push_back( i - arr[s[i] - 'a']);
        
        arr[s[i] - 'a'] = i;
    }
    return answer;
}