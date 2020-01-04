#include <iostream>
#include <vector>
#include "../leetcode_misc/listcode_misc.h"
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> r;
		auto& t = table();
		auto n = nums.size();
		if (t.count(n) == 0) populate(n);
		auto set = t.at(n);
		for (auto p : set)
		{
			vector<int> temp(n);
			for (size_t i = 0; i < n; i++)
				temp[p[i]] = nums[i];
			r.push_back(temp);
		}
		return r;
	}

	static unordered_map<size_t, vector<vector<size_t>>>& table()
	{
		static unordered_map<size_t, vector<vector<size_t>>> m;
		return m;
	}

	static void populate(size_t n)
	{
		auto& t = table();
		if (n == 1)
		{
			if (t.count(1) == 0)
				t[1] = { {0} };
			return;
		}
		if (t.count(n - 1) == 0) populate(n - 1);
		auto prev = t.at(n - 1);
		vector<vector<size_t>> curr;
		for (auto p : prev)
		{
			for (size_t i = 0; i < p.size(); i++)
			{
				auto p_temp = p;
				p_temp.insert(p_temp.begin() + i, n - 1);
				curr.push_back(p_temp);
			}
			auto p_last = p;
			p_last.push_back(n - 1);
			curr.push_back(p_last);
		}
		t[n] = curr;
	}
};

void test(vector<int> nums)
{
	Solution so;
	cout
		<< "Input: " << nums << endl;
	cout << "Output: " << so.permute(nums) << endl << endl;
}

int main()
{
	Solution s;
	s.populate(5);
	cout << s.table().at(5) << endl;
	test({ 1,2,3 });
}