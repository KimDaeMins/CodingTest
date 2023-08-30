#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);

    string str = s;
    while (str.size() != 1)
    {
        ++answer[0];

        int length = str.size();
        str.erase(std::remove(str.begin(), str.end(), '0'), str.end());
        int removeLength = str.size();
        answer[1] += length - removeLength;

        str = "";
        while (removeLength != 0)
        {
            str += to_string(removeLength % 2);
            removeLength /= 2;
        }
        reverse(str.begin(), str.end());
    }

    return answer;
}
