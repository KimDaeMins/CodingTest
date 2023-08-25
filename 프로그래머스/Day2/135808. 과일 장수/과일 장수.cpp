#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, int m, vector<int> score) {
    long answer = 0;
    vector<int> a(k + 1, 0);
    int count = 0;
    for (int b : score)
    {
        ++a[b];
        ++count;
    }

    int index = k;
    while (count >= m)
    {
        int c = m;
        while (a[index] > 0)
        {
            a[index] -= c;
            if (a[index] < 0)
            {
                c = -a[index];
            }
            else
            {
                c = m;
                answer += index * m;
                count -= m;
                if (count < m)
                    break;
            }
            while (a[index] <= 0)
            {
                --index;
            }
        }
    }
    return answer;
}