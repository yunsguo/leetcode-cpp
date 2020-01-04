#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) 
	{
		unordered_set<int> set;
		for (auto n : nums)
			if (set.count(n) != 0) return true;
			else set.insert(n);
		return false;
	}
};