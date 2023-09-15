#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    //elements 의 i + 1을 더한수를 push_back
    int index = 0;
    int count = 1;
    int lock = elements.size();
    set<int> s;
    while(count < lock)
    {
        vector<int> temp;
        for(int i = 0; i < lock; ++i, ++index)
        {
            if(i + count >= lock)
                temp.push_back(elements[index] + elements[i + count - lock]);
            else
                temp.push_back(elements[index] + elements[i + count]);
        }
        
        for(int a : temp)
        {
            elements.push_back(a);
        }
        
        ++count;
    }
    for(int a : elements)
    {
        s.insert(a);
    }
    answer = s.size();
    return answer;
}