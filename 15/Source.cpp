#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

namespace std {

	template <>
	struct hash<tuple<size_t, size_t, size_t>>
	{
		std::size_t operator()(const tuple<size_t, size_t, size_t>& k) const
		{
			return ((hash<size_t>()(get<0>(k))
				^ (hash<size_t>()(get<1>(k)) << 1)) >> 1)
				^ (hash<size_t>()(get<2>(k)) << 1);
		}
	};

}
class Solution {
public:
	vector<vector<size_t>> threeSum(vector<size_t>& nums) {

		unordered_map<size_t, size_t> table;
		unordered_set<tuple<size_t, size_t, size_t>> set;
		vector<size_t> table2;
		vector<vector<size_t>> r;
		if (nums.size() < 3) return r;
		for (size_t i = 0; i < nums.size(); i++)
			if (table.count(nums[i]) == 0) { table[nums[i]] = 1; table2.push_back(nums[i]); }
			else table.at(nums[i])++;

		if (table.count(0)!=0 && table.at(0) >= 3) set.insert({ 0,0,0 });

		for (auto two_of : table2)
		{
			if (table.at(two_of) < 2) continue;
			auto target = 0 - two_of * 2;
			if (target!= two_of && table.count(target) != 0) order_and_insert(set, two_of, two_of, target);
		}
		if (table2.size() >= 3)
			for (size_t i = 0; i < table2.size() - 2; i++)
				for (size_t j = i + 1; j < table2.size() - 1; j++)
				{
					auto a = table2[i]; auto b = table2[j];
					auto target = 0 - a - b;
					if (target == a || target == b) continue;
					if (table.count(target) != 0) order_and_insert(set, a, b, target);
				}

		for (auto t : set)
			r.push_back({ get<0>(t),get<1>(t),get<2>(t) });
		return r;
	}

	void order_and_insert(unordered_set<tuple<size_t, size_t, size_t>>& set, size_t a, size_t b, size_t c)
	{
		if (c > b) swap(b, c);
		if (b > a) swap(a, b);
		if (c > b) swap(b, c);
		set.insert({ a,b,c });
	}
};

void display_vector(vector<size_t> array)
{
	if (array.size() != 0)
	{
		cout << "[" << array.front();
		for (size_t i = 1; i < array.size(); i++)
			cout << ", " << array[i];
		cout << "]" << endl;
		return;
	}
	cout << "[]" << endl;
}

void test(vector<size_t> array)
{
	Solution s;
	auto r = s.threeSum(array);
	cout << "3sum: ";
	display_vector(array);
	if (r.size() == 0) { cout << "no result" << endl << endl; return; }
	for (auto t : r)
		display_vector(t);
	cout << endl;
}

size_t main()
{
	test({ -1, 0, 1, 2, -1, -4 });
	test({});
	test({ 0,0,0 });
	test({ 1,1,-2});
	test({ 1,2,-2,-1 }); 
	test({ -1, 0, 1, 0 });
}