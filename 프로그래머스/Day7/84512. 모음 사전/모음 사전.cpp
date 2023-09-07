#include <string>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

//내가 생각한 해결방안
//내가 쓴 단어 갯수를 구한다. -> 연관성을 찾는다
//A AA AAA AAAA AAAAA AAAAE AAAAI AAAAO AAAAU
//AAAE AAAEA AAAEE AAAEI AAAEO AAAEU
//AAAI AAAIA AAAIE AAAII AAAIO AAAIU
//AAAO AAAOA AAAOE AAAOI AAAOO AAAOU
//AAAU AAAUA AAAUE AAAUI AAAUO AAAUU
//AAE AAEA AAEAA AAEAE AAEAI AAEAO AAEAU
//AAEE AAEEA AAEEE AAEEI AAEEO AAEEU
//모르겠다

//모범답안?
//사전을 직접 만든다.
//내 글자랑 비교한다

void Input(int _maxLen, string _s, string _t[], vector<string>* _v)
{
    if(_maxLen == _s.size())
    {
        _v->push_back(_s);
        return;
    }
    
    for(int i = 0 ; i < 5; ++i)
    {
        Input(_maxLen, _s + _t[i], _t, _v);
    }
}
int solution(string word) {
    int answer = 0;
    string t[5] = {"A", "E" , "I", "O" , "U"}; 
    vector<string> v;
    
    for(int i = 0; i < 5; ++i)
    {
        Input(i + 1, "", t, &v);
    }
    
    // 사전 순으로 정렬한다 문자열 소팅
    sort(v.begin(), v.end());

    answer = find(v.begin(), v.end(), word) - v.begin() + 1;
    return answer;
}