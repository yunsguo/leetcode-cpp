#include <string>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

class Solution {
public:
	Solution() :cache{ 0,1,2,3,5 } {}
	size_t climbStairs(size_t n) {
		if (n < (size_t)cache.size()) return cache[n];
		auto step2 = climbStairs(n - 2);
		auto result = step2 + climbStairs(n - 1);
		cache.push_back(result);
		return result;
	}
private:
	vector<size_t> cache;
};

size_t main() {
	Solution s;
	std::cout
		<< "2: " << s.climbStairs(2) << std::endl
		<< "45: " << s.climbStairs(45) << std::endl;
}