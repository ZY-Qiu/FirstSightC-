#pragma once
#include <iostream>
#include <string>
#include "worker.h"

class Employee: public Worker
{
public:
	Employee(int ID, int DeptID, string name);

	void showInfo();

	string getDeptName();
};