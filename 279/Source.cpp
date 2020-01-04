#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
	static vector<int> squares;
	static unordered_map<int, int> cache;
	static int ns_impl(int n)
	{
		if (cache.count(n) != 0) return cache.at(n);
		while (true)
		{
			int ss = squares.size();
			if (ss*ss >= n) break;
			ss++;
			squares.push_back(ss*ss);
		}
		int min = INT32_MAX;
		for (auto square : squares)
		{
			if (square >= n)
			{
				if (square == n)
				{
					cache[n] = 1; return 1;
				}
				break;
			}
			auto temp = ns_impl(n - square) + 1;
			if (temp < min)
				min = temp;
		}
		cache[n] = min;
		return min;
	}
public:
	int numSquares(int n) {
		return ns_impl(n);
	}
};

vector<int> Solution::squares = vector<int>();
unordered_map<int, int> Solution::cache = unordered_map<int, int>();

void test(int n)
{
	cout << "Input: " << n << endl;
	Solution s;
	cout << "Output: " << s.numSquares(n) << endl;
}

int main()
{
	for (int i = 1; i < 24; i++)
		test(i);
}