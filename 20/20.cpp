// 20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <vector>
#include <algorithm>
#include <iostream>
#include "../util/util.h"
#include <unordered_set>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		vector<char> stack;
		for (char c : s) {
			switch (c) {
			case '{':
			case '[':
			case '(':
				stack.push_back(c);
				break;
			case '}':
				if (stack.size() == 0 || stack.back() != '{') return false;
				stack.pop_back();
				break;
			case ']':
				if (stack.size() == 0 || stack.back() != '[') return false;
				stack.pop_back();
				break;
			case ')':
				if (stack.size() == 0 || stack.back() != '(') return false;
				stack.pop_back();
				break;
			default:
				return false;
			}
		}
		return stack.size() == 0;
	}
};

int main()
{
	std::cout << "Hello World!\n";
	Solution s;
	cout << s.isValid("()") << endl;
	cout << s.isValid("]") << endl;
	cout << s.isValid("()[]{}") << endl;
	cout << s.isValid("(]") << endl;
	cout << s.isValid("([)]") << endl;
	cout << s.isValid("{[]}") << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
