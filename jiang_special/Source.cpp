#include <unordered_set>
#include <list>
#include <iostream>
#include "../leetcode_misc/listcode_misc.h"

/*
The problem came from one of Jiang Haowen's OA questions.
Alice has a series of beads with number from 1 to n engraved on them.
She wants to make a necklace such that every beads next to each other has a prime sum.
Given the number of beads N, find the number of ways she can arrange the necklace.
*/

using namespace std;


class Solution
{
	using Set = unordered_set<size_t>;
	using Scenario = pair<Set, size_t>;
	Set primes;
	int result;
	size_t N;

	static void prepare_primes(size_t n, Set& set)
	{
		list<size_t> list;
		for (size_t i = 2; i <= n; i++)
			list.push_back(i);
		auto itor = list.begin();
		while (itor != list.end())
		{
			auto curr = itor;
			auto curr_number = *curr;
			if (curr_number*curr_number >= n)
				break;
			auto temp = ++curr;
			while (temp != list.end())
			{
				if (*temp%curr_number == 0)
					list.erase(temp++);
				else
					temp++;
			}
			itor++;
		}
		for (auto p : list)
			set.insert(p);
	}

public:
	int necklace_number(int n)
	{
		N = n;
		prepare_primes(n * 2 - 1, primes);
		Set set;
		set.insert(1);
		Scenario s(set, 1);
		dfs(s, 1);
		return result;
	}

	size_t fetch_first(const Set& s)
	{
		for (size_t i = N; i > 1; i--)
			if (s.count(i) == 0) return i;
		return -1;
	}

	bool dfs(Scenario& s, size_t index)
	{
		if (index + 1 == N)
		{
			auto candidate = fetch_first(s.first);
			if (primes.count(candidate + s.second) == 0 || primes.count(candidate + 1) == 0)
				return false;
			result++;
			return true;
		}
		for (size_t i=2;i<=N;i++)
		{
			if (s.first.count(i) != 0 || primes.count(i + s.second) == 0) continue;
			auto last_bead = s.second;
			s.first.insert(i);
			s.second = i;
			dfs(s,index+1);
			s.first.erase(i);
			s.second = last_bead;
		}
		return true;
	}
};

void test(int n)
{
	Solution s;
	cout << "Input: " << n << endl
		<< "Output: " << s.necklace_number(n) << endl;
}
int main()
{
	test(3);
	test(4);
	test(5);
	test(6);
	test(9);
	test(10);
	test(12);
}