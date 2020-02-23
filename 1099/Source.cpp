#include <vector>
#include <algorithm>
#include <iostream>
#include "../util/util.h"
#include <set>

using namespace std;

class Solution {
	static int max(int a, int b) {
		return a > b ? a : b;
	}
public:
	int twoSumLessThanK(vector<int>& A, int K) {
		auto size = A.size();
		vector<int> negations(size);
		for (int i = 0; i < size; i++)
			negations[i] = K - A[i];
		int dif = K;
		for (int i = 0; i < size; i++)
			for (int j = i + 1; j < size; j++) {
				auto dif_n = negations[j] - A[i];
				if (dif_n == 0)cout << "irregularity: " << i << ", " << j << endl;
				if (dif_n > 0) dif = min(dif, dif_n);
			}
		return dif == K ? -1 : K - dif;
	}
	int twoSumLessThanK2(vector<int>& A, int K) {
		sort(A.begin(), A.end(), std::greater<int>());
		cout << "sorted: " << A << endl;
		auto l = A.size();
		int result = -1;
		for (size_t i = 0; i < l; i++)
			for (size_t j = i + 1; j < l; j++)
			{
				auto candidate = A[i] + A[j];
				if (candidate >= K) continue;
				if (candidate > result)  result = candidate;  break;
			}
		return result;
	}
};

int main() {
	Solution s;
	vector<int> A1 = { 34, 23, 1, 24, 75, 33, 54, 8 };
	vector<int> A2 = { 254, 914, 110, 900, 147, 441, 209, 122, 571, 942, 136, 350, 160, 127, 178, 839, 201, 386, 462, 45, 735, 467, 153, 415, 875, 282, 204, 534, 639, 994, 284, 320, 865, 468, 1, 838, 275, 370, 295, 574, 309, 268, 415, 385, 786, 62, 359, 78, 854, 944 };
	vector<int> A3 = { 10,20,30 };
	cout << s.twoSumLessThanK2(A1, 60) << endl;	cout << s.twoSumLessThanK2(A2, 200) << endl; cout << s.twoSumLessThanK2(A3, 15) << endl;
}