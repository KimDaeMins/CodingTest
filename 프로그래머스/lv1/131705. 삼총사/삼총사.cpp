#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
int combi(int start, vector<int> num, vector<int> b, int n, int k)
{
    if (b.size() == k)
    {
        if (num[b[0]] + num[b[1]] + num[b[2]] == 0)
            return 1;
        return 0;
    }

    int number = 0;
    for (int i = start + 1; i < n; i++)
    {
        b.push_back(i);
        number += combi(i, num, b, n, k);
        b.pop_back();
    }
    return number;
}

int solution(vector<int> number) {
    int answer = 0;
    vector<int> b;
    answer = combi(-1, number, b, number.size(), 3);
    return answer;
}