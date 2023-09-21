#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

//dp로 풀면 좀더 이쁘다 라는거
unordered_map<int, int> map;
vector<int> vec;
long long Combi(vector<int> a, int start)
{
	if (a.size() == 2)
	{
		//4 - 2 4 - 3 3 - 2
		//2배 4/3배 1.5배
		if (a[0] * 2 == a[1]
			|| a[0] * 4 == a[1] * 3
			|| a[0] * 3  == a[1] * 2)
			return map[a[0]] * map[a[1]];
		return 0;
	}

	long long num = 0;
	for (int i = start + 1; i < vec.size(); ++i)
	{
		a.push_back(vec[i]);
		num += Combi(a, i);
		a.pop_back();
	}
	return num;
}
long long solution(vector<int> weights) {
	long long answer = 0;
	vector<int> a;
	for (int i : weights)
	{
		map[i]++;
		if (map[i] == 1)
			vec.push_back(i);
	}
	
	sort(vec.begin(), vec.end());
	answer = Combi(a, -1);
	
	int maxNum = 1;
	for (auto p : map)
	{
		if (p.second > maxNum)
		{
			maxNum = p.second;
		}
	}

	vector<long long> b;
	b.resize(maxNum);
	b[0] = 0;
	for (int i = 1; i < maxNum; ++i)
	{
		b[i] = b[i - 1] + i;
	}
	for (auto p : map)
	{
		answer += b[p.second - 1];
	}
	return answer;
}