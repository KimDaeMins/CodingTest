#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    int arr[26] = {};
    std::fill(arr, arr + 26, 9999);
    int Input = 0;
    int secondInput = 0;
    for (string a : keymap)
    {
        for (int i = 0; i < a.size(); ++i)
        {
            arr[a[i] - 'A'] = min(arr[a[i] - 'A'], i + 1);
        }
    }
    for (string a : targets)
    {
        bool isNone = false;
        for (int i = 0; i < a.size(); ++i)
        {
            Input += arr[a[i] - 'A'];
            if (arr[a[i] - 'A'] == 9999)
            {
                answer.push_back(-1);
                isNone = true;
                break;
            }
        }
        if (!isNone)
            answer.push_back(Input);
        Input = 0;
    }
    return answer;
}