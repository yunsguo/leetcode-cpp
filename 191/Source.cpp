#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	size_t hammingWeight(uint32_t n) {
		if (n == 0) return 0;
		return (n & 1) + hammingWeight(n >> 1);
	}
};

size_t main()
{
	Solution s;

	cout << s.hammingWeight(11) << endl;
}