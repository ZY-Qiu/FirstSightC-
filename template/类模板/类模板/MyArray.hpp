#pragma once
#include <iostream>

using namespace std;

template<class T>
class MyArray
{
public:
	MyArray(int capacity);

	MyArray(const MyArray& arr);

	MyArray& operator=(const MyArray& arr);

	void Push_Back(const T& val);

	void Pop_Back();

	T& operator[](int index);

	int getCapacity();

	int getSize();

	~MyArray();
private:

	T* paddr; // 指向堆区开辟的数组

	int m_capacity;  // 容量

	int m_size;  // 数组大小
};


template<class T>
MyArray<T>::MyArray(int capacity)
{
	cout << "有参构造调用" << endl;
	this->m_capacity = capacity;
	this->m_size = 0;
	this->paddr = new T[capacity];
}

// 深拷贝 构造函数
template<class T>
MyArray<T>::MyArray(const MyArray& arr)
{
	cout << "拷贝构造调用" << endl;
	this->m_capacity = arr.m_capacity;
	this->m_size = arr.m_size;
	this->paddr = new T[arr.m_capacity];

	for (int i = 0; i < arr.m_size; i++)
	{
		this->paddr[i] = arr.paddr[i];
	}
}

// 重载运算符 =
template<class T>
MyArray<T>& MyArray<T>::operator=(const MyArray& arr)
{
	cout << "operator=的调用" << endl;
	if (this->paddr != NULL)
	{
		this->m_capacity = 0;
		this->m_size = 0;
		delete[] this->paddr;
		this->paddr = NULL;
	}

	this->m_capacity = arr.m_capacity;
	this->m_size = arr.m_size;
	this->paddr = new T(arr.m_capacity);

	for (int i = 0; i < arr.m_size; i++)
	{
		this->paddr[i] = arr.paddr[i];
	}
	return *this;
}

// 尾插法
template<class T>
void MyArray<T>::Push_Back(const T& val)
{
	if (this->m_capacity == this->m_size)
	{
		cout << "容量已满，无法添加！" << endl;
		return;
	}
	this->paddr[this->m_size] = val;
	this->m_size++;
}

// 尾删法
template<class T>
void MyArray<T>::Pop_Back()
{
	if (this->m_size == 0)
	{
		cout << "数组为空，无法删除" << endl;
		return;
	}
	this->m_size--;
}


// 重载运算符[]，使得可以通过下标访问数据
template<class T>
T& MyArray<T>::operator[](int index)
{
	if (index < 0 || index >= this->m_size)
	{
		cout << "Index out of range!" << endl;
		return this->paddr[0];
	}
	return this->paddr[index];
}

template<class T>
int MyArray<T>::getCapacity()
{
	return this->m_capacity;
}

template<class T>
int MyArray<T>::getSize()
{
	return this->m_size;
}

template<class T>
MyArray<T>::~MyArray()
{
	if (this->paddr != NULL)
	{
		cout << "析构函数调用" << endl;
		delete[] this->paddr;
		this->paddr = NULL;
	}
	
}