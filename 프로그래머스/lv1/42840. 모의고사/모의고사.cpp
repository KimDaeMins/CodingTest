#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//문제를 잘 읽자!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int a[5] = {1,2,3,4,5};
    int b[8] = {2,1,2,3,2,4,2,5};
    int c[10] = {3,3,1,1,2,2,4,4,5,5};
    int Correct[3] = {0, 0, 0};
    
    for(int i = 0; i < answers.size(); ++i)
    {
        if(a[i%5] == answers[i]) 
            ++Correct[0];
        if(b[i%8] == answers[i]) 
            ++Correct[1];
        if(c[i%10] == answers[i])
            ++Correct[2];
    }
    
    int max = *max_element(Correct, Correct+3);
    
    for(int i = 0; i < 3; ++i)
    {
        if(Correct[i] == max) 
            answer.push_back(i + 1);
    }
    return answer;
}