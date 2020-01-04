#include <vector>
#include <iostream>
#include <algorithm>
#include "../util/util.h"

using namespace std;

class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {

	}

	static int getSmallerSetSize(int i, int j) {
		return i * j + i + j;
	}

	static int getLargerSetSize(int i, int j, int size) {
		return getSmallerSetSize(size - i - 1, size - j - 1);
	}

	static bool isInRange(int k, int i, int j, int size) {
		auto min = getSmallerSetSize(i, j);
		auto max = size * size - getLargerSetSize(i, j, size) - 1;
		return k >= min && k <= max;
	}
	static int getCandidateSize(int k, int size) {
		int result = 0;
		for (int i = 0; i < size; i++)
			for (int j = i; j < size; j++)
				if (isInRange(k, i, j, size))
					result += i == j ? 1 : 2;
		return result;
	}
	static vector<int> getCandidacy(int size) {
		auto l = size * size;
		vector<int> result;
		for (int i = 0; i < l; i++)
			result.push_back(getCandidateSize(i, size));
		return result;
	}

	static int getPreRanking(int k, int size) {

		int result = 0;
		for (int i = 0; i < size; i++)
		{
			int j = 0;
			if (isInRange(k, i, j, size))
				break;
			else
			{
				result++;
			}
			j++;
			for (; j < size; j++)
				if (isInRange(k, i, j, size))
					break;
				else
				{
					result++;
				}
		}
		return result;
	}
	static vector<int> getFullRanking(int size) {
		auto l = size * size;
		vector<int> result;
		for (int i = 0; i < l; i++)
			result.push_back(getPreRanking(i, size));
		return result;
	}
};

vector<vector<int>> getDiagnalMatrix(const vector<int>& list) {
	int size = sqrt(list.size());
	int l = size * 2 - 1;
	int k = 0;
	vector<vector<int>> result(size, vector<int>(size, 0));
	for (int i = 0; i < size; i++)
		for (int j = 0; j <= i; j++)
			result[i - j][j] = list[k++];
	for (int j = 1; j < size; j++) {
		auto sum = j + size - 1;
		for (int i = size - 1; i >= j; i--)
			result[i][sum - i] = list[k++];
	}
	return result;
}

int main()
{
	vector<vector<int>> m1 = {
		{1, 5, 9},
			{10, 11, 13},
			{12, 13, 15},
	};
	vector<int> list = { 0,1,2,3,4,5,6,7,8 };
	cout << "candidacy: " << endl;
	for (int i = 1; i <= 10; i++) {
		auto candidacy = Solution::getCandidacy(i);
		cout << i << ": " << candidacy << endl;
		cout << i << ": " << getDiagnalMatrix(candidacy) << endl;
	}
	cout << "ranking: " << endl;
	for (int i = 1; i <= 10; i++) {
		auto fullRanking = Solution::getFullRanking(i);
		cout << i << ": " << fullRanking << endl;
		cout << i << ": " << getDiagnalMatrix(fullRanking) << endl;
	}
}