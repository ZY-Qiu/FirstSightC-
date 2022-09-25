//#include <iostream>
//#include <string>
//
//using namespace std;
//
//template<class T>
//class base
//{
//public:
//	T obj;
//};
//
//class Son : public base<int>  // 继承类模板时需要指定父类模板参数
//{
//
//};
//
//template<class T1, class T2>
//class Son2 : public base<T1>  // 子类在继承时也可以使用类模板来灵活继承父类模板
//{
//public:
//	T2 sub;
//	void print()
//	{
//		cout << "T1 type is " << typeid(T1).name() << endl;
//		cout << "T2 type is " << typeid(T2).name() << endl;
//	}
//};
//
//void test()
//{
//	Son2<int, float> s;
//	s.print();
//}
//
//int main()
//{
//	test();
//
//	system("pause");
//	return 0;
//}