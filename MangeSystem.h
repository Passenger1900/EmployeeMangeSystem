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
    void add_one(const string& tmp_num,
                 const string& tmp_name,
                 const string& tmp_title);
    void add_staffs();
    void remove_inter();
    void remove(const string& num);
    void edit_inter();
    void edit(const string& num);
    int find(const string& input_tmp,int mode=0);
    void find_person();
    void sort();
    void empty();
    void read_file();
    void update_file();

    ~MangeSystem();
};