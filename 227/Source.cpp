#include <string>
#include <tuple>
#include <iostream>

using namespace std;

class Solution
{
	using Monad = tuple<bool, int, size_t>;
	constexpr const static Monad failure = { false,-1,0 };

	struct PreOp
	{
		int val;
		int op;
		void carry(Monad& m)
		{
			int& number = get<1>(m);
			switch (op)
			{
			case '+':
				number += val;
				break;

			case '-':
				number = val - number;
				break;
			case '*':
				number *= val;
				break;
			case '/':
				number = val / number;
				break;
			}
		}
		PreOp(Monad first, Monad operation) :val(get<1>(first)), op(get<1>(operation)) {}
		PreOp() :val(0), op(-1) {}
	};

	static Monad number(const string& s, Monad m)
	{
		if (!get<0>(m) || get<2>(m) >= s.size()) return failure;
		if (get<2>(m) >= s.size()) return { false,get<1>(m),get<2>(m) };
		auto token = space(s, m);
		size_t i = get<2>(token);
		auto c = s[i];
		if (c > '9' || c < '0') return { false,get<1>(token),get<2>(token) };
		size_t j = i + 1;
		while (j < s.size() && s[j] <= '9' && s[j] >= '0')
			j++;
		return { true,stoi(s.substr(get<2>(token),j - i)),j };
	}
	static Monad space(const string& s, Monad m)
	{
		if (!get<0>(m) || get<2>(m) >= s.size()) return m;
		size_t i = get<2>(m);
		if (s[i] != ' ')return m;
		size_t j = i + 1;
		while (j < s.size() && s[j] == ' ')
			j++;
		return { true,0,j };
	}


	static Monad operation(const string& s, Monad m)
	{
		if (!get<0>(m)) return m;
		if (get<2>(m) >= s.size()) return { false,get<1>(m),get<2>(m) };
		auto token = space(s, m);
		size_t i = get<2>(token);
		char c = s[i];
		if (c != '+' && c != '-'&&c != '*'&&c != '/')
			return { false,0,i };
		return { true,c,i + 1 };
	}

	static Monad term(const string& s, Monad m)
	{
		if (!get<0>(m) || get<2>(m) >= s.size()) return failure;
		auto first = number(s, m);
		if (!get<0>(first)) return failure;
		auto the_rest = term_chunk(s, first);
		if (!get<0>(the_rest)) return first;
		return the_rest;
	}

	static Monad term_chunk(const string& s, Monad m)
	{
		if (!get<0>(m) || get<2>(m) >= s.size()) return failure;
		auto op = operation(s, m);
		auto symbol = get<1>(op);
		if (!get<0>(op) || symbol == '+' || symbol == '-') return failure;
		auto second = number(s, op);
		if (!get<0>(second)) return failure;
		return { true,symbol == '*' ? get<1>(m)*get<1>(second) : get<1>(m) / get<1>(second),get<2>(second) };
	}

public:
	int calculate(string s)
	{
		PreOp prev;
		Monad m = { true,0,0 };
		while (true)
		{
			if (get<2>(m) >= s.size()) break;
			auto first = term(s, m);
			if (!get<0>(first)) break;
			m = first;
			while (true)
			{
				auto next = term_chunk(s, m);
				if (!get<0>(next)) break;
				m = next;
			}
			prev.carry(m);
			auto op = operation(s, m);
			auto symbol = get<1>(op);
			if (!get<0>(op) || symbol == '*' || symbol == '/') break;
			prev = PreOp(m, op);
			m = op;
		}
		return get<1>(m);
	}
};

void test(string str)
{
	cout << "Input: " << str << endl;
	Solution s;
	cout << "Output: " << s.calculate(str) << endl;
}

int main(int argc, char *argv[])
{
	test("3+2*2");
	test(" 3/2 ");
	test(" 3+5 / 2 ");
	test("100000000/1/2/3/4/5/6/7/8/9/10");
	while (true)
	{
		string temp = "";
		cin >> temp;
		if (temp == "exit") break;
		test(temp);
	}
}