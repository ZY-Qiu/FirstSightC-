#include "manager.h"

Manager::Manager(int ID, int DeptID, string name)
{
	this->m_ID = ID;
	this->m_DeptID = DeptID;
	this->m_name = name;
}

void Manager::showInfo()
{
	cout << "职工编号：" << this->m_ID
		<< "\t职工姓名：" << this->m_name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：完成老板交代的任务，并下发任务给员工" << endl;
}

string Manager::getDeptName()
{
	return "经理";
}