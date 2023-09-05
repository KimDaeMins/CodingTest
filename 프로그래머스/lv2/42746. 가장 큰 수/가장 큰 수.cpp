#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string A, string B) {
    return A + B > B + A;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> numbers_str;
    for(auto& I : numbers)
    { 
        numbers_str.push_back(to_string(I));
    }
    
    sort(numbers_str.begin(), numbers_str.end(), cmp);
    
    for(auto& STR: numbers_str)
    {
        answer += STR;
    }
    
    if(answer[0] == '0') 
        return "0";
    
    return answer;
}