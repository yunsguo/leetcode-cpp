#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <iostream>
#include "../leetcode_misc/listcode_misc.h"

using namespace std;

class Solution
{
	unordered_map<int, vector<int>> edges;
	unordered_set<int> schedule;

	bool can_finishs_this(int course, unordered_set<int> targets, vector<int>& temp_schedule)
	{
		if (schedule.count(course) != 0) return true;
		if (targets.count(course) != 0) return false;
		targets.insert(course);
		temp_schedule.push_back(course);
		if (edges.count(course) != 0)
			for (auto next : edges.at(course))
				if (!can_finishs_this(next, targets, temp_schedule)) return false;
		return true;
	}

public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites)
	{
		edges.clear();
		for (auto pair : prerequisites)
			if (edges.count(pair.first) == 0) edges[pair.first] = { pair.second };
			else edges.at(pair.first).push_back(pair.second);

		for (int i = 0; i < numCourses; i++)
		{
			unordered_set<int> stack;
			vector<int> temp;
			if (!can_finishs_this(i, stack, temp)) return false;
			for (auto c : temp)
				schedule.insert(c);
		}
		return true;
	}
};

void test(int numCourses, vector<pair<int, int>> prerequisites)
{
	Solution s;
	cout << "Input: " << numCourses << ", " << prerequisites << endl;
	cout << "Output: " << s.canFinish(numCourses, prerequisites) << endl;
}

int main()
{
	test(2, { {1,0} });
	test(2, { {1,0},{0,1} });
	test(3, { {0,1},{0,2},{1,2} });
	test(3, { {1,0},{1,2},{0,1} });
	test(4, { {2, 0}, {1, 0}, {3, 1}, {3, 2}, {1, 3} });
}