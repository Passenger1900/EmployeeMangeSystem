#include "MangeSystem.h"
#include <cstdlib>
#include <fstream>

string MangeSystem::filename = "employees.txt";

MangeSystem::MangeSystem()
{
    std::ifstream read_file;

    cout<<"ini MangeSystem"<<endl;
    cout<<"found elemets in xxx.txt"<<endl;
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
            (*i).show_item();
        }
    }
}

employee& MangeSystem::add_one(const employee& employee_in)
{

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