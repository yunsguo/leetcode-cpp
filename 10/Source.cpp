#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {

	struct expr
	{
		virtual bool match(const string& str, size_t& i) = 0;
		virtual ~expr() {}
	};

	struct concrete_char :public expr
	{
		concrete_char(char c) :c_(c) {}
		virtual bool match(const string& str, size_t& i) override {
			if (i >= str.size() || str[i] != c_) return false;
			i++;
			return true;
		}

	private:
		char c_;
	};

	struct any_char :public expr
	{
		virtual bool match(const string& str, size_t& i) override {
			if (i >= str.size()) return false;
			i++;
			return true;
		}
	};

	struct any_dctor :public expr
	{
		any_dctor() :ptr_(nullptr) {}
		any_dctor(expr* ptr) :ptr_(ptr) {}
		virtual bool match(const string& str, size_t& i) override {
			while (ptr_->match(str, i)) {}
			return true;
		}
		~any_dctor() { delete ptr_; ptr_ = nullptr; }

	private:
		expr* ptr_;

	};

public:
	bool isMatch(string s, string p) {
		size_t i = 0;
		size_t j = 0;
		return matching_rest(s, i, p, j);
	}

	bool matching_rest(const string& str, size_t i, const string& p,size_t j) {
		if (i == str.size() && j == p.size()) return true;
		if (j >= p.size()) return false;
		if (j + 1 >= p.size() || p[j + 1] != '*') {
			if (i >= str.size()) return false;
			if (p[j] == '.' || p[j] == str[i]) return matching_rest(str, i + 1, p, j + 1);
			return false;
		}
		expr* c = nullptr;
		if (p[j] == '.') c = new any_char();
		else c = new concrete_char(p[j]);
		auto prev_i = i;
		auto asterisk = new any_dctor(c);
		asterisk->match(str, i);
		if (j + 2 >= p.size() && i>=str.size()) return true;
		for (size_t k = prev_i; k <= i; k++)
			if (matching_rest(str, k, p, j + 2)) return true;
		return false;
	}
};

void test(string s, string p)
{
	cout << "s = \"" << s << "\" p = \"" << p << "\"\n";
	Solution so;
	cout << (so.isMatch(s, p) ? "true" : "false") << endl;
}

size_t main()
{
	test("aa", "a");
	test("aa", "a*");
	test("ab", ".*");
	test("aab", "c*a*b");
	test("mississippi", "mis*is*p*.");
	test("aaa", "a*a");
	test("a", "ab*");
	test("a", ".*..a*");
}