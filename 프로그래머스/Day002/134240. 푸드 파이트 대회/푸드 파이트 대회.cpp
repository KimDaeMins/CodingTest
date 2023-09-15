#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> food) {
    string answer = "0";
    
    
    for(int i = food.size() - 1; i > 0; --i)
    {
        int insert = food[i] / 2;
        char ch = *to_string(i).c_str();
        string a(insert * 2, *to_string(i).c_str());

        answer = a.substr(0, insert) + answer + a.substr(insert);
    }
    return answer;
}