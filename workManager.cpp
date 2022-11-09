//
//  zgxt.cpp
//  zgxt
//
//  Created by anker on 2022/10/21.
//

#include <stdio.h>
#include <string>
#include "workManager.hpp"
#include "employee.hpp"
#include "manager.hpp"
#include "boss.hpp"

WorkManager::WorkManager()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    if(!ifs.is_open())
    {
        cout << "文件不存在！" << endl;
        this->empNum = 0;
        this->empArray = NULL;
        this->fileIsEmpty = true;
        ifs.close();
        
        return;
    }
    char ch;
    ifs >> ch;
    if(ifs.eof())
    {
        cout << "文件为空！" << endl;
        this->empNum = 0;
        this->empArray = NULL;
        this->fileIsEmpty = true;
        ifs.close();
        
        return;
    }
    int num = this->getNum();
    this->empNum = num;
//    cout << num << endl;
    this->empArray = new Worker *[this->empNum];
    this->initEmps();
}

void WorkManager::Show_Menue()
{
    cout << "******************************************" << endl;
    cout << "*********   欢迎使用职工管理系统！  **********" << endl;
    cout << "*************  0.退出管理程序  *************" << endl;
    cout << "*************  1.增加职工信息  *************" << endl;
    cout << "*************  2.显示职工信息  *************" << endl;
    cout << "*************  3.删除离职职工  *************" << endl;
    cout << "*************  4.修改职工信息  *************" << endl;
    cout << "*************  5.查找职工信息  *************" << endl;
    cout << "*************  6.按照编号排序  *************" << endl;
    cout << "*************  7.清空所有文档  *************" << endl;
    cout << "******************************************" << endl;
    cout << endl;
}

void WorkManager::exitSystem()
{
    cout << "欢迎下次使用！" << endl;
    exit(0);
}

void WorkManager::addEmp()
{
    int addNum = 0;
    cout << "请输入需要添加的职工人数：" << endl;
    cin >> addNum;
    
    int newSize = this->empNum + addNum;
    if(newSize > 0)
    {
        Worker ** newSpace = new Worker*[newSize];
        if(this->empArray != NULL)
        {
            for(int i = 0; i < this->empNum; i++)
            {
                newSpace[i] = this->empArray[i];
            }
        }
        for(int i = 0; i < addNum; i++)
        {
            int id;
            string name;
            int dSelect;
            cout << "请输入第" << i + 1 << "位职工的编号：";
            cin >> id;
            cout << "请输入第" << i + 1 << "位职工的姓名：";
            cin >> name;
            
            cout << "请选择第" << i + 1 << "位职工的职位：" << endl;
            cout << "1.员工" << endl;
            cout << "2.经理" << endl;
            cout << "3.CEO" << endl;
            cin >> dSelect;
            
            Worker * worker = NULL;
            switch(dSelect)
            {
                case 1:
                    worker = new Employee(id, name, dSelect);
                    break;
                case 2:
                    worker = new Manager(id, name, dSelect);
                    break;
                case 3:
                    worker = new Boss(id, name, dSelect);
                    break;
                default:
                    break;
            }
            newSpace[this->empNum + i] = worker;
        }
        // 释放原有内存
        delete[] this->empArray;
        // 指向新内存空间
        this->empArray = newSpace;
        // 更改数量
        this->empNum = newSize;
        
        cout << "成功添加" << addNum << "个新职工！" << endl;
        this->save();
    }
    else
    {
        cout << "输入有误！" << endl;
    }
}

void WorkManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out);
    
    if(!ofs.is_open())
    {
        cout << "文件打开失败！" << endl;
    }
    for(int i = 0; i < this->empNum; i++)
    {
        ofs << this->empArray[i]->id << " " << this->empArray[i]->name << " "  << this->empArray[i]->deptId << endl;
    }
//    cout << "数据写入成功！" << endl;
    ofs.close();
}

int WorkManager::getNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    
    int id;
    string name;
    int dId;
    
    int num = 0;
    while(ifs >> id && ifs >> name && ifs >> dId)
    {
        num++;
    }
    ifs.close();
    
    return num;
}

void WorkManager::initEmps()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    
    int id;
    string name;
    int dId;
    
    int index = 0;
    while(ifs >> id && ifs >> name && ifs >> dId)
    {
        Worker * worker = NULL;
        if(dId == 1)
        {
            worker = new Employee(id, name, dId);
        }
        else if(dId == 2)
        {
            worker = new Manager(id, name, dId);
        }
        else
        {
            worker = new Boss(id, name, dId);
        }
        
        this->empArray[index] = worker;
        index++;
    }
}

void WorkManager::showEmps()
{
    if(this->fileIsEmpty)
    {
        cout << "文件不存在或为空" << endl;
    }
    else
    {
        for(int i = 0; i < this->empNum; i++)
        {
            this->empArray[i]->showInfo();
        }
    }
}

int WorkManager::isExist(int id)
{
    int index = -1;
    for(int i = 0; i < this->empNum; i++)
    {
        if(this->empArray[i]->id == id)
        {
            index = i;
            break;
        }
    }
    return index;
}

