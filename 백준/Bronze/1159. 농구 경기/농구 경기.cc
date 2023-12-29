#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string BasketBall(vector<string> a)
{
	//퍼스트워드가 키값인데 안에 배열의 숫자가 들어있음
	map<char, vector<int>> m;
	string out = "";
	for (int i = 0; i < a.size(); ++i)
	{
		map<char, vector<int>>::iterator iter = m.find(a[i][0]);
		if (iter == m.end())
		{
			vector<int> v;
			v.push_back(i);
			m.emplace(a[i][0], v);
		}
		else
		{
			iter->second.push_back(i);
			if (iter->second.size() == 5)
				out += iter->first;
		}
	}

	if (out.length() > 0)
	{
		sort(out.begin(), out.end());
		return out;
	}
	else
	{
		return "PREDAJA";
	}
}
int main()
{
	int a = 0;
	cin >> a;
	vector<string> b;

	for (int i = 0; i < a; ++i)
	{
		string c;
		cin >> c;
		b.push_back(c);
	}
	cout << BasketBall(b) << endl;
	return 0;
}