#include "employee.h"

Employee::Employee(int ID, int DeptID, string name)
{
	this->m_ID = ID;
	this->m_DeptID = DeptID;
	this->m_name = name;
}

void Employee::showInfo()
{
	cout << "职工编号：" << this->m_ID
		<< "\t职工姓名：" << this->m_name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：完成经理交代的任务" << endl;
}

string Employee::getDeptName()
{
	return "员工";
}