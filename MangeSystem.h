#include "employee.h"
#include <vector>

using std::vector;
class MangeSystem
{
    private:
    static string filename; 
    vector<employee*> staff;
    public:   
    MangeSystem();
    void menu();
    void start();
    void exit();
    void show();
    void add_one(const employee& employee_in);
    void add_staffs();
    void remove(const string& num);
    void edit(const string& num);
    employee& find();
    void sort();
    void empty();
    void read_file();
    void update_file();

    ~MangeSystem(){}
};