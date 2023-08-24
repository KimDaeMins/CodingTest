#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    int arr[10] = {0,1, 2,3, 4, 5, 6 ,7 ,8 ,9};
    
    for(int i = 0; i < numbers.size(); ++i)
    {
        arr[numbers[i]] = 0;
    }
    for(int i = 1; i  < 10; ++i)
    {
        answer += arr[i];
    }
    if(answer == 0)
        answer = -1;
    return answer;
}