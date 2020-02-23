// 994.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <vector>
#include <algorithm>
#include <iostream>
#include "../util/util.h"
#include <unordered_set>

using namespace std;
class Solution {
	static bool elapse(unordered_set<int>& rotten, unordered_set<int>& fresh, size_t cn) {
		vector<int> transfer;
		if (rotten.size() < fresh.size()) {
			cout << "on rotten." << endl;
			for (int cell : rotten)
			{
				if (fresh.erase(cell + cn) == 1) transfer.push_back(cell + cn);
				if (fresh.erase(cell - cn) == 1) transfer.push_back(cell - cn);
				auto r = cell % cn;
				if (r != 0 && fresh.erase(cell - 1) == 1) transfer.push_back(cell - 1);
				if (r != cn - 1 && fresh.erase(cell + 1) == 1) transfer.push_back(cell + 1);
			}
			rotten.insert(transfer.begin(), transfer.end());
		}
		else {
			cout << "on fresh." << endl;
			for (int cell : fresh) {
				if (rotten.count(cell + cn) == 1) transfer.push_back(cell );
				if (rotten.count(cell - cn) == 1) transfer.push_back(cell );
				auto r = cell % cn;
				if (r != 0 && rotten.count(cell - 1) == 1) transfer.push_back(cell);
				if (r != cn - 1 && rotten.count(cell + 1) == 1) transfer.push_back(cell);
			}
			for (int cell : transfer)
				fresh.erase(cell);
			rotten.insert(transfer.begin(), transfer.end());
		}
		cout << "transfer: " << transfer << endl;
		return transfer.size() > 0;
	}
public:
	int orangesRotting(vector<vector<int>>& grid) {
		unordered_set<int> rotten;
		unordered_set<int> fresh;
		if (grid.size() == 0) return -1;
		auto cn = grid[0].size();
		for (size_t i = 0; i < grid.size(); i++)
			for (size_t j = 0; j < grid[i].size(); j++)
			{
				switch (grid[i][j]) {
				case 1:
					fresh.insert(i * cn + j);
					break;
				case 2:
					rotten.insert(i * cn + j);
					break;
				}
			}
		auto t = 0;
		while (elapse(rotten, fresh, cn))
			t++;
		if (fresh.size() > 0) return -1;
		return t;
	}
};

int main()
{
	std::cout << "Hello World!\n";
	vector<vector<int>> e1{ {2,1,1},{1,1,0},{0,1,1} };
	Solution s;
	cout << s.orangesRotting(e1) << endl;;
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
