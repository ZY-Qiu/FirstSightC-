//#include <iostream>
//#include <string>
//
//using namespace std;
//
//template<class T1, class T2>
//class Person
//{
//public:
//	Person(T1 name, T2 age);
//	void show();
//
//	T1 m_name;
//	T2 m_age;
//};
//
//// 类外实现类模板成员函数需要加上模板参数列表
//template<class T1, class T2>
//Person<T1, T2>::Person(T1 name, T2 age)
//{
//	this->m_age = age;
//	this->m_name = name;
//}
//
//template<class T1, class T2>
//void Person<T1, T2>::show()
//{
//	cout << "name is " << m_name << "\tage is " << m_age << endl;
//}
//
//void test()
//{
//	Person<string, int> p("Tom", 10);
//	p.show();
//}
//
//int main()
//{
//	test();
//
//	system("pause");
//	return 0;
//}