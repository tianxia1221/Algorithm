#include "pch.h"
#include <iostream>
#include <algorithm>  
#include <string>  
#include <vector>       // std::vector
using namespace std;
 
void splitCommon(const string &str, const string &pattern, vector<string> &res)
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
 
//strtok_s是windows下的一个分割字符串安全函数，其函数原型如下：
//char *strtok_s(char *strToken, const char *strDelimit, char **buf);
//这个函数将剩余的字符串存储在buf变量中，而不是静态变量中，从而保证了安全性。
 
 
//strtok_s函数是linux下分割字符串的安全函数，函数声明如下：
//char *strtok_r(char *str, const char *delim, char **saveptr);
//该函数也会破坏带分解字符串的完整性，但是其将剩余的字符串保存在saveptr变量中，保证了安全性。
 
 
void split(string &str, string &delimiter, vector<string> &ret) {
	ret.clear();
	char *context;
	char *p = strtok_s(const_cast<char*>(str.data()), delimiter.data(), &context);
	while (p != nullptr)
	{
		ret.push_back(string(p));
		p = strtok_s(nullptr, delimiter.data(), &context);
	}
	return;
}
 
int main() {
	string str;
	string delimiter = " ,。";
	vector<string> ret;
 
	cout << "-----------" << endl;
	str = "abc,xyz";
	split(str, delimiter, ret);
	for (auto s : ret) {
		cout << s << endl;
	}
 
	cout << "-----------" << endl;
	str = "HELLO WORLD, abc, xyz 。 ttt,,,mn";
	split(str, delimiter, ret);
	for (auto s : ret) {
		cout << s << endl;
	}
 
	cout << "-----------" << endl;
	str = "HELLO WORLD,abc,xyz";
	splitCommon(str, ",", ret);
	for (auto s : ret) {
		cout << s << endl;
	}
 
	return 0;
}
 
 
 