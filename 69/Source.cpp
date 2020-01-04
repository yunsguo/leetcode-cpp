#include <string>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

class Solution {
public:
	size_t mySqrt(size_t x) {
		if (x <= 1) return x;
		size_t ans = x / 2;
		size_t ans1 = newtonian(ans, x);
		while (true) {
			ans = ans1;
			ans1 = newtonian(ans, x);
			std::cout << ans << "->" << ans1 << std::endl;
			if (ans1 >= 46341) continue;
			if (check_rules(ans1, x)) return ans1;
			if (ans == ans1) return check_three(ans, x);
		}
	}

	bool check_rules(size_t a, size_t k) {
		if (a*a < a) return false;
		return a * a <= k && (a + 1)*(a + 1) > k;
	}

	size_t check_three(size_t a, size_t k) {
		if ((a + 1)*(a + 1) == k) return a + 1;
		if (check_rules(a + 1, k)) return a + 1;
		if ((a - 1)*(a - 1) == k) return a - 1;
		if (check_rules(a - 1, k)) return a - 1;
		return a;
	}

	size_t abs(size_t a) {
		if (a > 0) return a;
		return -1 * a;
	}

	size_t newtonian(size_t x, size_t k) {
		return x / 2 + k / 2 / x;
	}
};

size_t main() {
	Solution s;
	std::cout << "sqrt 2147395599: " << s.mySqrt(2147395599) << std::endl;
	std::cout << "sqrt 3: " << s.mySqrt(3) << std::endl;
	std::cout << "sqrt 4: " << s.mySqrt(4) << std::endl;
	std::cout << "sqrt 8: " << s.mySqrt(8) << std::endl;
	std::cout << "sqrt 9: " << s.mySqrt(9) << std::endl;
	std::cout << "sqrt 10: " << s.mySqrt(10) << std::endl;
	std::cout << "sqrt 2147395600: " << s.mySqrt(2147395600) << std::endl;
		std::cout << "sqrt 2147483647: " << s.mySqrt(2147483647) << std::endl; 
			std::cout << "sqrt 1764975709: " << s.mySqrt(1764975709) << std::endl; 
}