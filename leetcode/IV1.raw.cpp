#include "pch.h"
#include <iostream>
#include <algorithm>  
#include <string>  
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

#include <algorithm> 

using namespace std;

struct Node {

	string key;
	int count;
	
	Node() {
	}

	Node(string key, int count) {
		key = key;
		count = count;
	}

	bool operator > (Node a)  {   

		
		if (a.count == count) {
			return key > a.key;
		}
		return count > a.count;
	}

};

class mycomparison
{
public:
	bool operator() (const Node& a, const Node& b) const
	{
		if (a.count == b.count) {
			return b.key > a.key;
		}
		return a.count > b.count;
	}
};

class IV1 {
public:
	static vector<string> retFs(int numFs,
		int topFs,
		vector<string> possibleFs,
		int numReqs,
		vector<string> reqs)
	{

		unordered_map<string, int> hm;
		unordered_map<string, string> caseHm;
		vector<string> arr;
		string key;
		priority_queue<Node, vector<Node>, mycomparison> smallQ;
		Node node;
		mycomparison cmp;

		if (topFs > numReqs) topFs = numReqs;
		if (topFs == 0) return vector<string>();

		for (int i = 0; i < numFs; i++) {
			string str = possibleFs[i];
			transform(str.begin(), str.end(), str.begin(), tolower);

			hm[str] = 0;
			caseHm[str] = possibleFs[i];
		}

		for (int i = 0; i < numReqs; i++) {
			unordered_set<string> hs;
			splitCommon(reqs[i], " ", arr);
			for (int j = 0; j < arr.size(); j++) {
				transform(arr[j].begin(), arr[j].end(), arr[j].begin(), tolower);
				if (hm.find(arr[j]) == hm.end()) continue;
				if (hs.find(arr[j]) != hs.end()) continue;
				hs.insert(arr[j]);
				hm[arr[j]] = hm[arr[j]] + 1;
			}
		}

		for (auto it = hm.begin(); it!=hm.end(); it++) {
			cout << it->first << " " << it->second << endl;
			node.key = it->first;
			node.count = it->second;;
			if (topFs > 0) {
				smallQ.push(node);
				topFs--;
				continue;
			}
		//	if (node > smallQ.top()) {
			if (cmp(node, smallQ.top()) ) {
				smallQ.pop();
				smallQ.push(node);
			}
		}

		cout << "-------------" << endl;

		vector<string> ret(smallQ.size());
		for (int i = smallQ.size() - 1; i >= 0; i--) {
			cout << caseHm[smallQ.top().key] << " " << smallQ.top().count << endl;
			ret[i] = caseHm[smallQ.top().key];
			smallQ.pop();
		}


		return ret;
	}


	static void splitCommon(const string &str, const string &pattern, vector<string> &res)
	{
		string strs = str + pattern;
		size_t pos = strs.find(pattern);

		res.clear();
		if (str == "")
			return;

		while (pos != strs.npos)
		{
			string temp = strs.substr(0, pos);
			res.push_back(temp);
			strs = strs.substr(pos + 1, strs.size());
			pos = strs.find(pattern);
		}

		return;
	}
};


int main() {

	int numFs = 6;
	int topFs = 3;

	vector<string> possibleFs;
	possibleFs.push_back("hover");
	possibleFs.push_back("DELL");
	possibleFs.push_back("emc");

	possibleFs.push_back("VMWare");
	possibleFs.push_back("HP");
	possibleFs.push_back("solar");

	int nReqs = 7;

	vector<string> reqs;
	reqs.push_back("even more dell");
	reqs.push_back("emc life");
	reqs.push_back("HP");
	reqs.push_back("HP emc two IBM");
	reqs.push_back("HP please hp");
	reqs.push_back("net hover");
	reqs.push_back("solar power");

	vector<string> ret = IV1::retFs(numFs, topFs, possibleFs, nReqs, reqs);
	for (auto s : ret) cout << s << endl;

}


