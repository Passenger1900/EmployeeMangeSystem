#include "MangeSystem.h"
#include <algorithm>
#include <cstdlib>
#include <fstream>

string MangeSystem::filename = "employees.txt";
using std::cin;
using std::cout;
using std::endl;
MangeSystem::MangeSystem()
{
    cout<<"ini MangeSystem"<<endl;
    read_file();

}

MangeSystem::~MangeSystem()
{
    // 释放vector中所有用new申请的内存
    for(auto i=staff.begin();i!=staff.end();i++)
    {
        delete *i;
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

void MangeSystem::add_one(const string& tmp_num,
                            const string& tmp_name,
                            const string& tmp_title)
{
    employee* tmp_e = nullptr;
    if (tmp_title == "employee")
    {
        tmp_e = new employee(tmp_num, tmp_name, tmp_title);
    }
    else if (tmp_title == "manager")
    {
        tmp_e = new manager(tmp_num, tmp_name, tmp_title);
    }
    else
    {
        tmp_e = new boss(tmp_num, tmp_name, tmp_title);
    }
    staff.push_back(const_cast<employee*>(tmp_e));
}

void MangeSystem::add_staffs()
{
    int tmp_count=0;
    cout<<"please input the num of staffs "<<endl;
    cin>>tmp_count;
    string tmp_num;
    string tmp_name;
    string tmp_title;
    while((tmp_count--)>0)
    {
        cout<<"input num"<<endl;
        cin >> tmp_num;
        cout<<"input name"<<endl;
        cin >> tmp_name;
        cout<<"input title: \n 0 for employee\n 1 for manager\n 2 for boss"<<endl;
        cin >> tmp_title;
        add_one(tmp_num,tmp_name,tmp_title);
    }
}

void MangeSystem::remove(const string& num)
{
    auto index = find(num);
    if(index ==-1)
    {
        cout<<"not in "<<endl;
    }
    else
    {
        delete staff[index];
        staff[index] = nullptr;
        staff.erase(staff.begin()+index);

    }
    update_file();
}

void MangeSystem::edit(const string& num)
{
    auto index = find(num);
    if(index ==-1)
    {
        cout<<"not in "<<endl;
    }
    else
    {
        string tmp_num;
        string tmp_name;
        string tmp_title;
        cout<<"the information you want change is ?"<<endl;
        (*staff[index]).show_item();
        cout<<"new num is ? 0 for nochange"<<endl;
        cin>>tmp_num;
        if(tmp_num == "0")
        {
            tmp_num = staff[index]->num_out();
        }

        cout<<"new name is ? 0 for nochange"<<endl;
        cin>> tmp_name;
        if(tmp_name == "0")
        {
            tmp_name = staff[index]->name_out();
        }
        
        cout<<"new title is ? 0 for nochange"<<endl;
        cout<<"1 , 2 ,3  for emloyee,manageer,boss"<<endl;
        cin>>tmp_title;
        if(tmp_title== "0")
        {
            tmp_title == staff[index]->title_out();
        }

        employee * new_item = nullptr;
        if(tmp_title == "1")
        {
            new_item = new employee(tmp_num,tmp_name);
        }
        else if (tmp_title== "2")
        {
            new_item = new manager(tmp_num,tmp_name);
        }
        else
        {
            new_item = new boss(tmp_num,tmp_name);
        }

        auto tmp_ptr = staff[index];
        staff[index] = new_item;
        delete tmp_ptr;
        tmp_ptr = nullptr;
    }
    update_file();
}



int MangeSystem::find(const string& input_tmp,int mode=0)
{
    // 默认mode0，按照num查找
    if(mode==0)
    {
       auto it = std::find_if(staff.begin(),staff.end(),
            [&](employee* tmp){return (*tmp).num_out()== input_tmp;});
        if(it!= staff.end())
        {
            auto index = std::distance(staff.begin(),it);
            return index;
        }
        else
        {
            return -1;
        }
    }
    else if(mode ==1)
    {
        auto it = std::find_if(staff.begin(), staff.end(),
                               [&](employee *tmp)
                               { return (*tmp).num_out() == input_tmp; });
        if(it!= staff.end())
        {
            auto index = std::distance(staff.begin(),it);
            return index;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        cout<<"wrong input mode ,should in {0 , 1}"<<endl;
    }
}

void MangeSystem::find_person()
{
    cout<<"0 for num search/n 1 for name search"<<endl;
    int search_mode=0;
    cin>> search_mode;
    string input_tmp;
    if(search_mode==0)
    {
        cout << "input the num" << endl;
        cin >> input_tmp;
    }
    else
    {
        cout<<"input the name"<<endl;
        cin>>input_tmp;
    }
    auto result = find(input_tmp,search_mode);
    if(result == -1) 
    {
        cout<<"not in"<<endl;
    }
    else
    {
        staff[result]->show_item();
    }
}


void MangeSystem::sort()
{
    cout<<"1 for ascending sort\n,2 for descending sort"<<endl;
    int mode;
    cin>>mode;
    if(mode == 1)
        std::sort(staff.begin(),staff.end(),worsethan); 
    else
        std::sort(staff.begin(),staff.end(),biggerthan);
}

bool worsethan(const employee* left,const employee* right)
{
    if(((*left).num_out()) < ((*right).num_out()))
        return true;
    else
        return false;
}

bool biggerthan(const employee* left,const employee* right)
{
    if(((*left).num_out()) < ((*right).num_out()))
        return true;
    else
        return false;
}

void MangeSystem::empty()
{
    cout<< "are you sure to empty the data? y/n"<<endl;
    if(cin.get() == 'y')
    {
        for (auto i =staff.begin();i!=staff.end();i++)
        {
            delete (*i);
            *i = nullptr;
        }
        staff.clear();
    }
    else
    {
        cout<<"nothe was deleted"<<endl;
    }
    update_file();
}


void MangeSystem::read_file()
{ 
    std::ifstream infile(MangeSystem::filename.c_str(),
                            std::ios_base::in);
    string tmp_num;
    string tmp_name;
    string tmp_title;
    int index_tmp;
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
            add_one(tmp_num,tmp_name,tmp_title);
        }
    }
}

void MangeSystem::update_file()
{
    std::ofstream outfile(MangeSystem::filename.c_str(),std::ios_base::out);
    for (auto i = staff.begin(); i != staff.end(); i++)
    {
        outfile<<std::distance(staff.begin(),i) <<(**i).format_data();
    }
    outfile.close();
}