#include "workerManager.h"

WorkerManager::WorkerManager()
{
	this->m_EmpNum = 0;
	this->m_EmpArray = NULL;
	this->m_FileIsEmpty = 1;

	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		//cout << "无职工文件" << endl;
		ifs.close();
	}
	else 
	{
		char ch;
		ifs >> ch;
		if (ifs.eof())
		{
			//cout << "文件为空！" << endl;
			ifs.close();
		}
		else
		{
			this->m_FileIsEmpty = 0;
			this->getEmpNum();

			this->m_EmpArray = new Worker * [this->m_EmpNum];
			this->init_Emp();
		}
	}
}

void WorkerManager::ShowMenu()
{
	cout << "***********************************************" << endl;
	cout << "*********** 欢迎使用职工管理系统！ ************" << endl;
	cout << "*************** 0.退出管理程序 ****************" << endl;
	cout << "*************** 1.增加职工信息 ****************" << endl;
	cout << "*************** 2.显示职工信息 ****************" << endl;
	cout << "*************** 3.删除离职职工 ****************" << endl;
	cout << "*************** 4.修改职工信息 ****************" << endl;
	cout << "*************** 5.查找职工信息 ****************" << endl;
	cout << "*************** 6.按照编号排序 ****************" << endl;
	cout << "*************** 7.清空所有文档 ****************" << endl;
	cout << "***********************************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::AddEmp()
{
	cout << "请输入添加的职工的数量：" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		int newSize = this->m_EmpNum + addNum;
		Worker** newSpace = new Worker * [newSize];

		// 拷贝原数据
		if (this->m_EmpNum != 0)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		// 添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			int dep;
			string name;

			while (1)
			{
				cout << "请输入第" << i+1 << "个新职工的编号" << endl;
				cin >> id;
				int index = this->isExist(id);
				if (index == -1)
				{
					break;
				}
				else
				{
					cout << "该职工编号已存在，请重新输入！" << endl;
				}
			}
			cout << "请输入第" << i+1 << "个新职工的姓名" << endl;
			cin >> name;
			cout << "请输入第" << i+1 << "个新职工的部门" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dep;
			
			Worker* w = NULL;
			switch (dep)
			{
			case 1:
				w = new Employee(id, dep, name);
				break;
			case 2:
				w = new Manager(id, dep, name);
				break;
			case 3:
				w = new Boss(id, dep, name);
				break;
			default:
				break;
			}
			
			newSpace[m_EmpNum + i] = w;
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = newSpace;
		this->m_EmpNum = newSize;
		cout << "成功添加" << addNum << "名新职工" << endl;
		this->save();
	}
	else
	{
		cout << "输入数据有误" << endl;
		system("cls");
	}
	system("pause");
	system("cls");
}

void WorkerManager::ShowEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "无职工信息文件或为空！" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out | ios::trunc);

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_ID << " "
			<< this->m_EmpArray[i]->m_name << " "
			<< this->m_EmpArray[i]->m_DeptID << endl;
	}
	ofs.close();
	this->m_FileIsEmpty = false;
}

void WorkerManager::getEmpNum()
{
	int id;
	int did;
	string name;
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		this->m_EmpNum++;
	}
	//cout << "职工人数为：" << this->m_EmpNum << endl;
	
}

void WorkerManager::init_Emp()
{
	int id;
	int did;
	string name;
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	Worker* worker = NULL;
	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> did)
	{
		switch(did)
		{
		case 1:
			worker = new Employee(id, did, name);
			break;
		case 2:
			worker = new Manager(id, did, name);
			break;
		case 3:
			worker = new Boss(id, did, name);
			break;
		default:
			break;
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

void WorkerManager::DelEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "无职工信息" << endl;
	}
	else
	{
		cout << "请输入删除职工的编号：" << endl;
		int id;
		cin >> id;
	
		int index = this->isExist(id);
		if (index != -1)
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			this->save();

			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "删除失败，该职工编号不存在！" << endl;
		}
	}
	
	system("pause");
	system("cls");
}

