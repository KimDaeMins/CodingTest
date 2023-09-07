#include <string>
#include <vector>

using namespace std;
    int input[1001][1001] = {};

vector<int> solution(int n) {
    vector<int> answer;

    int mY[3] = {1, 0, -1};
    int mX[3] = {0, 1, -1};
    long count = 1;
    
    int size = n;
    if(n == 1)
    {
     answer.push_back(1);   
    }
    else if(n == 2)
    {
             answer.push_back(1);
             answer.push_back(2);
             answer.push_back(3);
    }
    else
    {
    for(int i = 0; i < size; ++i)
    {
        input[i][0] = count++;
    }
    for(int i = 1; i < size ; ++i)
    {
        input[size - 1][i] = count++;
    }
    for(int i = 1; i < size - 1; ++i)
    {
        input[size - 1 - i][size - 1 - i] = count++;
    }
    
    int nY = 1;
    int nX = 1;
    int dir = 0;
    while(true)
    {
        if(input[nY + mY[dir]][nX + mX[dir]] != 0)
        {
            ++dir;
            dir %= 3;
        }
        
        if(input[nY + mY[dir]][nX + mX[dir]] != 0)
            break;
        
        nY += mY[dir];
        nX += mX[dir];
        input[nY][nX] = count++;
    }
    
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j <= i; ++j)
        {
            answer.push_back(input[i][j]);
        }
    }
    }
    return answer;
}