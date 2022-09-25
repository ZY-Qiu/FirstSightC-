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
//void test()
//{
//	//Person p1("Jerry", 23);
//	Person<string, int> p1("Jerry", 2);  // 类模板无法自动类型推导，必须显式指定
//	p1.ShowPerson();
//
//	Person<string> p2("Tom", 3);  // 有默认模板参数，可以只指定一个
//	p2.ShowPerson();
//}
//
//int main()
//{
//	test();
//
//	system("pause");
//	return 0;
//}