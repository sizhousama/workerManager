//
//  worker.hpp
//  zgxt
//
//  Created by anker on 2022/10/21.
//

#ifndef worker_h
#define worker_h

#include <stdio.h>
#include <string>
using namespace::std;

class Worker
{
public:
    // 定义基类的析构函数为虚函数，delete 时就可以正确释放内存
    virtual ~Worker(){}
    // 显示员工相信
    virtual void showInfo() = 0;
    // 获取部门名称
    virtual string getDeptName() = 0;
    
    int id;
    string name;
    int deptId;
};


#endif /* worker_hpp */
