#include <iostream>


class Solution {
public:
	int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
		int b = minutesToTest / minutesToDie + 1;
		int e = (int)(log(buckets) / log(b));
		if (pow(b, e) >= buckets)
			return e;
		return e + 1;
	}
};



int main()
{
	Solution s;
	std::cout << s.poorPigs(1000, 15, 15) << std::endl;
};