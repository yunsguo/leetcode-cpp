#include <vector>
#include "../leetcode_misc/listcode_misc.h"

using namespace std;

class Solution {

private:
	bool canTravel(vector<int>& gas, vector<int>& cost, size_t index)
	{
		int tank = 0;
		auto n = gas.size();
		for (size_t i = 0; i < n; i++)
		{
			tank += gas[(i+index)%n];
			if (tank < 0)
				return false;
		}
		return true;
	}
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int n = gas.size();
		int sum = 0;
		vector<size_t> candidates;
		for (size_t i = 0; i < n; i++)
		{
			gas[i] = gas[i] - cost[i];
			if (gas[i] >= 0)
				candidates.push_back(i);
			sum += gas[i];
		}
		if (sum < 0 || candidates.empty()) return -1;
		for (auto c : candidates)
			if (canTravel(gas, cost, c)) return c;
		return -1;
	}
};

void test(vector<int> gas, vector<int> cost)
{
	Solution s;
	cout
		<< "input: " << endl
		<< "gas:  " << gas << endl
		<< "cost: " << cost << endl;
	cout << "output: " << s.canCompleteCircuit(gas, cost) << endl;
}

int main()
{
	test({ 1,2,3,4,5 }, { 3,4,5,1,2 });
	test({ 2,3,4 }, { 3,4,3 });
};
