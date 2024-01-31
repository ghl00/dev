#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <unordered_map>
using namespace std;

int Index(string& str, string& sub, int pos)
{
	size_t strLen = str.length();
	size_t subLen = sub.length();
	int i = pos;

	while (i <= (strLen - subLen + 1))
	{
		string tmp = str.substr(i, subLen);
		if (sub == tmp)
			return i;
		else
			++i;
	}
	return -1;
}

int main()
{
	string str = "0123456789a3456fg";
	string sub = "3456";
	int index = Index(str, sub, -1);
	cout << index << endl;
	return 0;
}

