#include <cmath>
using namespace std;

long long solution(int w, int h) {
    long long answer = 1;

    long long rect = (long long)w * h;

    //세로전체길이 * ( 지점  / 가로전체길이 ) 맞나요?

    long long beforeline = 0;
    for (int i = 1; i <= w; ++i)
    {
        long double mindouble = 0.0000000001;
        long double nextline = h * (i / (long double)w);
        long long next = nextline + mindouble;
        //소수가 존재하는지 판별하는법
        if (next == nextline 
            ||(next < nextline && next > nextline - mindouble)
            ||(next > nextline && next < nextline + mindouble))
        {
            rect -= next - beforeline;
        }
        else
        {
            rect -= next + 1 - beforeline;
        }
        beforeline = next;
    }
    answer = rect;
    return answer;
}