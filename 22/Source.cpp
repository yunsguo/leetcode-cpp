#include <vector>
#include <forward_list>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:

	vector<string> generateParenthesis(size_t n) {
		forward_list<state> stack;
		stack.push_front(state());
		vector<string> r;
		while (!stack.empty())
			operate(stack, r, n);
		return r;
	}

private:

	struct state
	{
		state() :open(0), close(0), p_("") {}

		void add_open() {
			open++;
			p_ += '(';
		}

		void add_close() {
			close++;
			p_ += ')';
		}

		void finish() {
			while (close !=open)
				add_close();
		}
		size_t open;
		size_t close;
		string p_;
	};

	static void operate(forward_list<state>& stack, vector<string>& container, size_t n)
	{
		auto& s = stack.front();
		if (s.open == n)
		{
			s.finish();
			container.push_back(s.p_);
			stack.pop_front();
			return;
		}
		if (s.open == s.close)
		{
			s.add_open();
			return operate(stack, container, n);
		}

		auto branch = s;
		s.add_open();
		branch.add_close();
		stack.push_front(branch);
	}
};

void test(size_t n)
{
	Solution s;
	auto r = s.generateParenthesis(n);
	cout << "while n = " << n << endl;
	for (auto s : r)
		cout << s << endl;
	cout << endl;
}

size_t main()
{
	test(1);
	test(3);
}