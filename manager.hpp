//
//  manager.hpp
//  zgxt
//
//  Created by anker on 2022/10/24.
//

#ifndef manager_hpp
#define manager_hpp
#include <iostream>
#include <stdio.h>
#include "worker.hpp"
using namespace::std;

// 经理类
class Manager :public Worker
{
public:
    Manager(int id, string name, int dId);
    // 展示职工信息
    virtual void showInfo();
    // 获取职工岗位名称
    virtual string getDeptName();
};
#endif /* manager_hpp */
