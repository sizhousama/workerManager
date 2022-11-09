//
//  employee.hpp
//  zgxt
//
//  Created by anker on 2022/10/24.
//

#ifndef employee_hpp
#define employee_hpp

#include <stdio.h>
#include "worker.hpp"
using namespace::std;

// 员工类
class Employee :public Worker
{
public:
    Employee(int id, string name, int dId);
    // 展示职工信息
    virtual void showInfo();
    // 获取职工岗位名称
    virtual string getDeptName();
};
#endif /* employee_hpp */
