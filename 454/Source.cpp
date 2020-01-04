#include <vector>
#include <unordered_map>
#include <iostream>
#include "../leetcode_misc/listcode_misc.h"

using namespace std;

class Solution
{
	static void intersect(const vector<int>& A, const vector<int>& B, unordered_map<int, size_t>& map)
	{
		auto N = A.size();
		for (size_t i = 0; i < N; i++)
			for (size_t j = 0; j < N; j++)
			{
				auto sum = A[i] + B[j];
				if (map.count(sum) == 0)map[sum] = 1;
				else map.at(sum)++;
			}
	}

	static int count(const unordered_map<int, size_t>& one, const unordered_map<int, size_t>& two)
	{
		if (one.size() > two.size()) return count(two, one);
		int result = 0;
		for (auto pair : one)
		{
			if (two.count(pair.first*-1) != 0)
				result += pair.second*two.at(pair.first*-1);
		}
		return result;
	}

	static int intersect2(const vector<int>& A, const vector<int>& B, const unordered_map<int, size_t>& map)
	{
		auto N = A.size();
		int result = 0;
		for (size_t i = 0; i < N; i++)
			for (size_t j = 0; j < N; j++)
			{
				auto sum = -1*(A[i] + B[j]);
				if (map.count(sum) != 0) result += map.at(sum);
			}
		return result;
	}

public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D)
	{
		unordered_map<int, size_t> ab;
		intersect(A, B, ab);
		return intersect2(C,D,ab);
	}
};

void test(vector<int> A, vector<int> B, vector<int> C, vector<int> D)
{
	Solution s;
	cout << "Input: " << "A: " << A << endl << "B: " << B << endl << "C: " << C << endl << D << "D: " << endl;
	cout << "Output: " << s.fourSumCount(A, B, C, D) << endl;
}

int main()
{
	test({ 1,2 }, { -2,-1 }, { -1,2 }, { 0,2 });
}