#include <vector>
#include <iostream>

using std::vector;
class Solution {
public:
	size_t removeElement(vector<size_t>& nums, size_t val) {
		size_t length = nums.size();
		for (size_t i = 0; i < length; i++)
			if (nums[i] == val)
				if (!removeVal(val, nums, i, length))
					return 0;
		return length;
	}

	bool removeVal(size_t val, vector<size_t>& nums, size_t i, size_t& length) {
		if (i >= length) return false;
		if (i == length-1) {
			length -= 1;
			return true;
		}
		size_t back = nums[length - 1];
		if (back == val) {
			length -= 1;
			return removeVal(val, nums, i, length);
		}
		nums[i] = back;
		length -= 1;
		return true;
	}
};

std::ostream& operator<<(std::ostream& os, const vector<size_t>& v) {
	if (v.size() == 0) return os << "[]";
	auto i = v.begin();
	os << "[" << *i;
	i++;
	while (i != v.end()) {
		os << "," << *i;
		i++;
	}
	return os << "]";
}

size_t main()
{
	std::vector<size_t> a1 = { 3,2,2,3 };
	std::vector<size_t> a2 = { 4,5 };
	Solution s;
	auto l = s.removeElement(a2, 5);
	std::cout << "length: " << l << std::endl
		<< "array: " << a2 << std::endl;
	NULL
}

