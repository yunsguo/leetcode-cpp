#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	string convertToTitle(size_t n) {
		if (n <= 26) return string(1, '@' + n);
		if (n % 26 == 0) return convertToTitle(n / 26 - 1) + 'Z';
		return convertToTitle(n / 26) + convertToTitle(n % 26);
	}
};

void display(size_t n)
{
	Solution s;
	std::cout << n << ": " << s.convertToTitle(n) << std::endl;
}
size_t main()
{
	display(1);
	display(28);
	display(52);
	display(701);
}