#include <vector>
#include <iostream>

using namespace std;

template<size_t N>
struct pow2
{
	static constexpr uint32_t value = 2 * pow2<N - 1>::value;
};

template<>
struct pow2<1>
{
	static constexpr uint32_t value = 1;
};

class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t r = 0;
		if (n % 2==1) r++;
		r = r << 1;
		n = n >> 1;
		if (n % 2 == 1) r++;
		r = r << 1;
		n = n >> 1;
		if (n % 2 == 1) r++;
		r = r << 1;
		n = n >> 1;
		if (n % 2 == 1) r++;
		r = r << 1;
		n = n >> 1;
		if (n % 2 == 1) r++;
		r = r << 1;
		n = n >> 1;
		if (n % 2 == 1) r++;
		r = r << 1;
		n = n >> 1;
		if (n % 2 == 1) r++;
		r = r << 1;
		n = n >> 1;
		if (n % 2 == 1) r++;
		r = r << 1;
		n = n >> 1;
		if (n % 2 == 1) r++;
		r = r << 1;
		n = n >> 1;
		if (n % 2 == 1) r++;
		r = r << 1;
		n = n >> 1;
		if (n % 2 == 1) r++;
		r = r << 1;
		n = n >> 1;
		if (n % 2 == 1) r++;
		r = r << 1;
		n = n >> 1;
		if (n % 2 == 1) r++;
		r = r << 1;
		n = n >> 1;
		if (n % 2 == 1) r++;
		r = r << 1;
		n = n >> 1;
		if (n % 2 == 1) r++;
		r = r << 1;
		n = n >> 1;
		if (n % 2 == 1) r++;
		r = r << 1;
		n = n >> 1;
		if (n % 2 == 1) r++;
		r = r << 1;
		n = n >> 1;
		if (n % 2 == 1) r++;
		r = r << 1;
		n = n >> 1;
		if (n % 2 == 1) r++;
		r = r << 1;
		n = n >> 1;
		if (n % 2 == 1) r++;
		r = r << 1;
		n = n >> 1;
		if (n % 2 == 1) r++;
		r = r << 1;
		n = n >> 1;
		if (n % 2 == 1) r++;
		r = r << 1;
		n = n >> 1;
		if (n % 2 == 1) r++;
		r = r << 1;
		n = n >> 1;
		if (n % 2 == 1) r++;
		r = r << 1;
		n = n >> 1;
		if (n % 2 == 1) r++;
		r = r << 1;
		n = n >> 1;
		if (n % 2 == 1) r++;
		r = r << 1;
		n = n >> 1;
		if (n % 2 == 1) r++;
		r = r << 1;
		n = n >> 1;
		if (n % 2 == 1) r++;
		r = r << 1;
		n = n >> 1;
		if (n % 2 == 1) r++;
		r = r << 1;
		n = n >> 1;
		if (n % 2 == 1) r++;
		r = r << 1;
		n = n >> 1;
		if (n % 2 == 1) r++;
		r = r << 1;
		n = n >> 1;
		if (n % 2 == 1) r++;
		return r;
	}
};

size_t main()
{
	Solution s;

	cout << s.reverseBits(43261596) << endl;
}