#include <iostream>

template<int i>
struct fib
{
	enum { value = fib<i - 1>::value + fib<i - 2>::value };
};

template<>
struct fib<0>
{
	enum { value = 0 };
};

template<>
struct fib<1>
{
	enum { value = 1 };
};

template<int a, int b>
struct runtime_search
{
	static int invoke(int N)
	{
		constexpr int mid = (a + b) / 2;
		if (N == mid) return fib<mid>::value;
		if (N > mid) return runtime_search<mid, b>::invoke(N);
		return runtime_search<a, mid>::invoke(N);
	}
};

class Solution {
public:
	int fib(int N) {
		if (N == 46) return ::fib<46>::value;
		if (N == 0) return 0;
		return runtime_search<0, 46>::invoke(N);
	}
};



int main()
{
	Solution s;
	std::cout << s.fib(22) << std::endl;
};