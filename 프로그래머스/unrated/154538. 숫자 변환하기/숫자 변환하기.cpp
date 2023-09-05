#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
//그니까 내 논리는 이거야 
//특정숫자에 도달했어 3가지방법으로
//그랬을때 그녀석의 인덱스를 숫자로 저장해
//
int ys[1000001] = {};
void Search(int y, int count, int n, int x)
{
    if(y <= x)
        return;
    
    if(y % 3 == 0)
    {
        ys[y / 3] = min(count, ys[y / 3]);
        if(ys[y / 3] == count)
            Search(y / 3, count + 1, n , x);
    }
    if(y % 2 == 0)
    {
        ys[y / 2] = min(count, ys[y / 2]);
        if(ys[y / 2] == count)
            Search(y / 2, count + 1, n , x);
    }
    if(y - n >= x)
    {
        ys[y - n] = min(count, ys[y - n]);
        if(ys[y - n] == count)
            Search(y - n, count + 1, n , x);
    }   
}
int solution(int x, int y, int n) {
    int answer = 0;

    if(x == y)
        return 0;
    fill(ys, ys + 1000001, 99999);
    
    Search(y, 1 , n, x);
    if(ys[x] == 99999)
        answer = -1;
    else
        answer = ys[x];
    
    return answer;
}