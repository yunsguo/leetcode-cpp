// 1167.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <vector>
#include <algorithm>
#include <iostream>
#include "../util/util.h"
#include <unordered_set>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        make_heap(sticks.begin(), sticks.end(), compare);
        auto size = sticks.size();
        while (sticks.size() != 0)
        {
            pop_heap(sticks.begin(), sticks.end(), compare);
            cout << sticks.back() << endl;
            sticks.pop_back();
        }
        return 0;
    }
};
int main()
{
    vector<int> v1{2,4,3};
    Solution s;
    s.connectSticks(v1);
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
