//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <functional>
//
//using namespace std;
//
//void test()
//{
//	vector<bool> v;
//	v.push_back(true);
//	v.push_back(false);
//	v.push_back(true);
//	v.push_back(false);
//
//	for (vector<bool>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//
//	vector<bool> v2;
//	v2.resize(v.size());
//	// 使用transform算法搬运至另一容器中
//	// 并使用logical_not<>()仿函数取反
//	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
//	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//int main()
//{
//	test();
//
//	system("pause");
//	return 0;
//}