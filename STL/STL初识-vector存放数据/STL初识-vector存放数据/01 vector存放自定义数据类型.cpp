//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//class Person
//{
//public:
//	Person(int age, string name)
//	{
//		this->m_age = age;
//		this->m_name = name;
//	}
//
//	int m_age;
//	string m_name;
//};
//
//void print(Person &p)
//{
//	cout << "Age is " << p.m_age << "\tname is " << p.m_name << endl;
//}
//
//void test1()
//{
//	vector<Person> v;
//
//	Person p1(10, "a");
//	Person p2(20, "b");
//	Person p3(30, "c");
//
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//
//	// 使用while输出
//	/*vector<Person>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << "Age is " << it->m_age << "\tname is " << it->m_name << endl;
//		++it;
//	}*/
//
//	// 使用for输出
//	/*for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << "Age is " << it->m_age << "\tname is " << it->m_name << endl;
//	}*/
//
//	// 使用for_each输出
//	for_each(v.begin(), v.end(), print);
//}
//
//void print2(Person* p)
//{
//	cout << "Age is " << p->m_age << "\tname is " << p->m_name << endl;
//}
//
//void test2()
//{
//	vector<Person*> v;
//
//	Person p1(10, "a");
//	Person p2(20, "b");
//	Person p3(30, "c");
//
//	v.push_back(&p1);
//	v.push_back(&p2);
//	v.push_back(&p3);
//
//	// for
//	/*for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << "Age is " << (**it).m_age << "\tname is " << (**it).m_name << endl;
//	}*/
//
//	// for_each
//	for_each(v.begin(), v.end(), print2);
//}
//
//int main()
//{
//	test2();
//
//	system("pause");
//	return 0;
//}