//#include <iostream>
//using namespace std;
//
//void func(int a, int b)
//{
//	cout << "调用普通函数" << endl;
//}
//
//template<typename T>
//void func(T a, T b)
//{
//	cout << "调用模板函数" << endl;
//}
//
//template<typename T>
//void func(T a, T b, T c)
//{
//	cout << "调用重载模板函数" << endl;
//}
//
//void test()
//{
//	int a = 1;
//	int b = 3;
//	
//	func(a, b);  // 优先调用普通函数
//	func<>(a, b);  // 使用空模板参数列表，可调用模板函数
//	func(a, b, b); // 模板函数重载
//
//	char c = 'c';
//	char d = 'd';
//	func(c, d);  // 优先匹配
//}
//
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}