#include <type_traits>
#include <iostream>

using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		if (dividend >= 0 && divisor >= 0)
		{
			auto r = divide_impl(dividend, divisor);
			return  r > 2147483647 ? 2147483647:r;
		}
		if (dividend < 0 && divisor < 0)
		{
			auto r = divide_impl(abs(dividend), abs(divisor));
			return  r > 2147483647 ? 2147483647 : r;
		}
		return 0 - divide_impl(abs(dividend), abs(divisor));
	}

	size_t divide_impl(size_t dividend, size_t divisor)
	{
		if (dividend < divisor) return 0;
		if (dividend == divisor) return 1;
		if (divisor == 1) return dividend;
		ds_ = divisor;
		return try_subtract(dividend, divisor, 1);
	}

	size_t try_subtract(size_t dividend, size_t divisor, size_t size)
	{
		if (dividend > divisor) return size + try_subtract(dividend - divisor, divisor + divisor, size + size);
		if (dividend == divisor) return size;
		if (dividend > ds_)
			return try_subtract(dividend, ds_, 1);
		return 0;
	}

private:
	size_t ds_;
};

int main()
{
	Solution s;
	cout << s.divide(10, 3);
	cout << s.divide(-100, 2);
	cout << s.divide(100, -2);
	cout << s.divide(-100, -2);
	cout << s.divide(-2147483648, 2);
}