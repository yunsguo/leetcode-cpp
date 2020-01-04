#include <vector>
#include <algorithm>
#include <iostream>
#include "../util/util.h"

using namespace std;

class Solution {
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
};

int main() {
	Solution s;
	vector<int> A1 = { 34, 23, 1, 24, 75, 33, 54, 8 };
	vector<int> A2 = { 254, 914, 110, 900, 147, 441, 209, 122, 571, 942, 136, 350, 160, 127, 178, 839, 201, 386, 462, 45, 735, 467, 153, 415, 875, 282, 204, 534, 639, 994, 284, 320, 865, 468, 1, 838, 275, 370, 295, 574, 309, 268, 415, 385, 786, 62, 359, 78, 854, 944 };
	cout << s.twoSumLessThanK(A1, 60) << endl;	cout << s.twoSumLessThanK(A2, 200) << endl;
}