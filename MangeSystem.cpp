#include "MangeSystem.h"
#include <cstdlib>
#include <fstream>

string MangeSystem::filename = "employees.txt";

MangeSystem::MangeSystem()
{
    cout<<"ini MangeSystem"<<endl;
    std::ifstream infile(MangeSystem::filename.c_str(),
                            std::ios_base::in);
    // 使用 string tmp 对象读取，在txt中仅仅保存num
    string tmp_num;
    string tmp_name;
    string tmp_title;
    int index_tmp;
    employee *tmp_e = nullptr;
    infile.seekg(0,std::ios_base::end);
    if(infile.tellg()==0)
    {
        cout<<"empty file"<<endl;
    }
    else
    {
        infile.seekg(0);
        while(!infile.eof())
        {
            infile >> index_tmp;
            infile >> tmp_num;
            infile >> tmp_name;
            infile >> tmp_title;
            if (tmp_title == "employee")
            {
                tmp_e = new employee(tmp_num, tmp_name, tmp_title);
            }
            else if (tmp_title == "manager")
            {
                tmp_e = new manager(tmp_num, tmp_name, tmp_title);
            }
            else{
                tmp_e = new boss(tmp_num, tmp_name, tmp_title);
            }
            add_one(*tmp_e);
        }

    }

}

void MangeSystem::start()
{
}

void MangeSystem::menu()
{
    cout<<"******************"<<endl;
    cout<<"0. exit"<<endl;
    cout<<"1. add "<<endl;
    cout<<"2. show"<<endl;
    cout<<"3. delete by num"<<endl;
    cout<<"4. edit by num "<<endl;
    cout<<"5. find by num or name "<<endl;
    cout<<"6. sort by num "<<endl;
    cout<<"7. empty system "<<endl;
    cout<<"******************"<<endl;
}

void MangeSystem::exit()
{
    std::exit(EXIT_SUCCESS);
}

void MangeSystem::show()
{
    if (staff.size()==0)
    {
        cout<< "the mangeSystem is empty"<<endl;
    }
    else
    {
        for( auto i= staff.begin();i!=staff.end();i++)
        {
            (**i).show_item();
        }
    }
}

void MangeSystem::add_one(const employee& employee_in)
{
    staff.push_back(const_cast<employee*>(&employee_in));
}

void MangeSystem::add_staffs()
{

}
void MangeSystem::remove(const string& num)
{

}
void MangeSystem::edit(const string& num)
{

}

employee& find()
{

}
void MangeSystem::sort()
{

}
void MangeSystem::empty()
{

}