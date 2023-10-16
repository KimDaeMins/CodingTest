#include <string>
#include <vector>

using namespace std;

//그니까 음 1개면 3번부터시작 1회       13
//2개면 2번부터시작 3회                12 13 23
//3개면? 3번부터시작 7회               13 12 32 13 21 23 13 
//4개면? 2번부터 시작 15회겠지뭐        12 13 23 12 31 32 12 13 23 21 31 23 12 13 23
void Hanoi(int n, int now, int end, vector<vector<int>>& a)
{
	if (n == 1)
	{
		vector<int> b = { now, end };
		a.push_back(b);
		return;
	}
	//서브는 6 - now - end 헐
	Hanoi(n - 1, now, 6 - now - end, a);
	Hanoi(1, now, end, a);
	Hanoi(n - 1, 6 - now - end, end, a);

}
vector<vector<int>> solution(int n) {
	vector<vector<int>> answer;

	Hanoi(n, 1, 3, answer);

	return answer;
}
