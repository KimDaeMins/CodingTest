#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
void Test4(int v[])
{
	int sum = 0;
	for (int i = 0; i < 9; ++i)
		sum += v[i];

    vector<int> solve;
	for(int i = 0; i < 9; ++i)
		for (int j = 0; j < i; ++j)
		{
			if (sum - v[i] - v[j] == 100)
			{
				for (int k = 0; k < 9; ++k)
				{
					if (k != i && k != j)
						solve.push_back(v[k]);
				}
                
                sort(solve.begin(), solve.end());
                
                for (int a : solve)
				{
	                cout << a << endl;
				}
				return;
			}
		}
}
int main()
{
	int arr[9];
	for (int i = 0; i < 9; ++i)
		cin >> arr[i];
	Test4(arr);
	return 0;
}