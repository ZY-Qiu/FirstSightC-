#pragma once
#include <iostream>
#include <fstream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;

#define FILENAME "empFile.txt"

class WorkerManager
{
public:
	WorkerManager();

	void ShowMenu();

	void exitSystem();

	void AddEmp();

	void save();

	void getEmpNum();

	void init_Emp();

	void ShowEmp();

	void DelEmp();

	void ModEmp();

	void FindEmp();

	void SortEmp();

	int isExist(int id);

	void Clean_File();

	~WorkerManager();

	int m_EmpNum; // employer number

	Worker** m_EmpArray;

	bool m_FileIsEmpty;
};