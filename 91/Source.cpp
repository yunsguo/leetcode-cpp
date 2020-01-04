#include <iostream>
#include <exception>
#include <string>

using namespace std;

class Solution
{
public:
	static bool consumable(char c)
	{
		return c != '0';
	}

	static bool consumable(char a, char b)
	{
		int num = (a - '0') * 10 + b - '0';
		return num >= 10 && num <= 26;
	}

	static int NDImpl(string s, int start) {
		int end = s.length();
		if (end - start == 1) {
			if (consumable(s[start]))
				return 1;
			return 0;
		}
		char a = s[start];
		char b = s[start + 1];
		char scenario = 0;
		scenario += consumable(a) ? 1 : 0;
		scenario += consumable(b) ? 2 : 0;
		scenario += consumable(a, b) ? 4 : 0;
		if (end - start == 2)
		{
			switch (scenario)
			{
			case 0:
			case 1:
			case 2:
				return 0;
			case 3:
			case 4:
			case 5:
			case 6:
				return 1;
			case 7:
				return 2;
			}
		}
		switch (scenario)
		{
		case 0:
		case 1:
		case 2:
			return 0;
		case 3:
			return NDImpl(s, start + 1);
		case 4:
		case 5:
		case 6:
			return NDImpl(s, start + 2);
		case 7:
			return NDImpl(s, start + 1) + NDImpl(s, start + 2);
		}
		return -1;
	}

	int numDecodings(string s) {
		return NDImpl(s, 0);
	}
};

int main()
{
	Solution s;
	string str = "9371597631128776948387197132267188677349946742344217846154932859125134924241649584251978418763151253";
	cout << "input: " << str << endl;
	cout << "output: " << s.numDecodings(str) << endl;
};
