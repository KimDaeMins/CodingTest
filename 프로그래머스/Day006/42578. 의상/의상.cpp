#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    
    unordered_map<string, int> Wears;
    for(auto& VEC : clothes)
    {
        Wears[VEC[1]] += 1;
    }
    int Kinds = Wears.size();
    int answer = 1;
    for(auto& Pair : Wears)
    {
        answer *= (Pair.second + 1);
    }
    return answer - 1;
}
