//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//class Greater
//{
//public:
//	bool operator()(int v1, int v2)
//	{
//		return v1 > v2;
//	}
//};
//
//void test()
//{
//	vector<int> v;
//	v.push_back(10);
//	v.push_back(50);
//	v.push_back(40);
//	v.push_back(20);
//	v.push_back(30);
//
//	// 使用sort算法升序排列
//	sort(v.begin(), v.end());
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//
//	// 使用二元谓词Greater仿函数，改变sort算法策略，实现降序排列
//	// Greater()为匿名函数对象
//	sort(v.begin(), v.end(), Greater());
//	cout << "-----------------------------" << endl;
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
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