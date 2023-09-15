#include <string>
#include <vector>

using namespace std;

void QuadTree(int startX, int startY, int endX, int endY, vector<vector<int>>* arr, vector<int>& answer)
{
    int firstNum = (*arr)[startY][startX];
    bool isAll = true;
    for (int i = startY; i < endY; ++i)
    {
        for (int j = startX; j < endX; ++j)
        {
            if (firstNum != (*arr)[i][j])
            {
                isAll = false;
                break;
            }
        }
        if (!isAll)
            break;
    }

    if (isAll)
    {
        answer[firstNum]++;
        return;
    }

    int midX = startX + (endX - startX) / 2;
    int midY = startY + (endY - startY) / 2;

    QuadTree(startX, startY, midX, midY, arr, answer);
    QuadTree(midX, startY, endX, midY, arr, answer);
    QuadTree(startX, midY, midX, endY, arr, answer);
    QuadTree(midX, midY, endX, endY, arr, answer);
}
vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);
    int startX = 0;
    int startY = 0;
    int endX = arr.size();
    int endY = arr.size();

    QuadTree(startX, startY, endX, endY, &arr, answer);

    int a = 0;

    return answer;
}