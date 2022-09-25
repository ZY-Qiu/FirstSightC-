#include <iostream>
#include <fstream>
#include <string>
#include "workerManager.h"
//#include "worker.h"
//#include "employee.h"
//#include "manager.h"
//#include "boss.h"

using namespace std;

int main()
{
	WorkerManager wm;
	
	int choice;
	
	//Worker* w = new Employee(1, 1, "张三");
	//w->showInfo();
	//delete w;
	//w = new Manager(2, 2, "李四");
	//w->showInfo();
	//delete w;
	//w = new Boss(3, 3, "王五");
	//w->showInfo();
	//delete w;

	while (1)
	{
		wm.ShowMenu();

		cout << "请输入您的选择：" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0: // 退出系统
			wm.exitSystem();
			break;
		case 1:
			wm.AddEmp();
			break;
		case 2:
			wm.ShowEmp();
			break;
		case 3:
			wm.DelEmp();
			break;
		case 4:
			wm.ModEmp();
			break;
		case 5:
			wm.FindEmp();
			break;
		case 6:
			wm.SortEmp();
			break;
		case 7:
			wm.Clean_File();
			break;
		default: 
			system("cls");
		}
	}


	system("pause");

	return 0;
}