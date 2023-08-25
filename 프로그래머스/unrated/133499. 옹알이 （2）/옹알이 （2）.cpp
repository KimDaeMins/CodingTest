#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    string a[4] = { "aya", "ye", "woo", "ma" };

    for (int i = 0; i < babbling.size(); ++i)
    {
         int beforeIndex = -1;
        int index = 0;
        while (true)
        {
            if (babbling[i].size() == index)
            {
                ++answer;
                break;
            }
            //사이즈는 7 인덱스는 0이라쳤을때 
            if (index + 2 <= babbling[i].size())
            {
                if (babbling[i].substr(index, 2) == "ye")
                {
                    if (beforeIndex == 1)
                        break;
                    beforeIndex = 1;
                    index += 2;
                }
                else if (babbling[i].substr(index, 2) == "ma")
                {
                    if (beforeIndex == 3)
                        break;
                    beforeIndex = 3;
                    index += 2;
                }
                else if (index + 3 <= babbling[i].size())
                {
                    if (babbling[i].substr(index, 3) == "aya")
                    {
                        if (beforeIndex == 0)
                            break;
                        beforeIndex = 0;
                        index += 3;
                    }
                    else if (babbling[i].substr(index, 3) == "woo")
                    {
                        if (beforeIndex == 2)
                            break;
                        beforeIndex = 2;
                        index += 3;
                    }
                    else
                        break;
                }
                else
                    break;
            }
            else
                break;

        }
    }
    return answer;
}