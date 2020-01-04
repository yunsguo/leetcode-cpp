#include <unordered_set>
#include <unordered_map>
#include <iostream>

// Forward declaration of the knows API.
bool knows(int a, int b);

using namespace std;

class Solution
{
	template<typename P, typename T>
	static void filter(unordered_set<T>& set, P p)
	{
		auto it = set.begin();
		while (it != set.end()) {
			if (p(*it)) it++;
			else it = set.erase(it);
		}
	}

public:
	int findCelebrity(int n)
	{
		unordered_set<int> candidates;
		unordered_map<int, bool> knows_result;
		for (int i = 0; i < n; i++)
			candidates.insert(i);
		for (int i = 0; i < n; i++)
		{
			filter(candidates, [&](int c) {
				if (i == c) return true;
				bool result = knows(i, c);
				knows_result[i*n + c] = result;
				if (result)
					return true;
				return false;
			});
		}
		filter(candidates, [&](int c) {
			for (int i = 0; i < n; i++)
				if (i == c) continue;
				else
				{
					bool result;
					if (knows_result.count(c*n + i) != 0)result = knows_result.at(c*n + i);
					else result = knows(c, i);
					if (result) return false;
				}
			return true;
		});
		if (candidates.size() == 1) return *candidates.cbegin();
		return -1;
	}
};