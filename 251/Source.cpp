#include <vector>

using namespace std;

class Vector2D
{
	vector<vector<int>>::const_iterator i;
	vector<int>::const_iterator j;
	vector<vector<int>> v_;

public:
	Vector2D(vector<vector<int>>& v) :v_(v)
	{
		i = v_.cbegin();
		while (i != v_.cend())
		{
			j = i->cbegin();
			if (j == i->cend())
				i++;
			else break;
		}
	}

	int next()
	{
		auto result = *j;
		j++;
		hasNext();
		return result;
	}

	bool hasNext()
	{
		if (i == v_.cend()) return false;
		if (j != i->cend()) return true;
		while (i != v_.cend())
		{
			if (j == i->cend())
			{
				i++;
				if (i == v_.cend())
					return false;
				j = i->cbegin();
			}
			else return true;
		}
		return false;
	}
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main()
{
	//vector<vector<int>> v({ {0} });
	//vector<vector<int>> v({ {},{3} });
	vector<vector<int>> v({ {1,2},{3},{4} });
	Vector2D test(v);
	test.next();
	test.next();
	test.next();
	test.hasNext();
	test.hasNext();
	test.next();
	test.hasNext();
}