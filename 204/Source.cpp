#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <list>

using namespace std;
//
//class Solution {
//public:
//	size_t countPrimes(size_t n) {
//		auto& ps = primes();
//		if (n <= max())
//		{
//			if (n <= 2) return 0;
//			if (n > ps.back()) return ps.size();
//			if (n == ps.back()) return ps.size() - 1;
//			return find(n, 0, ps.size());
//		}
//		cal_until(n);
//		auto r = ps.size();
//		return r;
//	}
//
//private:
//
//	static void cal_until(size_t n) {
//		list<size_t> seq;
//		auto& ps = primes();
//		for (size_t i = max() + 1; i <= n; i++)
//			seq.push_back();
//		size_t roof = (size_t)sqrt(n - 1) + 1;
//		for (auto p : ps)
//		{
//			seq.remove_if([p](size_t n)->bool {return n % p == 0; });
//			if (p > roof) break;
//		}
//		while (seq.size() != 0)
//		{
//			auto p = seq.front();
//			seq.pop_front();
//			ps.push_back(p);
//			seq.remove_if([p](size_t n)->bool {return n % p == 0; });
//			if (p > roof) break;
//		}
//		for (auto p : seq)
//			ps.push_back(p);
//		max() = n;
//	}
//
//	static size_t find(size_t n, size_t i, size_t j)
//	{
//		auto& ps = primes();
//		auto pivot = (i + j) / 2;
//		if (n > ps[pivot - 1] && ps[pivot] >= n)
//			return pivot;
//		if (n > ps[pivot])
//			return find(n, pivot, j);
//		return find(n, i, pivot);
//	}
//
//	static size_t& max() {
//		static size_t m = 97;
//		return m;
//	}
//
//	static vector<size_t>& primes() {
//		static vector<size_t> v{ 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97 };
//		return v;
//	}
//};

class Solution {
public: 
	size_t countPrimes(size_t n) {
	auto isPrime = vector<bool>(n);
	for (size_t i = 2; i < n; i++) {
		isPrime[i] = true;
	}
	// Loop's ending condition is i * i < n instead of i < sqrt(n)
	// to avoid repeatedly calling an expensive function sqrt().
	for (size_t i = 2; i * i < n; i++) {
		if (!isPrime[i]) continue;
		for (size_t j = i * i; j < n; j += i) {
			isPrime[j] = false;
		}
	}
	size_t count = 0;
	for (size_t i = 2; i < n; i++) {
		if (isPrime[i]) count++;
	}
	return count;
}
};

size_t main()
{
	Solution s;
	cout << 999983 << ": " << s.countPrimes(999983) << endl;
	//for (size_t i = 50; i < 150; i++)
	//	cout << i << ": " << s.countPrimes(i) << endl;
}