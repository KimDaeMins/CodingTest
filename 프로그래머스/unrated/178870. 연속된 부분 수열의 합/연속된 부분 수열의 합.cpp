#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(const pair<int, int>& a, const pair<int, int>& b)
{
    if(a.second - a.first < b.second - b.first)
    {
        return true;
    }
    else if((a.second - a.first) == (b.second - b.first))
    {
        return a.first<b.first;
    }
    return false;
}
vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    vector<pair<int, int>> v;
    int num = 0;
    //어떤방식이냐면 지렁이가듯이
    int left = 0;
    for(int right  = 0; right < sequence.size(); ++right)
    {
        num += sequence[right];
       
        while(num > k)
        {
            num -= sequence[left++];
        }
        
         if(num == k)
            v.push_back(pair<int, int>(left, right));
    }
   
    std::sort(v.begin(), v.end(), comp);
    answer.push_back(v[0].first);
    answer.push_back(v[0].second);
    return answer;
}