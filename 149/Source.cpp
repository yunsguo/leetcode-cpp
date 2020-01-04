#include <vector>
#include <exception>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include "../leetcode_misc/listcode_misc.h"

using namespace std;
template<typename T>
T gcd(T a,T b)
{
	while (b != 0)
	{
		auto t = b;
		b = a % b;
		a = t;
	}
	return a;
}

struct line
{

	long long int a, b, c;

	line(Point p1, Point p2) :a(p2.y - p1.y), b(p1.x - p2.x), c((long long int)p2.x*p1.y - p1.x*p2.y)
	{
		auto gcd_ = gcd(c, gcd(a, b));
		a /= gcd_; b /= gcd_; c /= gcd_;
	}

	bool on_line(const Point& p)const
	{
		return a * p.x + b * p.y + c == 0;
	}

	bool operator==(const line& other)const { return a == other.a&&b == other.b&&c == other.c; }

};

bool operator==(const Point& p1, const Point& p2) { return p1.x == p2.x &&p1.y == p2.y; }

bool operator!=(const Point& p1, const Point& p2) { return !(p1 == p2); }

template<>
struct std::hash<Point>
{
	size_t operator()(const Point& key) const
	{
		return (key.x * 2) | key.y;
	}
};

template<>
struct std::hash<line>
{
	size_t operator()(const line& l) const
	{
		return ((l.a * 2) | l.b) * 2 | l.c;
	}
};

class Solution
{

	static void try_max(int &max, int can) { if (can > max)max = can; }

	unordered_set<Point> unique_points;
	unordered_map<Point, int> duplicate_points;
	unordered_map<line, int> line_max;
	unordered_map<line, unordered_set<Point>> line_points;

	void insert_line(const Point& p1, const Point&p2)
	{
		line l(p1, p2);

	}

	size_t point_number(const Point& p)
	{
		if (duplicate_points.count(p) == 0) return 1;
		return duplicate_points.at(p);
	}

public:
	int maxPoints(vector<Point>& points)
	{
		if (points.size() == 0) return 0;
		unique_points.clear();
		duplicate_points.clear();
		for (auto p : points)
			if (unique_points.count(p) != 0)
			{
				if (duplicate_points.count(p) == 0)
					duplicate_points[p] = 2;
				else duplicate_points.at(p)++;

			}
			else unique_points.insert(p);
		if (unique_points.size() <= 2) return points.size();
		int max = -1;
		line_max.clear();
		vector<Point> unique;
		for (auto p : unique_points)
			unique.push_back(p);
		while (unique.size() != 0)
		{
			auto p1 = unique.back();
			unique.pop_back();
			for (auto p2 : unique)
			{
				auto l = line(p1, p2);
				auto pn1 = point_number(p1);
				auto pn2 = point_number(p2);
				if (line_max.count(l) == 0)
				{
					line_max[l] = pn1 + pn2;
					unordered_set<Point> set;
					set.insert(p1); set.insert(p2);
					line_points[l] = set;
				}
				else
				{
					if (line_points.at(l).count(p1) == 0)
					{
						line_max.at(l) += pn1;
						line_points.at(l).insert(p1);
					}
					if (line_points.at(l).count(p2) == 0)
					{
						line_max.at(l) += pn2;
						line_points.at(l).insert(p2);
					}
				}
				if (line_max.at(l) > max)max = line_max.at(l);
			}
		}
		return max;
	}
};

void test(vector<Point> points)
{
	Solution s;
	cout
		<< "Input: " << points << endl;
	cout
		<< "Output: " << s.maxPoints(points) << endl;
}
int main()
{
	//test({ {1,1},{2,2},{3,3} });
	//test({ {1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4} });
	//test({ {1,1},{1,1},{1,1} });
	//test({ {0,0},{0,0} });
	//test({ {0, 9}, {138, 429}, {115, 359}, {115, 359}, {-30, -102}, {230, 709}, {-150, -686}, {-135, -613}, {-60, -248}, {-161, -481}, {207, 639}, {23, 79}, {-230, -691}, {-115, -341}, {92, 289}, {60, 336}, {-105, -467}, {135, 701}, {-90, -394}, {-184, -551}, {150, 774} });
	test({ {{0,0},{1,65536},{65536,0}} });
}