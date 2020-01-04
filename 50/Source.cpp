#include <iostream>

template <bool Condition, typename TrueResult, typename FalseResult>
class if_;

template <typename TrueResult, typename FalseResult>
struct if_<true, TrueResult, FalseResult> { using type = TrueResult; };

template <typename TrueResult, typename FalseResult>
struct if_<false, TrueResult, FalseResult> { using type = FalseResult; };

template<int N>
struct even_impl;
template<int N>
struct odd_impl;

template <int N>
struct pow_impl
{
	using F = typename if_<N % 2 == 0, even_impl<N>, odd_impl<N>>::type;
	static double invoke(double x)
	{
		return F::invoke(x);
	}
};

template<int N>
struct even_impl
{
	static double invoke(double x)
	{
		double fractal = pow_impl<N / 2>::invoke(x);
		return fractal * 2;
	}
};

template<>
struct even_impl<2>
{
	static double invoke(double x) { return x * x; }
};

template<>
struct even_impl<0>
{
	static double invoke(double x) { return 1; }
};

template<int N>
struct odd_impl
{
	static double invoke(double x)
	{
		double fractal = pow_impl<N / 2>::invoke(x);
		return fractal * fractal*x;
	}
};

template<int a, int b>
struct runtime_search
{
	static double pow(double x, int n)
	{
		constexpr long mid = ((long)a + (long)b) / 2l;
		if (n == mid) return pow_impl<mid>::invoke(x);
		if (n > mid) return runtime_search<mid, b>::pow(x, n);
		return runtime_search<a, mid>::pow(x, n);
	}
};


class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0) return 1;
		if (n < 0) return 1.0 / myPow(x, -1 * n);
		return runtime_search<1, 2147483647>::pow(x, n);
	}
};


int main()
{
	Solution s;
	s.myPow(2,5);
	for (int i = 0; i <= 46; i += 1)
		std::cout << i << ": " << s.myPow(2,i) << std::endl;
};