int WorkerManager::isExist(int id)
{
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (id == this->m_EmpArray[i]->m_ID)
		{
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::ModEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "无职工信息" << endl;
	}
	else
	{
		cout << "请输入修改职工的编号：" << endl;
		int id;
		cin >> id;

		int index = this->isExist(id);
		if (index != -1)
		{
			int nid;
			string name;
			int did;
			
			cout << "查到" << id << "号职工，请输入新职工编号" << endl;
			cin >> nid;
			cout << "原职工名：" << this->m_EmpArray[index]->m_name << "，请输入新职工姓名" << endl;
			cin >> name;
			cout << "原职工部门：" << this->m_EmpArray[index]->m_DeptID << "，请输入新职工部门" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> did;

			delete this->m_EmpArray[index];
			Worker* w = NULL;
			
			switch (did)
			{
			case 1:
				w = new Employee(nid, did, name);
				break;
			case 2:
				w = new Manager(nid, did, name);
				break;
			case 3:
				w = new Boss(nid, did, name);
				break;
			default:
				break;
			}
			this->m_EmpArray[index] = w;

			this->save();

			cout << "职工编号：" << id << " 修改成功！" << endl;
		}
		else
		{
			cout << "修改失败，该职工编号不存在！" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::FindEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "无职工信息" << endl;
	}
	else
	{
		cout << "请输入查找的方式：" << endl;
		cout << "1.按职工编号查找" << endl;
		cout << "2.按姓名查找" << endl;

		int select;
		cin >> select;

		if (select == 1)
		{
			cout << "请输入查找的职工编号：" << endl;
			int id;
			cin >> id;

			int index = this->isExist(id);
			if (index != -1)
			{
				cout << "查找成功！该职工信息如下：" << endl;
				this->m_EmpArray[index]->showInfo();
			}
			else
			{
				cout << "查找失败，查无此人！" << endl;
			}
		}
		else if (select == 2)
		{
			cout << "请输入查找的职工姓名：" << endl;
			string name;
			cin >> name;
			bool flag = false;

			for(int i = 0; i < this->m_EmpNum; i++)
			{
				if (name == this->m_EmpArray[i]->m_name)
				{
					cout << "查找成功！职工编号为" << this->m_EmpArray[i]->m_ID
						<< "号的信息如下：" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if(!flag)
			{
				cout << "查找失败，查无此人！" << endl;
			}
		}
		else
		{
			cout << "选择查找方式有误" << endl;
		}	
	}
	system("pause");
	system("cls");
}

void WorkerManager::SortEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "无职工信息" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式：" << endl;
		cout << "1.按职工编号升序" << endl;
		cout << "2.按职工编号降序" << endl;

		int select;
		cin >> select;

		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int MinOrMax = i;
			for (int j = i+1; j < this->m_EmpNum; j++)
			{
				if(select == 1)
				{
					if (this->m_EmpArray[j]->m_ID < this->m_EmpArray[MinOrMax]->m_ID)
					{
						MinOrMax = j;  // Here is min
					}
				}
				else if (select == 2)
				{
					if (this->m_EmpArray[j]->m_ID > this->m_EmpArray[MinOrMax]->m_ID)
					{
						MinOrMax = j;  // Here is max
					}
				}
			}
			Worker* w = this->m_EmpArray[i];
			this->m_EmpArray[i] = this->m_EmpArray[MinOrMax];
			this->m_EmpArray[MinOrMax] = w;
		}
		
		if(select != 1 && select != 2)
		{
			cout << "选择排序方式有误" << endl;
			system("pause");
			system("cls");
		}
		else
		{
			this->save();
			cout << "排序成功，排序后结果为：" << endl;
			this->ShowEmp();
		}
	}
}

void WorkerManager::Clean_File()
{
	cout << "确认清空吗？" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;

	int sel;
	cin >> sel;

	if (sel == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			delete this->m_EmpArray[i];
			this->m_EmpArray[i] = NULL;
		}
		delete [] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}