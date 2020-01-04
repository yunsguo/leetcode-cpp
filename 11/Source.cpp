#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	size_t maxArea(vector<size_t>& height) {
		size_t j = height.size() - 1;
		size_t area = min(height.front(),height.back())*j;
		if (height.front() > height.back())
			area_probe(height, 0, j - 1, area);
		else area_probe(height, 1, j, area);
		return area;
	}
private:
	static size_t min(size_t a, size_t b) { return a <= b ? a : b; }

	void area_probe(vector<size_t>& height, size_t i, size_t j, size_t& max)
	{
		if (i >= j) return;
		size_t area = min(height[i], height[j])*(j - i);
		if (area > max) max = area;
		if (height[i] >= height[j])
			area_probe(height, i, j - 1,max);
		else area_probe(height, i + 1, j, max);
	}
};

size_t main()
{
	vector<size_t> input = { 1,8,6,2,5,4,8,3,7 };
	Solution s;
	cout<<s.maxArea(input);
}