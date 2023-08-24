#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    int minIndex;
    int minValue =  INT32_MAX;
    for(int i = 0 ; i < arr.size(); ++i)
    {
        if(minValue > arr[i])
        {
            minIndex = i;
            minValue = arr[i];
        }
    }
    
    if(arr.size() == 1)
    {
        answer.push_back(-1);
    }
    else
    {
        for(int i = 0 ; i < arr.size(); ++i)
    {
        if(i != minIndex)
        {
            answer.push_back(arr[i]);
        }
    }
    }
    return answer;
}