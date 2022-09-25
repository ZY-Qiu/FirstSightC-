//#include <iostream>
//#include <string>
//
//using namespace std;
//
//// 都可以有两个模板参数
//template<class NameType, class AgeType = int> // 类模板中可以有默认参数
//class Person
//{
//public:
//
//	Person(NameType name, AgeType age)
//	{
//		this->m_name = name;
//		this->m_age = age;
//	}
//
//	void ShowPerson()
//	{
//		cout << "Name = " << this->m_name << ", age = " << this->m_age << endl;
//	}
//
//	string m_name;
//	int m_age;
//};
//
//// 1.指定传入类型
//void Print1(Person<string, int> &p)
//{
//	cout << "Name = " << p.m_name << "\tage = " << p.m_age << endl;
//}
//
//// 2.参数模板化，即利用函数模板的自动类型推导
//template<class T1, class T2>
//void Print2(Person<T1, T2>& p)
//{
//	cout << "Name type = " << typeid(T1).name() << endl;
//	cout << "age type = " << typeid(T2).name() << endl;
//}
//
//// 3.将整个类模板化
//template<class T>
//void Print3(T& p)
//{
//	cout << "Name = " << p.m_name << "\tage = " << p.m_age << endl;
//}
//
//void test()
//{
//	//Person p1("Jerry", 23);
//	Person<string, int> p1("Jerry", 2);  // 类模板无法自动类型推导，必须显式指定
//	Print1(p1);
//
//	Person<string> p2("Tom", 3);  // 有默认模板参数，可以只指定一个
//	Print2(p2);
//
//	Person<string, int> p3("Jack", 4);
//	Print3(p3);
//}
//
//int main()
//{
//	test();
//
//	system("pause");
//	return 0;
//}