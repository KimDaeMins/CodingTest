#include <string>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<int, int> m;
    for(int i = 0; i < records.size(); ++i)
    {
        int num = stoi(records[i].substr(0, 2)) * 60;
        num += stoi(records[i].substr(3, 2));
        int carnum = stoi(records[i].substr(6, 4));
        string inout = records[i].substr(11);
        
        if(inout == "IN")
        {
            m[carnum] -= num;
        }
        else
        {
            m[carnum] += num;
        }
    }
    
    for(auto p : m)
    {
        if(p.second <= 0)
            p.second += 23 * 60 + 59; 
        if(p.second - fees[0] < 0)
        {
             answer.push_back(fees[1]);
        }
        else
        {
            if((p.second - fees[0]) % fees[2])
                answer.push_back(fees[1] + max(0, p.second - fees[0]) / fees[2] * fees[3] + fees[3]);
            else
                answer.push_back(fees[1] + max(0, p.second - fees[0]) / fees[2] * fees[3]);           
              
        }
       
    }
    return answer;
}