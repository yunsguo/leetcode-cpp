#include <vector>

using namespace std;

class Solution {
public:
	void rotate(vector<size_t>& nums, size_t k) {
		size = nums.size();
		auto limit = size;
		k = k % size;
		if (k >= size) return rotate(nums, k % size);
		if (k == 0 || size == 0) return;
		recursive_move_away(nums, k, k, 0, nums[0], limit);
		if (limit == 0) return;
		size_t i = 1;
		while (limit != 0)
		{
			recursive_move_away(nums, k, (k + i) % size, i, nums[i], limit);
			i++;
		}
	}
private:
	size_t size;

	void recursive_move_away(vector<size_t>& nums, size_t step, size_t index, size_t end, size_t val, size_t& times) {
		times--;
		auto i = (index + step) % size;
		if (index == end)
		{
			nums[i] = val;
			return;
		}
		auto temp = nums[index];
		recursive_move_away(nums, step, i, end, val, times);
			nums[i] = temp;
	}
};

size_t main()
{
	vector<size_t> test = { 1,2,3,4,5,6,7 };
	vector<size_t> test2 = { 1,2,3,4,5,6 };
	Solution s;
	//s.rotate(test, 3);
	s.rotate(test2, 4);
}