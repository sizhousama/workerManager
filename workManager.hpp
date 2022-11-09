//
//  Header.h
//  zgxt
//
//  Created by anker on 2022/10/21.
//

#ifndef Header_hpp
#define Header_hpp
#include <iostream>
#include <fstream>
#include "worker.hpp"

#define FILENAME "/Users/anker/Desktop/worker/workerManager/workerManager/职工信息.txt"
using namespace::std;

class WorkManager
{
public:
    WorkManager();
    void Show_Menue();
    void exitSystem();
    void addEmp();
    void save();
    int getNum();
    void initEmps();
    void showEmps();
    int isExist(int id);
    void delEmp();
    void upEmp();
    void findEmp();
    void sortEmp();
    void clear();
    ~WorkManager();
    
    int empNum;
    Worker ** empArray;
    bool fileIsEmpty;
};

#endif /* Header_h */
