#include <vector>
#include <iostream>
#include "../leetcode_misc/listcode_misc.h"

using namespace std;

class Solution
{
	static bool is_conflicted(const vector<int>& i1, const vector<int>& i2)
	{
		if (i1[0] > i2[0]) return is_conflicted(i2, i1);
		if (i2[0] >= i1[0] && i2[0] < i1[1]) return true;
		if (i2[1] > i1[0] && i2[1] <= i1[1]) return true;
		return false;
	}

	static bool insert(vector<vector<int>>& room, const vector<int>& i)
	{
		for (auto& interval : room)
			if (is_conflicted(interval, i)) return false;
		room.push_back(i);
		return true;
	}
	template<typename T>
	static void quick_remove(vector<T>& v, size_t i)
	{
		if (i + 1 != v.size()) swap(v[i], v.back());
		v.pop_back();
	}

	static void mmr_impl(vector<vector<int>>& intervals, size_t& min)
	{
		if (intervals.size() == 0) return;
		vector<vector<int>> container;
		size_t i = 0;
		while (i < intervals.size())
		{
			if (insert(container, intervals[i]))
				quick_remove(intervals, i);
			else i++;
		}
		min++;
		mmr_impl(intervals, min);
	}

public:
	int minMeetingRooms(vector<vector<int>>& intervals)
	{
		int min = 0;
		if (intervals.size() == 0) return min;
		while (intervals.size()!=0)
		{
			vector<vector<int>> container;
			size_t i = 0;
			while (i < intervals.size())
			{
				if (insert(container, intervals[i]))
					quick_remove(intervals, i);
				else i++;
			}
			min++;
		}
		return min;
	}
};

void test(vector<vector<int>> intervals)
{
	cout << "Input: " << intervals << endl;
	Solution s;
	cout << "Output: " << s.minMeetingRooms(intervals) << endl;
}

int main()
{
	test({ {0,30},{5,10},{15,20} });
	test({ {7,10},{2,4} });
	test({ {13,15},{1,13},{6,9} });
}