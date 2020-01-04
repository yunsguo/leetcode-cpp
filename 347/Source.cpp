
#include <iostream>
#include <vector>
#include <unordered_map>
#include "../leetcode_misc/listcode_misc.h"
#include "../util/util.h"

using namespace std;

template<typename T, typename K>
void sortFirstK(vector<T>& arr, size_t low, size_t high, K comparer, size_t k) {
	if (low < high)
	{
		/* pi is partitioning index, arr[pi] is now
		   at right place */
		auto pi = partition(arr, low, high, comparer);

		if (k < pi)
			sortFirstK(arr, low, pi - 1, comparer, k);  // Before pi
		sortFirstK(arr, pi + 1, high, comparer, k); // After pi
	}
}

template<typename T, typename K>
size_t partition(vector<T>& arr, size_t low, size_t high, K comparer)
{
	auto pivot = arr[high]; size_t i = low;
	for (size_t j = low; j < high; j++) {
		if (!comparer(arr[j], pivot)) {
			swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[i], arr[high]);
	return i;
}

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, size_t> frequency;
		for (auto i : nums)
			if (frequency.count(i) == 0)frequency[i] = 1; else frequency[i]++;
		vector<int> set;
		set.reserve(frequency.size());
		for (auto pair : frequency)
			set.push_back(pair.first);
		sortFirstK(set, 0, set.size() - 1, [&](int a, int b)->bool {return frequency[a] < frequency[b]; }, k);
		cout << "sorted set: " << set << endl;
		vector<int> tops;
		auto length = set.size();
		for (int j = 0; j < k; j++)
			tops.push_back(set[j]);
		return tops;
	}
};


int main() {
	Solution s;
	vector<int> n1 = { 2,1,5,6,4,7 };
	vector<int> n2 = { 1,1,1,2,2,3 };
	vector<int> n3 = { 5,3,1,1,1,3,5,73,1 };
	cout << s.topKFrequent(n1, 3) << endl;;
	cout << s.topKFrequent(n2, 2) << endl;;
	cout << s.topKFrequent(n3, 3) << endl;;
}