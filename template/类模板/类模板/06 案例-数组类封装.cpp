#include <iostream>
#include <string>
#include "MyArray.hpp"
using namespace std;

void printArr(MyArray<int>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << "arr[" << i << "] = " << arr[i] << endl;
	}
}

void test()
{
	MyArray<int> arr1(5);

	for (int i = 0; i < 5; i++)
	{
		arr1.Push_Back(i);
	}
	printArr(arr1);

	MyArray<int> arr2(arr1);
	arr2.Pop_Back();
	cout << "尾删后数组长度为 " << arr2.getSize() << endl;
	cout << "尾删后数组容量为 " << arr2.getCapacity() << endl;
	printArr(arr2);


	/*MyArray<int> arr2(arr1);

	MyArray<int> arr3(100);

	arr3 = arr2;*/
}

// 测试自定义数据类型
class Person
{
public:
	Person() {};  // 自定义数据类型作模板参数时，必须有默认构造函数

	Person(int age)  // 若写了有参构造函数，编译器便不会提供默认的构造函数；拷贝构造函数同理
	{
		this->m_age = age;
	}

	int m_age;
};

void printPersonArr(MyArray<Person>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << "Person "<< i << " age = " << arr[i].m_age << endl;
	}
}

void test02()
{
	MyArray<Person> arr(100);

	Person p1(1);
	Person p2(2);
	Person p3(3);
	Person p4(4);
	Person p5(5);

	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4);
	arr.Push_Back(p5);

	printPersonArr(arr);

	cout << "数组长度为 " << arr.getSize() << endl;
	cout << "数组容量为 " << arr.getCapacity() << endl;
}


int main()
{
	//test();
	test02();

	system("pause");
	return 0;
}