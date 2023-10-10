#include <string>
#include <vector>

using namespace std;

/*
col : 데이터의 열을 의미합니다.
row : 데이터의 행을 의미합니다.
tuple : 데이터의 행 원소들의 집합입니다.
mod : 나머지 연산을 의미합니다. (5 mod 2 : 5를 2로 나누었을 경우 나머지)
xor : 비트 연산자 중에서 같은 자릿수의 비트가 서로 다를 경우 1, 같을 경우 0을 출력하는 연산자입니다.
누적 : 값을 순차적으로 더한 것을 의미합니다.
*/

//1. 벡터자체를 소팅할순 없다(직접 소팅을 만들어야함)
//2. 2번째 오름차순 연산은 해야한다.
//3. vector<vector<int>> 를 밸류로 담아둔 맵을 만들고
//?
//4. map<int,map<int,vector<vector<int>>>>????????
//5. 뭐 이미 값이 들어있다면 뒤에 넣으면 되는거 아님?
#include <map>
#include <iostream>
#include <algorithm>

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
	int answer = 0;
	map<int, map<int, vector<vector<int>>, greater<int>>> m;
	for (auto& v : data)
	{
		int second = v[col - 1];
		int first = v[0];
		if (m.find(second) == m.end())
		{
			m.emplace(second, map<int, vector<vector<int>>, greater<int>>());
		}
		if (m[second].find(first) == m[second].end())
		{
			m[second].emplace(first, vector<vector<int>>());
		}
		m[second][first].push_back(v);
	}
	int now = 0;
	vector<int> mods;
	for (auto& a : m)
	{
		for (auto& b : a.second)
		{
			for (auto& c : b.second)
			{
				++now;

				if (now >= row_begin && now <= row_end)
				{
					int sum = 0;
					for (int i = 0; i < c.size(); ++i)
					{
						sum += c[i] % now;
					}
					mods.push_back(sum);
				}
				else
					continue;
			}
			if (now >= row_end)
			{
				break;
			}
		}
		if (now >= row_end)
		{
			break;
		}
	}

	answer = mods[0];

	for (int i = 1; i < mods.size(); ++i)
	{
		answer ^= mods[i];
	}

	return answer;
}
