#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    stack<int> st;
    stack<int> pst;

    for (int i : ingredient)
    {
        st.push(i);

        if (st.size() >= 4 && st.top() == 1)
        {
            pst.push(st.top());
            st.pop();
            if (st.top() == 3)
            {
                pst.push(st.top());
                st.pop();
                if (st.top() == 2)
                {
                    pst.push(st.top());
                    st.pop();
                    if (st.top() == 1)
                    {
                        stack<int> t;
                        pst.swap(t);
                        st.pop();
                        ++answer;
                    }
                }
            }

            while (!pst.empty())
            {
                st.push(pst.top());
                pst.pop();
            }
        }

    }

    return answer;
}