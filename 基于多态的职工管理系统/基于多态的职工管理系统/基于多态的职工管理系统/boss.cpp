#include "boss.h"

Boss::Boss(int ID, int DeptID, string name)
{
	this->m_ID = ID;
	this->m_DeptID = DeptID;
	this->m_name = name;
}

void Boss::showInfo()
{
	cout << "职工编号：" << this->m_ID
		<< "\t职工姓名：" << this->m_name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：压榨底层" << endl;
}

string Boss::getDeptName()
{
	return "老板";
}