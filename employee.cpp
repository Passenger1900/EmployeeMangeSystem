#include "employee.h"

void employee::show_item()
{
    cout<<"the id is "<<num<<endl;
    cout<<"the name is "<<name<<endl;
    cout<<"the title is "<<title<<endl;
    duty();
}

string employee::format_data()
{
    string tmp = num+" "+name+" "+title+"\n";
    return tmp;
}

string employee::num_out() const
{
    return num;
}