// 973.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <algorithm>
#include "../util/util.h"

using namespace std;

template<typename T, typename P>
void modified_quick_sort(vector<T>& A, P preorder, size_t lo, size_t hi, size_t k) {
	if (lo >= hi) return;
	auto p = partition(A, preorder, lo, hi);
	if (p == k - 1) return;
	if (p > k - 1)
		modified_quick_sort(A, preorder, lo, p, k);
	else
		modified_quick_sort(A, preorder, p + 1, hi, k);
}

class Solution {
public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
		auto size = points.size();
		if (K == size) return points;
		if (K == 0) return vector<vector<int>>(0);
		size_t preorder_til = 0;
		modified_quick_sort(points, [](const vector<int>& a, const vector<int>& b)->bool {return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1]; }, 0, points.size() - 1, K);
		return vector<vector<int>>(points.begin(), points.begin() + K);
	}
};


template<typename T, typename P>
size_t partition(vector<T>& A, P preorder, size_t lo, size_t hi) {
	auto pivot = A[(hi + lo) / 2];
	auto i = lo - 1;
	auto j = hi + 1;
	while (true) {
		do
			i++;
		while (preorder(A[i], pivot));
		do
			j--;
		while (preorder(pivot, A[j]));
		if (i >= j)
			return j;
		swap(A[i], A[j]);
	}
}

int main()
{
	std::cout << "Hello World!\n";
	vector<vector<int>> v1{ {3,3} ,{5,-1},{-2,4} };
	vector<vector<int>> v2{ {1,3} ,{-2,2} };
	vector<vector<int>> v3{ {-95, 76}, {17, 7}, {-55, -58}, {53, 20}, {-69, -8}, {-57, 87}, {-2, -42}, {-10, -87}, {-36, -57}, {97, -39}, {97, 49} };
	vector<vector<int>> v4{ {0,1} ,{1,0} };
	Solution s;
	cout << s.kClosest(v1, 2) << endl;
	cout << s.kClosest(v2, 1) << endl;
	cout << s.kClosest(v3, 5) << endl;
	cout << s.kClosest(v4, 2) << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
