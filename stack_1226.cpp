#include <iostream>
#include <string>
#include <stack>
using namespace std;

void LineEdit()
{
	stack<char> s;
	char ch = getchar();
	while (ch != EOF)
	{
		while (ch != EOF && ch != '\n')
		{
			switch (ch) 
			{
			case '#':
				if (!s.empty())
					s.pop();
				break;
			case '@':
				while (!s.empty())
					s.pop();
				break;
			default:
				s.push(ch);
				break;
			}
			ch = getchar();
		}

		string str;
		auto it = str.begin();
		while (!s.empty())
		{
			//it always point to first element position
			str.insert(it, s.top());
			s.pop();
		}
		cout << str << "\n";
		if (ch != EOF)
			ch = getchar();
	}
}

int main()
{
	LineEdit();
	return 0;
}
