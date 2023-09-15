#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
bool cmp(const pair<int,int>& a, const pair<int,int>& b) 
{
    //비교함수는 true일때 그대로 false일때 돌린다
	return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    //처음엔 dp ㄴㄴ 그뭐냐그게 괜찮지않을까 싶었지.
    //왜냐? 만다린의 종류가 제일 많은 녀석을 찾았어야하니까.
    //근데 원소가 천만개네? 버틸수있을까? 그건 모르는거지
    //그래서 맵을 쓰기로 했다.
    map<int, int> a;
    
    for(int i = 0; i < tangerine.size(); ++i)
    {
        a[tangerine[i]]++; 
    }
    
    //밸류값으로 맵을 정렬하는건 말이안되나? 어렵나?
    vector<pair<int,int>> v(a.begin(), a.end());
    
    sort(v.begin(), v.end(), cmp);
    
    int index = 0;
    while(k > 0)
    {
        k -= v[index].second;
        ++index;
    }
    answer = index;
    
    return answer;
}