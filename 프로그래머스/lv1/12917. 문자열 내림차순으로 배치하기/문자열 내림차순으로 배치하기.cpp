#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    std::sort(s.begin(), s.end(), greater<char>());
    answer = s;
    return answer;
}