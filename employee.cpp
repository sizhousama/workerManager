//
//  employee.cpp
//  zgxt
//
//  Created by anker on 2022/10/24.
//
#include <iostream>
#include "employee.hpp"
using namespace::std;

Employee::Employee(int id, string name, int dId)
{
    this->id = id;
    this->name = name;
    this->deptId = dId;
}

void Employee::showInfo()
{
    cout << "职工编号： " << this->id ;
    cout << " \t职工姓名： " << this->name;
    cout << " \t岗位：" << this->getDeptName();
    cout << " \t岗位职责：完成经理交给的任务" << endl;
}

string Employee::getDeptName()
{
    return string("员工");
};
