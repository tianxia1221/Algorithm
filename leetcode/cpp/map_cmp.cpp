
#include "pch.h"
#include<queue>
#include<vector>
#include<iostream>
#include<queue>

#include <map>
#include <string>
#include <iostream>
using namespace std;
struct Point { double x, y; };
struct PointCmp {
	bool operator()(const Point& lhs, const Point& rhs) const {
		return lhs.x < rhs.x; // NB. intentionally ignores y
	}
};
int main(void)
{
	std::map<Point, double, PointCmp> mag = {
	 { {5, -12}, 13 },
	 { {3, 4},   5 },
	 { {-8, -15}, 17 }
	};
	for (auto p : mag)
		std::cout << "The magnitude of (" << p.first.x
		<< ", " << p.first.y << ") is "
		<< p.second << '\n';


	//The magnitude of(-8, -15) is 17
	//The magnitude of(3, 4) is 5
	//The magnitude of(5, -12) is 13


	return 0;
}