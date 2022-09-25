#pragma once
#include <iostream>
#include <string>
#include "worker.h"

class Boss : public Worker
{
public:
	Boss(int ID, int DeptID, string name);

	void showInfo();

	string getDeptName();
};