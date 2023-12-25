#include <iostream>
#include <string>
#include <stack>
using namespace std;

void BracketVerify()
{
	stack<char> s;
	string Brackets;
	cin >> Brackets;
	for (auto ch : Brackets)
	{
		char UrgentBracket = !s.empty() ? s.top() : ' ';
		if (ch == UrgentBracket + 1 ||
			ch == UrgentBracket - 1 ||
			ch == UrgentBracket + 2 ||
			ch == UrgentBracket - 2)
		{
			if (!s.empty())
			{
				s.pop();
			}
		}
		else
		{
			s.push(ch);
			UrgentBracket = ch;
		}
	}	
	cout << (s.empty() ? "Yes\n" : "No\n");
}

int main()
{
	BracketVerify();
	return 0;
}