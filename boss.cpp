//
//  boss.cpp
//  zgxt
//
//  Created by anker on 2022/10/24.
//
#include <iostream>
#include "boss.hpp"
using namespace::std;

Boss::Boss(int id, string name, int dId)
{
    this->id = id;
    this->name = name;
    this->deptId = dId;
}

void Boss::showInfo()
{
    cout << "职工编号： " << this->id;
    cout << " \t职工姓名： " << this->name;
    cout << " \t岗位：" << this->getDeptName();
    cout << " \t岗位职责：管理公司所有事务" << endl;
}

string Boss::getDeptName()
{
    return string("CEO");
};
