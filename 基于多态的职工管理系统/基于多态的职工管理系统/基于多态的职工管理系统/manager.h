#pragma once
#include <iostream>
#include <string>
#include "worker.h"

class Manager : public Worker
{
public:
	Manager(int ID, int DeptID, string name);

	void showInfo();

	string getDeptName();
};