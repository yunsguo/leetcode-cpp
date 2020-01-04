#include <vector>
using namespace std;

class Solution {
public:
	vector<size_t> twoSum(vector<size_t>& numbers, size_t target) {
		auto d = diff(numbers, target);
		size_t i = numbers.size() - 1;
		while (i >= 0)
		{
			if (numbers[i] == d.back()) return { (size_t)(numbers.size() - d.size() + 1),i + 1 };
			if (numbers[i] > d.back())
				i--;
			else
				d.pop_back();
		}
		return { 0,0 };
	}

	vector<size_t> diff(const vector<size_t>& numbers, size_t target) {
		auto l = numbers.size();
		vector<size_t> d(l);
		for (size_t i = 0; i < l; i++)
			d[l - i - 1] = target - numbers[i];
		return d;
	}
};

size_t main()
{
	vector<size_t> test = { 2,7,11,15 };
	Solution s;
	s.twoSum(test, 9);
}