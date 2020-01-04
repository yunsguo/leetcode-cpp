#include <vector>
#include <string> 
#include <iostream>
#include <stack>

#include "../leetcode_misc/listcode_misc.h"

using namespace std;


//class Solution
//{
//	size_t surface;
//	int eval_impl(const vector<string>& tokens)
//	{
//		auto index = surface;
//		surface--;
//		char first = tokens[index].front();
//
//		if (first >= '0' && first <= '9' || first == '-' &&tokens[index].size() != 1) return stoi(tokens[index]);
//		int b = eval_impl(tokens);
//		int a = eval_impl(tokens);
//		switch (first)
//		{
//		case '+':
//			return a + b;
//		case '-':
//			return a - b;
//		case '*':
//			return a * b;
//		case '/':
//			return a / b;
//		}
//		return -1;
//	}
//public:
//	int evalRPN(vector<string>& tokens)
//	{
//		surface = tokens.size() - 1;
//		return eval_impl(tokens);
//	}
//};

class Solution
{
public:
	int evalRPN(vector<string>& tokens)
	{
		stack<int> s_;
		auto itor = tokens.cbegin();
		while (itor!=tokens.cend())
		{
			char first = itor->front();
			if (itor->size() == 1 && first < '0')
			{
				int b = s_.top();
				s_.pop();
				int a = s_.top();
				s_.pop();
				switch (first)
				{
				case '+':
					s_.push(a + b); break;
				case '-':
					s_.push(a - b); break;
				case '*':
					s_.push(a*b); break;
				case '/':
					s_.push(a / b); break;
				}
			}
			else
				s_.push(stoi(*itor));
			itor++;
		}
		return s_.top();
	}
};

void test(vector<string> tokens)
{
	Solution s;
	cout
		<< "Input: " << tokens << endl
		<< "Output: " << s.evalRPN(tokens) << endl;

}

int main()
{
	test({ "2", "1", "+", "3", "*" });
	test({ "3","-4","+" });
	test({ "4","13","5","/","+" });
}