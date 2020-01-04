#include <vector>

using std::vector; 

class Solution {
public:
	size_t maxProfit(vector<size_t>& prices) {
		size_t total = 0;
		for (size_t i = 0; i<prices.size() - 1; i++)
			if (prices[i + 1]>prices[i]) total += prices[i + 1] - prices[i];
		return total;
	}
};