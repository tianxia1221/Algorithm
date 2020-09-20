
#include "pch.h"
#include <iostream>
#include <algorithm>  
#include <string>  
#include <vector>       // std::vector

using namespace std;
int op_increase(int i) {
	return ++i;
}

void testTransform() {
	std::vector<int> foo;
	std::vector<int> bar;

	// set some values:
	for (int i = 1; i < 6; i++)
		foo.push_back(i * 10);                         // foo: 10 20 30 40 50

	bar.resize(foo.size());                         // allocate space

	std::transform(foo.begin(), foo.end(), bar.begin(), op_increase);
	// bar: 11 21 31 41 51

	// std::plus adds together its two arguments:
	std::transform(foo.begin(), foo.end(), bar.begin(), foo.begin(), std::plus<int>());
	// foo: 21 41 61 81 101

	std::cout << "foo contains:";
	for (std::vector<int>::iterator it = foo.begin(); it != foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	return;
}
void test1() {
	//#include <algorithm> 
	string strA = "ABC";
	string strB = "xyz";
	printf("Before transform:\n");
	printf("strA:%s \n", strA.c_str());
	printf("strB:%s \n\n", strB.c_str());

	transform(strA.begin(), strA.end(), strA.begin(), ::toupper);
	transform(strB.begin(), strB.end(), strB.begin(), ::toupper);
	printf("After transform to toupper:\n");
	printf("strA:%s \n", strA.c_str());
	printf("strB:%s \n\n", strB.c_str());

	transform(strA.begin(), strA.end(), strA.begin(), tolower);
	transform(strB.begin(), strB.end(), strB.begin(), tolower);
	printf("After transform to lower:\n");
	printf("strA:%s \n", strA.c_str());
	printf("strB:%s \n\n", strB.c_str());
}

void tolowerCase1(string &s) {

	for (int i = 0; i < s.size(); i++)
	{
		s[i] = tolower(s[i]);
	}

	cout << s << endl;
}


void tolowerCase2(string &s) {

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] + 32;
	}

	cout << s << endl;
}

int main()
{
	string s1("ABc");
	string s2("Xyz");
	testTransform();
	test1();
	tolowerCase1(s1);
	tolowerCase2(s2);

	string s3("uvwXYZ");
	printf("strA:%s \n", s3.c_str());
	std::transform(s3.begin(), s3.end(), s3.begin(), tolower);
	printf("After transform to lower:\n");
	printf("strB:%s \n\n", s3.c_str());
	return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file