void WorkManager::delEmp()
{
    if(this->fileIsEmpty)
    {
        cout << "文件不存在或为空" << endl;
    }
    else
    {
        cout << "请输入要删除的职工编号：" << endl;
        int id;
        cin >> id;
        
        int index = this->isExist(id);
        if(index != -1)
        {
            for(int i = index; i < this->empNum - 1; i++)
            {
                this->empArray[i] = this->empArray[i + 1];
            }
            this->empNum--;
            this->save();
            cout << "删除成功！" << endl;
        }
        else
        {
            cout << "删除失败，未找到该职工！" << endl;
        }
    }
}

void WorkManager::upEmp()
{
    if(this->fileIsEmpty)
    {
        cout << "文件不存在或为空" << endl;
    }
    else
    {
        cout << "请输入要修改的职工编号：" << endl;
        int id;
        cin >> id;
        
        int ret = this->isExist(id);
        if(ret != -1)
        {
            delete this->empArray[ret];
            cout << "查找到编号为" << id << "的职工" << endl;
            cout << "请输入新职工名称：" << endl;
            string name;
            cin >> name;
            
            int dSelect;
            cout << "请选择新职工岗位：" << endl;
            cout << "1.员工" << endl;
            cout << "2.经理" << endl;
            cout << "3.CEO" << endl;
            cin >> dSelect;
            
            Worker * worker = NULL;
            switch(dSelect)
            {
                case 1:
                    worker = new Employee(id, name, dSelect);
                    break;
                case 2:
                    worker = new Manager(id, name, dSelect);
                    break;
                case 3:
                    worker = new Boss(id, name, dSelect);
                    break;
                default:
                    break;
            }
            this->empArray[ret] = worker;
            cout << "修改成功！" << endl;
            this->save();
        }
        else
        {
            cout << "查无此人！" << endl;
        }
    }
}

void WorkManager::findEmp()
{
    if(this->fileIsEmpty)
    {
        cout << "文件不存在或为空" << endl;
    }
    else
    {
        cout << "请选择你要查询的方式" << endl;
        cout << "1.按编号查询" << endl;
        cout << "2.按名称查询" << endl;
        int select;
        cin >> select;
        
        if(select == 1)
        {
            cout << "请输入要查询职工的编号：" << endl;
            int id;
            cin >> id;
            
            int index = this->isExist(id);
            if(index != -1)
            {
                cout << "查找成功，该职工信息如下：" << endl;
                this->empArray[index]->showInfo();
            }
            else
            {
                cout << "查找失败，没有找到该职工！" << endl;
            }
        }
        else
        {
            cout << "请输入要查询的职工姓名：" << endl;
            string name;
            cin >> name;
            
            bool flag = false;
            for(int i = 0;i < this->empNum; i++)
            {
                if(this->empArray[i]->name == name)
                {
                    flag = true;
                    cout << "查找成功，该职工信息如下：" << endl;
                    this->empArray[i]->showInfo();
                }
            }
            if(!flag)
            {
                cout << "查找失败，没有找到该职工！" << endl;
            }
        }
    }
}

void WorkManager::sortEmp()
{
    if(this->fileIsEmpty)
    {
        cout << "文件不存在或为空" << endl;
    }
    else
    {
        cout << "请选择排序规则：" << endl;
        cout << "1.按编号升序" << endl;
        cout << "2.按编号降序" << endl;
        
        int select;
        cin >> select;
        for(int i = 0; i < empNum; i++)
        {
            int minOrMax = i;
            for(int j = i + 1; j < empNum; j++)
            {
                if(select == 1)
                {
                    if(empArray[minOrMax]->id > empArray[j]->id)
                    {
                        minOrMax = j;
                    }
                }
                else{
                    if(empArray[minOrMax]->id < empArray[j]->id)
                    {
                        minOrMax = j;
                    }
                }
            }
            if(i != minOrMax)
            {
                Worker * temp = empArray[i];
                empArray[i] = empArray[minOrMax];
                empArray[minOrMax] = temp;
            }
        }
        cout << "排序成功，结果为：" << endl;
        this->save();
        this->showEmps();
    }
}

void WorkManager::clear()
{
    cout << "确认清空？" << endl;
    cout << "1、确认" << endl;
    cout << "2、返回" << endl;

    int select = 0;
    cin >> select;
    
    if(select == 1)
    {
        ofstream ofs;
        ofs.open(FILENAME, ios::trunc);
        
        if(this->empArray != NULL)
        {
            for(int i = 0; i < empNum; i++)
            {
                if(empArray[i] != NULL)
                {
                    delete empArray[i];
                }
            }
            this->empNum = 0;
            delete[] this->empArray;
            this->empArray = NULL;
            this->fileIsEmpty = true;
        }
        cout << "清空成功！" << endl;
    }
}

WorkManager::~WorkManager()
{
    if(this->empArray != NULL)
    {
        delete[] this->empArray;
    }
}
