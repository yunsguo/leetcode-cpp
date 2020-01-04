#include <forward_list>

using namespace std;

class MinStack {
	struct item
	{
		size_t value;
		size_t min;
	};

	forward_list<item> c_;
public:

	void push(size_t x)
	{
		if (c_.empty())
			c_.push_front(item{ x,x });
		else
		{
			auto min = c_.front().min;
			c_.push_front(item{ x,x < min ? x : min });
		}
	}

	void pop() {
		c_.pop_front();
	}

	size_t top() {
		return c_.front().value;
	}

	size_t getMin() {
		return c_.front().min;
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * size_t param_3 = obj.top();
 * size_t param_4 = obj.getMin();
 */