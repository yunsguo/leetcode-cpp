#include <iostream>
#include <vector>
#include "../leetcode_misc/listcode_misc.h"
#include <unordered_set>

using namespace std;
	
class Solution {
public:
	int trap(vector<int>& height) {
		int left = 0; int right = height.size() - 1;
		int res = 0;
		int maxleft = 0, maxright = 0;
		while (left <= right) {
			if (height[left] <= height[right]) {
				if (height[left] >= maxleft) maxleft = height[left];
				else res += maxleft - height[left];
				left++;
			}
			else {
				if (height[right] >= maxright) maxright = height[right];
				else res += maxright - height[right];
				right--;
			}
		}
		return res;
	}
};

void test(vector<int> v)
{
	Solution s;
	cout << "Input: " << v << endl;
	cout << "Output: " << s.trap(v) << endl << endl;
}

int main()
{
	test({ 0,1,0,2,1,0,1,3,2,1,2,1 });
}