#include <string>
#include <vector>
#include <random>
#include <iostream>
#include <cmath>
using namespace std;
//1.벡터를 정렬한다 시간순으로
//2.첫번째 정렬한 녀석의 endTime기준으로 갯수를 센다. x
//2.첫번째 녀석 기준으로 endTime을 세는데 더 짧은 녀석이 있으면 그걸 endTIme으로 한다 n*n
//-> 1000*1000 + sort
//1.24*60 -> 1440개의 배열을 만든다 -> 1440 * 1000 = 1440000+1440 ->이게제일 쉬워보이긴 하는데..
int solution(vector<vector<string>> book_time) {
    int answer = 0;
    int count[1450] = {};
    
    for(int i = 0; i < book_time.size(); ++i)
    {
       int startTime = stoi(book_time[i][0].substr(0, 2)) * 60 + stoi(book_time[i][0].substr(3, 2));
        int endTime =  stoi(book_time[i][1].substr(0, 2)) * 60 + stoi(book_time[i][1].substr(3, 2)) + 10;
        for(int j = startTime; j < endTime; ++j)
        {
            count[j]++;
        }
    }
    for(int i = 0; i < 1450; ++i)
    {
        answer = max(count[i], answer);
    }
    return answer;
}