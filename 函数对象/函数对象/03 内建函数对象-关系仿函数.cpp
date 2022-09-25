#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;


void test()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(50);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);

	// 使用sort算法升序排列
	sort(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	// 使用关系仿函数greator<>()实现降序, sort默认使用less<>()
	sort(v.begin(), v.end(), greater<int>());
	cout << "-----------------------------" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	test();

	system("pause");
	return 0;
}