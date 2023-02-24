#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;
class employee
{
    private:
    string num;
    string name;
    string title; 
    public:
    employee(const string& num_in = "0000",
             const string& name_in = "Nobody",
             const string& title_in = "employee"):num(num_in),name(name_in),title(title_in)
            {cout<<"construct employee"<<endl;}
    virtual void duty(){cout<<"To complete the job from manager"<<endl;};
    void show_item();
    virtual ~employee(){cout<<"destroy "<<endl;};
};

class manager :public employee
{
    public:
    manager(const string& num_in = "0000",
            const string& name_in = "Nobody",
            const string& title_in = "manager"):employee(num_in,name_in,title_in){}
    virtual void duty(){cout<<"Complete the task assigned by boss,and distribute it to employees"<<endl;}
    virtual ~manager(){};
};

class boss :public manager
{
    public:
    boss(const string& num_in = "0000",
         const string& name_in = "Nobody",
         const string& title_in = "boss"):manager(num_in,name_in,title_in){}
    void duty(){cout<<"Manage all affairs of company"<<endl;}
    ~boss(){};
};

#endif