#include <iostream>

template<int n>
struct fib
{
	enum { value = fib<n - 1>::value + fib<n - 2>::value };
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
public:
	static int invoke(int N)
	{
		constexpr int mid = (a + b) / 2;
		if (N > mid) return runtime_search<mid, b>::invoke(N);
		if (N < mid) return runtime_search<a, mid>::invoke(N);
		return fib<mid>::value;
	}
};

using namespace std;

int main()
{
	cout << runtime_search<0, 46>::invoke(20);
}