
#include "pch.h"
#include<queue>
#include<vector>
#include<iostream>
#include<queue>
using namespace std;
//way1:
struct Node1 {
	int x, y;
	bool operator <(Node1 a) const {
		return x < a.x;
	}
	bool operator >(Node1 a) const {
		return x > a.x;
	}
};

//way2
struct Node {
	int x;
	int y;
	//friend  bool operator<(const Node &a, const Node &b) {
	//	return  a.x < b.x;  //大顶堆
	//}
	//friend  bool operator>(const Node &a, const Node &b) {
	//	return  a.x > b.x;  //小顶堆
	//}
};
//way 3
bool operator<(const Node &a, const Node &b) {
	return a.x < b.x;          //大顶堆
}

bool operator>(const Node &a, const Node &b) {
	return a.x > b.x;         //小顶堆
}

//way4
struct struct_cmp {
	bool operator()(Node a, Node b) {
		return  a.x > b.x;  //小顶堆
	}
};

//way5
class class_cmp {
public:
	bool operator()(Node a, Node b) {
		return  a.x > b.x;  //小顶堆
	}
};

int main()
{
	//  priority_queue<Node1> A;   //默认  大根堆
	priority_queue<Node1, vector<Node1>, less<Node1>> pq1;    //大根堆
	priority_queue<Node1, vector<Node1>, greater<Node1> > pq2;    //小根堆
	pq1.push(Node1{ 10, 2 });
	pq1.push(Node1{ 30, 2 });
	pq1.push(Node1{ 20, 2 });
	
	while (pq1.size() != 0) {
		cout << pq1.top().x << endl;
		pq1.pop();
	}
	cout << "---------------" << endl;

	pq2.push(Node1{ 10, 2 });
	pq2.push(Node1{ 30, 2 });
	pq2.push(Node1{ 20, 2 });

	while (pq2.size() != 0) {
		cout << pq2.top().x << endl;
		pq2.pop();
	}
	cout << "---------------" << endl;
	//  priority_queue<Node> A;   //默认  大根堆
	priority_queue<Node, vector<Node>, less<Node>> pq3;    //大根堆
	priority_queue<Node, vector<Node>, greater<Node> > pq4;    //小根堆
	pq3.push(Node{ 10, 2 });
	pq3.push(Node{ 30, 2 });
	pq3.push(Node{ 20, 2 });

	while (pq3.size() != 0) {
		cout << pq3.top().x << endl;
		pq3.pop();
	}
	cout << "---------------" << endl;

	pq4.push(Node{ 10, 2 });
	pq4.push(Node{ 30, 2 });
	pq4.push(Node{ 20, 2 });

	while (pq4.size() != 0) {
		cout << pq4.top().x << endl;
		pq4.pop();
	}
	cout << "---------------" << endl;

	priority_queue<Node, vector<Node>, struct_cmp > pq5;      //大根堆
	priority_queue<Node, vector<Node>, class_cmp > pq6;    //小根堆
	pq5.push(Node{ 10, 2 });
	pq5.push(Node{ 30, 2 });
	pq5.push(Node{ 20, 2 });

	while (pq5.size() != 0) {
		cout << pq5.top().x << endl;
		pq5.pop();
	}
	cout << "---------------" << endl;

	pq6.push(Node{ 10, 2 });
	pq6.push(Node{ 30, 2 });
	pq6.push(Node{ 20, 2 });

	while (pq6.size() != 0) {
		cout << pq6.top().x << endl;
		pq6.pop();
	}
	cout << "---------------" << endl;


		//30
		//20
		//10
		//-------------- -
		//10
		//20
		//30
		//-------------- -
		//30
		//20
		//10
		//-------------- -
		//10
		//20
		//30
		//-------------- -
		//10
		//20
		//30
		//-------------- -
		//10
		//20
		//30
		//-------------- -
}