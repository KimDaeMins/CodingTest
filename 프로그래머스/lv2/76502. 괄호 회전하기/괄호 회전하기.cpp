#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

//1칸회전 왼쪽부터 탐색 -> 반복..?
int solution(string s) {
    int answer = 0;

    for (int i = 0; i < s.size(); ++i)
    {
        stack<char> st;
        for (int j = s.size() - 1; j >= 0; --j)
        {
            st.push(s[j]);
        }
        stack<char> temp;
        while (!st.empty())
        {
            temp.push(st.top());
            st.pop();

            while (!st.empty() && !temp.empty())
            {
                if ((st.top() == ']' && temp.top() == '[')
                    || (st.top() == '}' && temp.top() == '{')
                    || (st.top() == ')' && temp.top() == '('))
                {
                    st.pop();
                    temp.pop();
                }
                else
                    break;
            }
        }
        if (temp.empty())
            ++answer;
        //문자열 회전..
        string stemp = s.substr(1);
        char stemp2 = s[0];
        s = stemp + stemp2;
    }
    return answer;
}