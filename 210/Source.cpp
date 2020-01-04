#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include "../leetcode_misc/listcode_misc.h"

using namespace std;

class Solution
{
	unordered_map<int, vector<int>> edges;
	bool topological_sort(vector<int>& result, unordered_set<int>& result_set, int course, unordered_set<int>& stack_)
	{
		if (stack_.count(course) != 0) return false;
		stack_.insert(course);
		if (edges.count(course) != 0)
			for (auto pre : edges.at(course))
				if (!topological_sort(result, result_set, pre, stack_)) return false;
		if (result_set.count(course) == 0)
		{
			result.push_back(course);
			result_set.insert(course);
		}
		stack_.erase(course);
		return true;
	}

public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites)
	{
		vector<int> result;
		unordered_set<int> set;
		unordered_set<int> stack_;
		for (auto pre : prerequisites)
			if (edges.count(pre.first) == 0)edges[pre.first] = { pre.second };
			else edges.at(pre.first).push_back(pre.second);
		for (int i = 0; i < numCourses; i++)
			topological_sort(result, set, i, stack_);
		if (result.size() != numCourses) return {};
		return result;
	}
};

void test(int numCourses, vector<pair<int, int>> prerequisites)
{
	Solution s;
	cout << "Input: " << numCourses << ", " << prerequisites << endl;
	cout << "Output: " << s.findOrder(numCourses, prerequisites) << endl;
}

int main()
{
	test(2, { {1,0} });
	test(4, { {1,0},{2,0},{3,1},{3,2} });
	test(2, { {0,1},{1,0} });
}