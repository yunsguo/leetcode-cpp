#include <string>

using std::string;

class Solution {
public:
	bool isPalindrome(string s) {
		size_t i = 0;
		size_t j = s.length() - 1;
		auto max = s.length();
		while (i<max && i<j)
		{
			if (isalnum(s[i]))
			{
				if (isalnum(s[j]))
				{
					if (tolower(s[i]) != tolower(s[j])) return false;
					i++; j--;
					continue;
				}
				else
				{
					j--;
					continue;
				}
			}
			else
			{
				i++;
				continue;
			}
		}
		return true;
	}
};

size_t main()
{
	Solution s;
	s.isPalindrome("race a car");
}