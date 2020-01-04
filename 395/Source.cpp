#include <string>

using namespace std;

class Solution
{

	int ls_impl(const string& str, size_t start, size_t end, int k)
	{

	}

public:
	int longestSubstring(string s, int k)
	{
		if (k <= 1) return s.size();
		return ls_impl(s, 0, s.size() - 1, k);
	}
};