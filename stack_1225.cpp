#include <iostream>
#include <stack>
using namespace std;

void conversion()
{
	int N = 0;
	stack<int> s;
	cin >> N;
	while (N)
	{
		s.push(N % 8);
		N = N / 8;
	}

	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
}

int main()
{
	conversion();
	return 0;
}