#include "../leetcode_misc/listcode_misc.h"
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

template<>
struct std::hash< pair<size_t, size_t>>
{
	size_t operator()(const pair<size_t, size_t>& val) const
	{
		return val.first | val.second;
	}
};

class Solution
{
	string str;
	vector<vector<int>> table;
	size_t n;


	int LPS_impl(size_t from, size_t to)
	{
		auto cache = table[from][to];
		if (cache != -1) return cache;
		if (from > to || to >= n || from >= n) return table[from][to] = 0;
		if (from == to) return table[from][to] = 1;
		if (str[from] == str[to])
			return table[from][to] = 2 + LPS_impl(from + 1, to - 1);
		return table[from][to] = max(LPS_impl(from + 1, to), LPS_impl(from, to - 1));
	}

public:
	int longestPalindromeSubseq(string s)
	{
		str = std::move(s);
		n = str.size();
		table = vector<vector<int>>(n, vector<int>(n, -1));
		return LPS_impl(0, n - 1);
	}
};

void test(string str)
{
	Solution s;
	cout << "Input: " << str << endl;
	cout << "Ouput: " << s.longestPalindromeSubseq(str) << endl;
}
int main()
{
	test("cbbd");
	test("bbbab");
	test("abcdabcdabcdabcd");
	test("gphyvqruxjmwhonjjrgumxjhfyupajxbjgthzdvrdqmdouuukeaxhjumkmmhdglqrrohydrmbvtuwstgkobyzjjtdtjroqpyusfsbjlusekghtfbdctvgmqzeybnwzlhdnhwzptgkzmujfldoiejmvxnorvbiubfflygrkedyirienybosqzrkbpcfidvkkafftgzwrcitqizelhfsruwmtrgaocjcyxdkovtdennrkmxwpdsxpxuarhgusizmwakrmhdwcgvfljhzcskclgrvvbrkesojyhofwqiwhiupujmkcvlywjtmbncurxxmpdskupyvvweuhbsnanzfioirecfxvmgcpwrpmbhmkdtckhvbxnsbcifhqwjjczfokovpqyjmbywtpaqcfjowxnmtirdsfeujyogbzjnjcmqyzciwjqxxgrxblvqbutqittroqadqlsdzihngpfpjovbkpeveidjpfjktavvwurqrgqdomiibfgqxwybcyovysydxyyymmiuwovnevzsjisdwgkcbsookbarezbhnwyqthcvzyodbcwjptvigcphawzxouixhbpezzirbhvomqhxkfdbokblqmrhhioyqubpyqhjrnwhjxsrodtblqxkhezubprqftrqcyrzwywqrgockioqdmzuqjkpmsyohtlcnesbgzqhkalwixfcgyeqdzhnnlzawrdgskurcxfbekbspupbduxqxjeczpmdvssikbivjhinaopbabrmvscthvoqqbkgekcgyrelxkwoawpbrcbszelnxlyikbulgmlwyffurimlfxurjsbzgddxbgqpcdsuutfiivjbyqzhprdqhahpgenjkbiukurvdwapuewrbehczrtswubthodv");
}