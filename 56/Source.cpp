#include <iostream>
#include <vector>
#include "../leetcode_misc/listcode_misc.h"
#include <string>
#include <queue>
#include <initializer_list>

using namespace std;

struct Interval
{
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
	Interval(initializer_list<int> l)
	{
		auto it = l.begin();
		start = *it;
		it++;
		end = *it;
	}

	friend ostream& operator<<(ostream& os, const Interval& v)
	{
		return os << "[" << v.start << ", " << v.end << "]";
	}
};

class Solution {
public:
	vector<Interval> merge(vector<Interval>& is)
	{
		if (is.size() < 2) return is;
		vector<Interval> non_connected;
		while (is.size() != 0)
		{
			size_t i = 0;
			Interval target = is.back();
			is.pop_back();
			while (i < is.size())
			{
				if (mergeable(target, is[i]))
				{
					target = merge_two(target, is[i]);
					swap_remove(is, i);
				}
				else
					i++;
			}
			non_connected.push_back(target);
		}
		return non_connected;
	}


private:

	template<typename T>
	static void swap_remove(vector<T>& container, size_t i)
	{
		if (i != container.size() - 1)
			container[i] = container.back();
		return container.pop_back();
	}

	static bool mergeable(const Interval& a, const Interval& b)
	{
		if (a.start <= b.start)
			return b.start <= a.end;
		return a.start <= b.end;
	}
	static Interval merge_two(const Interval& a, const Interval& b)
	{
		Interval i;
		if (a.start <= b.start)
			i.start = a.start;
		else
			i.start = b.start;
		i.end = max(a.end, b.end);
		return i;
	}
};

void test(vector<Interval> intervals)
{
	Solution so;
	cout << "Input: " << intervals << endl;
	cout << "Output: " << so.merge(intervals) << endl << endl;
}

int main()
{
	test({ {1,3},{2,6},{8,10},{15,18} });
	test({ {1,4},{0,2},{3,5} });
	test({ {1,4},{4,5} });
	test({ {1,4},{5,6} });
	test({ {4, 5},{1, 4},{0, 1} });
}