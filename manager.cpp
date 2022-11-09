//
//  manager.cpp
//  zgxt
//
//  Created by anker on 2022/10/24.
//
#include <iostream>
#include "manager.hpp"
using namespace::std;

Manager::Manager(int id, string name, int dId)
{
    this->id = id;
    this->name = name;
    this->deptId = dId;
}

void Manager::showInfo()
{
    cout << "职工编号： " << this->id;
    cout << " \t职工姓名： " << this->name;
    cout << " \t岗位：" << this->getDeptName();
    cout << " \t岗位职责：完成老板交给的任务,并下发任务给员工" << endl;
}

string Manager::getDeptName()
{
    return string("经理");
};
