#include <vector>
#include <string>
#include "../leetcode_misc/listcode_misc.h"

using namespace std;

class Solution
{
public:
	vector<string> fizzBuzz(int n)
	{
		vector<string> result;
		for (int i = 1; i <= n; i++)
		{
			string str="";
			if (i % 3 == 0)
				str += "Fizz";
			if (i % 5 == 0)
				str += "Buzz";
			if (str == "")str += to_string(i);
			result.push_back(str);
		}
		return result;
	}
};