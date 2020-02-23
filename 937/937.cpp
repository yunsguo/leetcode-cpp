// 937.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include "../util/util.h"
#include <set>

using namespace std;

bool isLower(char c) {
	return c >= 'a' && c <= 'z';
}

bool isDigit(char c) {
	return c >= '0' && c <= '9';
}

template<typename Predicate>
bool every(string str, Predicate p) {
	for (char c : str)
		if (!p(c)) return false;
	return true;
}

template<typename T, typename Predicate>
bool findAfter(vector<T> ts, Predicate p, size_t start = 0) {
	auto l = ts.size();
	for (size_t i = start; i < l; i++)
		if (p(ts[i])) return true;
	return false;
}

bool isLetters(string str) {
	return every(str, isLower);
}

bool isDigits(string str) {
	return every(str, isDigit);
}

vector<string> parseSpaceSeparatedWords(const string& str) {
	size_t prev = 0;
	vector<string> result;
	auto l = str.length();
	while (prev < l) {
		size_t curr = str.find(' ', prev);
		if (curr == string::npos) curr = l;
		if (curr > prev) result.push_back(str.substr(prev, curr - prev));
		prev = curr + 1;
	}
	return result;
}

bool compare(pair<string, size_t> log1, pair<string, size_t> log2) {
	auto logs1 = parseSpaceSeparatedWords(get<0>(log1));
	auto logs2 = parseSpaceSeparatedWords(get<0>(log2));
	if (findAfter(logs1, isLetters, 1)) {
		if (findAfter(logs2, isLetters, 1))
		{
			auto ord = get<0>(log1).substr(logs1[0].length()).compare(get<0>(log2).substr(logs2[0].length()));
			if (ord < 0) return true;
			if (ord == 0) return logs1[0].compare(logs2[0]) < 0;
			return false;
		}
		return true;
	}
	if (findAfter(logs2, isLetters, 1))
		return false;
	return get<1>(log1) < get<1>(log2);
}

class Solution {
public:

	vector<string> reorderLogFiles(vector<string>& logs) {
		vector<pair<string, size_t>> logsWithIndex;
		auto l = logs.size();
		for (size_t i = 0; i < l; i++)
			logsWithIndex.push_back({ logs[i], i });

		sort(logsWithIndex.begin(), logsWithIndex.end(), compare);
		vector<string> result;
		for (auto pair : logsWithIndex)
			result.push_back(get<0>(pair));
		return result;
	}
};

int main()
{
	Solution s;
	vector<string> logs = { "dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero" };
	vector<string> result = s.reorderLogFiles(logs);
	for (string str : result)
		cout << str << endl;
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
