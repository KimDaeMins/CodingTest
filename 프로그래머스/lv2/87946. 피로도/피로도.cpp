#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    
    sort(dungeons.begin(), dungeons.end());
    
    do{
        int check = 0;
        int temp = k;
        for(int i = 0; i < dungeons.size() && temp - dungeons[i][0] >= 0 ; ++ i)
        {
            temp -= dungeons[i][1];
            ++check;
        }
        
        if(answer < check)
        {
            answer = check;
        }
        
    }while(next_permutation(dungeons.begin(), dungeons.end()));
           
    return answer;
}