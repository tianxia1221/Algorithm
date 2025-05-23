
#include "pch.h"
#include<queue>
#include<vector>
#include<iostream>
#include<queue>
using namespace std;

struct pos {
	int x, y;
	pos(int x, int y) :x(x), y(y) {}
	pos() {}
	bool operator < (const pos &that) const
	{
		if (x == that.x) return y < that.y;
		return x < that.x;
	}
};

struct Node {
	int x, y;
	Node(int x, int y) :x(x), y(y) {}
	Node() {}
};

struct struct_cmp {
	bool operator()(const Node &a, const Node &b) {
		return a.x > b.x;
	}
};

class class_cmp {
public:
	bool operator()(const Node &a, const Node &b) {
		return a.x > b.x;
	}
};

bool fun_cmp(const Node &a, const Node &b) {
	return a.x > b.x;
}

int main()
{
	vector<Node> arr(3);
	arr[0] = { 1, 1 };
	arr[1] = { 10, 10 };
	arr[2] = { 5, 5 };
	sort(arr.begin(), arr.end(), struct_cmp());
	for (auto i : arr) cout << "x:" << i.x << "  y:" << i.y << " :struct_cmp" << endl;
	cout << "---------------" << endl;

	sort(arr.begin(), arr.end(), class_cmp());
	for (auto i : arr) cout << "x:" << i.x << "  y:" << i.y << " :class_cmp" << endl;
	cout << "---------------" << endl;

	sort(arr.begin(), arr.end(), fun_cmp);
	for (auto i : arr) cout << "x:" << i.x << "  y:" << i.y << " :fun_cmp" << endl;
	cout << "---------------" << endl;

	vector<pos> arr1;
	arr1.push_back(pos(10, 3));
	arr1.push_back(pos(20, 3));
	arr1.push_back(pos(0, 3));
	arr1.push_back(pos(0, 4));
	arr1.push_back(pos(1, 4));
	arr1.push_back(pos(1, 3));

	sort(arr1.begin(), arr1.end());
	for (auto i : arr1) cout << "x:" << i.x << "  y:" << i.y << " :default" << endl;
	cout << "---------------" << endl;

	//x:10  y : 10 : struct_cmp
	//x : 5  y : 5 : struct_cmp
	//x : 1  y : 1 : struct_cmp
	//-------------- -
	//x : 10  y : 10 : class_cmp
	//x : 5  y : 5 : class_cmp
	//x : 1  y : 1 : class_cmp
	//-------------- -
	//x : 10  y : 10 : fun_cmp
	//x : 5  y : 5 : fun_cmp
	//x : 1  y : 1 : fun_cmp
	//-------------- -
	//x : 0  y : 3 : default
	//x : 0  y : 4 : default
	//x : 1  y : 3 : default
	//x : 1  y : 4 : default
	//x : 10  y : 3 : default
	//x : 20  y : 3 : default
	//-------------- -

	return 0;
}