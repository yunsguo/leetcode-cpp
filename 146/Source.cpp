#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <array>

using namespace std;

class LRUCache
{
	vector<pair<int, size_t>> container;
	unordered_map<int, size_t> map;
	size_t capacity;
	size_t size_;
	size_t access_;
public:
	LRUCache(int capacity) :container(capacity, { 0,-1 }), capacity(capacity), size_(0), access_(0) {}

	int get(int key)
	{
		if (map.count(key) != 1) return -1;
		promote(key);
		return container[map.at(key)].first;
	}

	void put(int key, int value)
	{
		if (map.count(key) == 1)
		{
			promote(key);
			container[map.at(key)].first = value;
			return;
		}

		size_t pos;
		if (size_ == capacity)
			pos = remove();
		else
		{
			pos = size_;
			access_++;
		}
		map[key] = pos;
		container[pos] = { value,access_ };
		size_++;
	}

	size_t remove()
	{
		access_++;
		int key = -1;
		size_t min = access_;
		for (auto p : map)
		{
			auto val = container[p.second].second;
			if (val < min)
			{
				min = val;
				key = p.first;
			}
		}
		size_--;
		size_t result = map.at(key);
		map.erase(key);
		return result;
	}

	void promote(int key)
	{
		access_++;
		container[map.at(key)].second = access_;
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

template<typename ...Ts>
void test(size_t cap, Ts...args)
{
	auto cache = new LRUCache(cap);
	cout << "void";
	test(cache, args...);
}

template<typename ...Ts>
void test(LRUCache* cache, int get_i, Ts...args)
{
	cout << ", " << cache->get(get_i);
	test(cache, args...);
}


template<typename ...Ts>
void test(LRUCache* cache, pair<int, int> put_i, Ts...args)
{
	cache->put(put_i.first, put_i.second);
	cout << ", void";
	test(cache, args...);
}

void test(LRUCache* cache)
{
	delete cache;
	cout << endl;
}

int main()
{
	test(2u, pair<int, int>(1, 1), pair<int, int>(2, 2), 1, pair<int, int>(3, 3), 2, pair<int, int>(4, 4), 1, 3, 4);
	test(2u, pair<int, int>(2, 1), pair<int, int>(2, 2), 2, pair<int, int>(1, 1), pair<int, int>(4, 1), 2);
};