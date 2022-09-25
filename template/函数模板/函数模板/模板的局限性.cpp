#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	Person(int age, string name)
	{
		m_age = age;
		m_name = name;
	}


	// 可以使用运算符重载
	bool operator==(Person& p)
	{
		if (m_age == p.m_age && m_name == p.m_name)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int m_age;
	string m_name;
};

template<typename T>
bool cmp(T a, T b)
{
	return a == b;  // 难以使用自定义数据类型
}

// 可以使用具体化Person的模板，遇到时优先调用
template<> bool cmp(Person a, Person b) // 可以删除 template<> ，写成一个普通的函数重载，可优先调用
{
	if (a.m_age == b.m_age && a.m_name == b.m_name)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void test()
{
	Person p1(10, "Tom");
	Person p2(11, "Tom");

	//bool at = cmp(p1, p2);
	bool at = p1 == p2;
	cout << "对比结果为：" << at << endl;
}

int main()
{
	test();

	system("pause");
	return 0;
}