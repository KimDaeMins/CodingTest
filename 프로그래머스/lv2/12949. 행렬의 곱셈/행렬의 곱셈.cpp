#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    //arr1의 행과 arr2의 열이 같아야함
    //arr1의 행과 arr2의 열의 크기만큼 answer의 크기가 나올거임
    //열은 세로고 행은 가로임
    
    for(int i = 0; i < arr1.size(); ++i)//열
    {
        answer.push_back(vector<int>());
        
        for(int j = 0; j < arr2[0].size(); ++j)
        {
            //j행 i열 = 
            int sum = 0;
            for(int k = 0; k < arr2.size(); ++k)
            {
                sum += arr1[i][k] * arr2[k][j];
            }
            answer[i].push_back(sum);
        }
    }
    return answer;
}