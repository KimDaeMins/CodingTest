#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    
    vector<string> pb = phone_book;
    
    sort(pb.begin(), pb.end());
    
    for(size_t i = 0; i < pb.size() - 1; ++i)
    {
        string A = pb[i];
        string B = pb[i + 1];
        
        bool Check = false;
        for(size_t j = 0; j < A.size() && j < B.size() ; ++j)
        {
            if(A[j] != B[j])
            {
              Check = true;
              break;  
            }
        }
        
        if(!Check)
            return false;
    }
    return true;
}