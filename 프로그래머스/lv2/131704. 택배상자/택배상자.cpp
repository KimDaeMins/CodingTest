#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    int inputCount = 0;
    stack<int> st;
    for(int i = 1; i <= order.size(); ++i)
    {
        if(order[inputCount] == i)
        {
            inputCount++;
        }
        else 
        {
            while(!st.empty() && st.top() == order[inputCount])
            {
                inputCount++;
                st.pop();
            }
            st.push(i);
        }
    }
    while(!st.empty() && st.top() == order[inputCount])
    {
        inputCount++;
        st.pop();
    }
    answer = inputCount;
    return answer;
}