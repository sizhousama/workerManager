//
//  main.cpp
//  zgxt
//
//  Created by anker on 2022/10/21.
//

#include <iostream>
#include "workManager.hpp"
#include "worker.hpp"
#include "employee.hpp"
#include "manager.hpp"
#include "boss.hpp"

using namespace::std;

void showMenu()
{
    WorkManager wm;
    int choice = 0;
    while(true)
    {
        wm.Show_Menue();
        cout << "请输入你的选择：" << endl;
        cin >> choice;
        switch(choice)
        {
            case 0:
                wm.exitSystem();
                break;
            case 1:
                wm.addEmp();
                break;
            case 2:
                wm.showEmps();
                break;
            case 3:
                wm.delEmp();
                break;
            case 4:
                wm.upEmp();
                break;
            case 5:
                wm.findEmp();
                break;
            case 6:
                wm.sortEmp();
                break;
            case 7:
                wm.clear();
                break;
            default:
                system("cls");
                break;
        }
        
    }
}

int main() {
    showMenu();
    return 0;
}
