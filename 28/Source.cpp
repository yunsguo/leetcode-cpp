#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

vector<size_t> kmp_table(const string & W) {
	size_t l = W.length();
	vector<size_t> T(l);
	size_t pos = 1;
	size_t cnd = 0;
	T[0] = -1;
	while (pos < l) {
		if (W[pos] == W[cnd]) {
			T[pos] = T[cnd];
		}
		else {
			T[pos] = cnd;
			cnd = T[cnd];
			while (cnd >= 0 && W[pos] != W[cnd])
				cnd = T[cnd];
		}
		pos++; cnd++;
	}
	return T;
}
size_t strStr(string haystack, string needle) {
	if (needle == "") return 0;
	size_t np = 0;
	size_t j = 0; size_t k = 0;
	vector<size_t> T = kmp_table(needle);
	size_t sl = haystack.length();
	size_t wl = needle.length();
	while (j < sl) {
		if (needle[k] == haystack[j]) {
			j++; k++;
			if (k == wl) 
				return j - k;
		}
		else {
			k = T[k];
			if (k < 0) {
				j++; k++;
			}
		}
	}
	return -1;
}

std::ostream& operator<<(std::ostream& os, const vector<size_t>& v) {
	if (v.size() == 0) return os << "[]";
	auto i = v.begin();
	os << "[" << *i;
	i++;
	while (i != v.end()) {
		os << "," << *i;
		i++;
	}
	return os << "]";
}

size_t main() {
	//std::cout << kmp_table("abacababc");
	std::cout << "answer: " << strStr("mississippi", "issip") << std::endl;
	std::cout << "answer: " << strStr("hello", "ll") << std::endl;
}