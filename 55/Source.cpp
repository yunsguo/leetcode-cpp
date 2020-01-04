#include <iostream>
#include <vector>
#include "../leetcode_misc/listcode_misc.h"
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
	bool canJump(vector<int> A)
	{
		size_t i = 0;
		for (size_t reach = 0; i < A.size() && i <= reach; ++i)
			reach = max(i + A[i], reach);
		return i == A.size();
	}

};

void test(vector<int> nums)
{
	Solution so;
	cout << "Input: " << nums << endl;
	cout << "Output: " << (so.canJump(nums) ? "true" : "false") << endl << endl;
}

int main()
{
	test({ 2,3,1,1,4 });
	test({ 3,2,1,0,4 });
	test({ 2,0,0 });
	test({ 2,0,6,9,8,4,5,0,8,9,1,2,9,6,8,8,0,6,3,1,2,2,1,2,6,5,3,1,2,2,6,4,2,4,3,0,0,0,3,8,2,4,0,1,2,0,1,4,6,5,8,0,7,9,3,4,6,6,5,8,9,3,4,3,7,0,4,9,0,9,8,4,3,0,7,7,1,9,1,9,4,9,0,1,9,5,7,7,1,5,8,2,8,2,6,8,2,2,7,5,1,7,9,6 });
}