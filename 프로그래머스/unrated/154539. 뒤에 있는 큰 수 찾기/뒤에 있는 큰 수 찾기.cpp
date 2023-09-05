#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    answer.resize(numbers.size(), -1);
    stack<pair<int, int>> st;
    
    st.push(pair<int,int>(0, numbers[0]));
    for(int i = 1; i < numbers.size(); ++i)
    {
        while(!st.empty() && numbers[i] > st.top().second)
        {
            answer[st.top().first] = numbers[i];
            st.pop();
        }
        st.push(pair<int, int> (i, numbers[i]));
    }
  
    return answer;
}