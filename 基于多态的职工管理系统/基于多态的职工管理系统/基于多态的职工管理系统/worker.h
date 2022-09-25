#pragma once
#include<iostream>
#include<string>
using namespace std;

class Worker
{
public:
	
	virtual void showInfo() = 0;
	virtual string getDeptName() = 0;

	int m_ID;
	int m_DeptID;
	string m_name;
};