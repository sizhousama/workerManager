//
//  boss.hpp
//  zgxt
//
//  Created by anker on 2022/10/24.
//

#ifndef boss_hpp
#define boss_hpp

#include <iostream>
#include <stdio.h>
#include "worker.hpp"
using namespace::std;

// 老板类
class Boss :public Worker
{
public:
    Boss(int id, string name, int dId);
    // 展示职工信息
    virtual void showInfo();
    // 获取职工岗位名称
    virtual string getDeptName();
};
#endif /* boss_hpp */
