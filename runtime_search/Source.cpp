#include <iostream>

using byte = unsigned char;

template<typename T, T i>
struct compile_time
{
	enum { value = i };
	static void invoke() { std::cout << "boom! compile time constant: " << i << std::endl; }
};

template<byte K>
struct bit_number
{
	enum { value = bit_number<K - 2>::value << 2 };
};

template<>
struct bit_number<2>
{
	enum { value = 4 };
};

template<>
struct bit_number<1>
{
	enum { value = 2 };
};

template<>
struct bit_number<0> {};

byte MSB(size_t k)
{
	byte b = 0;
	while (k >> b != 0)
		b++;
	return b - 1;
}

struct runtime_search
{

	template<typename T, T a, T b>
	static void invoke(T k)
	{
		constexpr T mid = (a / 2) + (b / 2) + (((a % 2) + (b % 2)) / 2);
		if (k > mid)
		{
			invoke<T, mid, b>(k);
			return;
		}
		if (k < mid)
		{
			invoke<T, a,mid>(k);
			return;
		}
		compile_time<T, mid>::invoke();
	}
};
int main()
{
	compile_time<size_t, 5>::invoke();
	compile_time<size_t, bit_number<32>::value - 1u>::invoke();
	compile_time<size_t, sizeof(size_t)>::invoke();
	//for (size_t i = 0; i < 32; i++)
	//	std::cout << i << ": " << (size_t)MSB(i) << std::endl;
	runtime_search::invoke<size_t, 0, 8192>(25);
}