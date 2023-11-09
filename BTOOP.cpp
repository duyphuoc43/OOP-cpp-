#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Employee {
private:
    string id;
    string name;
    string birthday;
public:
    Employee() {}
    virtual ~Employee() {} 
    Employee(string _id, string _name, string _birthday) : id(_id), name(_name), birthday(_birthday) {}
    string getId() {
        return id;
    }
    void setId(string _id) {
        id = _id;
    }
    string getName() {
        return name;
    }
    void setName(string _name) {
        name = _name;
    }
    string getBirthday() {
        return birthday;
    }
    void setBirthday(string _birthday) {
        birthday = _birthday;
    }
    friend ostream& operator<<(ostream& os, const Employee& obj) {
        os << "ID: " << obj.id << ", Name: " << obj.name << ", Birthday: " << obj.birthday;
        return os;
    }
    void inputField() {
        cin.ignore();
        std::cout << "\ninput id :";
        getline(std::cin, id);
        std::cout << "\ninput name: ";
        getline(std::cin, name);
        std::cout << "\ninput Birthday: ";
        getline(std::cin, birthday);
    }
    
};

class Employee_Experience : public Employee {
private:
    float expIn_year;
    string proskill;
public:
    Employee_Experience() {}
    Employee_Experience(string _id, string _name, string _birthday, float _expIn_year, string _proskill) : Employee(_id, _name, _birthday), expIn_year(_expIn_year), proskill(_proskill) {}

    void setExpIn_year(float _expIn_year) {
        expIn_year = _expIn_year;
    }
    float getExpIn_year() {
        return expIn_year;
    }
    void setProskill(string _proskill) {
        proskill = _proskill;
    }
    string getProskill() {
        return proskill;
    }
    float getInfoExIn_year(int expIn_year) {
        return float(int(expIn_year));
    }
    float getInfoExIn_year(float expIn_year) {
        return float(expIn_year);
    }
    float getInfoExIn_year(string expIn_year) {
        return float(stod(expIn_year));
    }
    friend ostream& operator<<(ostream& os, const Employee_Experience& obj) {
        os << static_cast<const Employee&>(obj) << ", Experience in years: " << obj.expIn_year << ", Proskill: " << obj.proskill;
        return os;
    }
    void inputField() {
        Employee::inputField();
        std::cout << "\n expIn_year: ";
        std::cin >> expIn_year;
        std::cin.ignore();
        std::cout << "\n proskill: ";
        getline(std::cin, proskill);
    }

};

class Employee_Fresher : public Employee {
private:
    string gradution_date;
    float gpa;
public:
    Employee_Fresher() {}
    Employee_Fresher(string _id, string _name, string _birthday, string _gradution_date, float _gpa) : Employee(_id, _name, _birthday), gradution_date(_gradution_date), gpa(_gpa) {}
    void setGradution_date(string _gradution_date) {
        gradution_date = _gradution_date;
    }
    string getGradution_date() {
        return gradution_date;
    }
    void setGpa(float _gpa) {
        gpa = _gpa;
    }
    float getGpa() {
        return gpa;
    }
    friend ostream& operator<<(ostream& os, const Employee_Fresher& obj) {
        os << static_cast<const Employee&>(obj) << ", Gradution Date: " << obj.gradution_date << ", GPA: " << obj.gpa;
        return os;
    }
    void inputField() {
        Employee::inputField();
        std:: cout << "\n gradution_date: ";
        getline(cin, gradution_date);
        std::cout << "\n GPA: ";
        std::cin >> gpa;
    }
};

class Employee_Intern : public Employee {
private:
    string majors;
    int semester;
public:
    Employee_Intern() {}
    Employee_Intern(string _id, string _name, string _birthday, string _majors, int _semester) : Employee(_id, _name, _birthday), majors(_majors), semester(_semester) {}
    void setMajors(string _majors) {
        majors = _majors;
    }
    string getMajors() {
        return majors;
    }
    void setSemester(int _semester) {
        semester = _semester;
    }

    int getSemester() {
        return semester;
    }
    friend ostream& operator<<(ostream& os, const Employee_Intern& obj) {
        os << static_cast<const Employee&>(obj) << ", Major: " << obj.majors << ", Semester: " << obj.semester;
        return os;
    }

    void inputField() {
        Employee::inputField();
        std::cout << "\nMajors: ";
        getline(std::cin, majors);
        std::cout << "\nSemester: ";
        std::cin >> semester;
    }
};

class Employee_Manager {
private:
    vector<Employee*> employees;
    static Employee_Manager* employee_Managers;
    Employee_Manager() {}
public:
    void add_Employee(Employee* employee) {
        employees.push_back(employee);
    }
    static Employee_Manager* getManager() {
        if (employee_Managers == nullptr) {
            employee_Managers = new Employee_Manager();
        }
        return employee_Managers;
    }
    vector<Employee*> getListEmployee() {
        return employees;
    }

    void displayInfo() {
        for (const auto& employee : employees) {
            if (dynamic_cast<Employee_Experience*>(employee) != nullptr) {
                Employee_Experience* exp = dynamic_cast<Employee_Experience*>(employee);
                std::cout << "Employee_Experience: " << *exp << std::endl;
            }
            else if (dynamic_cast<Employee_Fresher*>(employee) != nullptr) {
                Employee_Fresher* fresher = dynamic_cast<Employee_Fresher*>(employee);
                std::cout << "Employee_Fresher: " << *fresher << std::endl;
            }
            else if (dynamic_cast<Employee_Intern*>(employee) != nullptr) {
                Employee_Intern* intern = dynamic_cast<Employee_Intern*>(employee);
                std::cout << "Employee_Intern: " << *intern << std::endl;
            }
        }
    }
    void sort_asc() {
        int length = employees.size();
        for (int i = 0; i < employees.size() - 1; i++) {
            for (int j = i+1; j < employees.size(); j++) {
                if ((employees[i]->getName()) > (employees[j]->getName())) {
                    swap(employees[i], employees[j]);
                }
            }
        }
    }
    void sort_desc() {
        int length = employees.size();
        for (int i = 0; i < employees.size() - 1; i++) {
            for (int j = 1; j < employees.size(); j++) {
                if (employees[i]->getName() < employees[j]->getName()) {
                    swap(employees[i], employees[j]);
                }
            }
        }
    }
    void find_name(string name) {
        for (Employee* e : employees) {
            if (e->getName() == name) {
                std::cout << "Find : " << e->getName() << std::endl;
                return;
            }
        }
        std::cout << "Not Find" << std::endl;
    }
    void update_name(string name) {
        for (Employee* e : employees) {
            if (e->getName() == name) {
                std::cout << "Find : " << e->getName() << std::endl;
                cout << "Update : " << endl;
                if (dynamic_cast<Employee_Experience*>(e) != nullptr) {
                    Employee_Experience* exp = dynamic_cast<Employee_Experience*>(e);
                    float exp_year;
                    std::cout << "Exp in year: "; std::cin >> exp_year;
                    exp->setExpIn_year(exp_year);
                    string proskill;
                    std::cout << "proskill: "; getline(std::cin, proskill);
                    exp->setProskill(proskill);
                    std::cout << " Employee_Experience: " << *exp << std::endl;
                }
                else if (dynamic_cast<Employee_Fresher*>(e) != nullptr) {
                    Employee_Fresher* fresher = dynamic_cast<Employee_Fresher*>(e);
                    string gradution_date;
                    std::cout << "gradution_date: "; getline(std::cin, gradution_date);
                    fresher->setGradution_date(gradution_date);
                    float gpa;
                    std::cout << "gpa: "; std::cin >> gpa;
                    fresher->setGpa(gpa);
                    std::cout << "Employee_Fresher: " << *fresher << std::endl;
                }
                else if (dynamic_cast<Employee_Intern*>(e) != nullptr) {
                    Employee_Intern* intern = dynamic_cast<Employee_Intern*>(e);
                    int semester;
                    std::cout << "Semester "; std::cin >> semester;
                    intern->setSemester(semester);
                    std::cout << "Employee_Intern: " << *intern << std::endl;
                }
                return;
            }
        }
        std::cout << "Not Find" << std::endl;
    }
    void delete_id(string id) {
        for (vector<Employee*>::iterator it = employees.begin(); it != employees.end(); ++it) {
            std::cout << "(*it)->getID() " << (*it)->getId() << endl;
            if ( (*it)->getId() == id) {
                employees.erase(it);
                std::cout << "successfully delete" << endl;
                return;
            }
        }
        std::cout << "Not delete" << std::endl;
    }
};

class EmployeeApp {
private:
    string version;
public:
    EmployeeApp() {
        version = "1.0";
    }
    void inputdata() {
        Employee_Experience* experience1 = new Employee_Experience("1", "Ban", "01/01/1990", 5.0, "C++");
        Employee_Fresher* fresher1 = new Employee_Fresher("2", "Huy", "02/02/1995", "10/05/2022", 3.5);
        Employee_Intern* intern1 = new Employee_Intern("3", "Van", "03/03/2000", "CNTT", 2);
        Employee_Intern* intern2 = new Employee_Intern("4", "Binh", "03/03/2000", "CNTT", 4);
        Employee_Intern* intern3 = new Employee_Intern("5", "An", "11/02/2000", "CNTT", 7);
        Employee_Fresher* fresher1 = new Employee_Fresher("6", "Hy", "02/02/1995", "10/05/2022", 3.5);
        Employee_Manager::getManager()->add_Employee(experience1);
        Employee_Manager::getManager()->add_Employee(fresher1);
        Employee_Manager::getManager()->add_Employee(intern1);
        Employee_Manager::getManager()->add_Employee(intern2);
        Employee_Manager::getManager()->add_Employee(intern3);
    }
    void start() {
        menu();
    }
};
Employee_Manager* Employee_Manager::employee_Managers = nullptr;

bool ascending(Employee o1, Employee o2) {
    return o1.getName() < o2.getName();
}
bool descending(Employee o1, Employee o2) {
    return o1.getName() > o2.getName();
}
void sort_name(vector<Employee*> employees, bool(*compare)(Employee, Employee)) {
    for (int i = 0; i < employees.size() - 1; i++) {
        for (int j = i+1; j < employees.size(); j++) {
            if (!(compare)(*employees[i], *employees[j])) {
                swap(*employees[i], *employees[j]);
            }
        }
    }
}

void displayMenu() {
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Menu:" << std::endl;
    std::cout << "1. xem thong tin  nhan vien" << std::endl;
    std::cout << "2. them nhan vien" << std::endl;
    std::cout << "3. sua thong tin nhan vien" << std::endl;
    std::cout << "4. xoa nhan vien" << std::endl;
    std::cout << "5. sap xep theo ten" << std::endl;
    std::cout << "6.Tim kiem nhan vien theo id " << std::endl;
    std::cout << "7. thoat" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "chon tuy chon: ";
}
void displayMenuInsert() {
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Menu:" << std::endl;
    std::cout << "1. them nhan vien kinh nghiem " << std::endl;
    std::cout << "2. them nhan vien fresher " << std::endl;
    std::cout << "3. them nhan vien intern" << std::endl;
    std::cout << "4. thoat" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "chon tuy chon: ";
    
}
void menuInsert() {
    while (true) {
        displayMenuInsert();
        int choice_1;
        std::cin >> choice_1;
        std::cin.ignore();
        switch (choice_1) {
        case 1:{
            Employee_Experience* ex1 = new Employee_Experience();
            ex1->inputField();
            Employee_Manager::getManager()->add_Employee(ex1);
        }
            break;
        case 2: {
            Employee_Fresher* ex2 = new Employee_Fresher();
            ex2->inputField();
            Employee_Manager::getManager()->add_Employee(ex2);
        }
            break;
        case 3: {
            Employee_Intern* ex3 = new Employee_Intern();
            ex3->inputField();
            Employee_Manager::getManager()->add_Employee(ex3);
        }
            break;
        case 4:
            return;
        default: 
            std::cout << "Lựa chọn không hợp lệ." << std::endl;
            break;
        }
    }
}
void menu() {
    while (true) {
        displayMenu();
        int choice;
        string name;
        std::cin >> choice;
        std::cin.ignore();
        switch (choice) {
        case 1: 
            Employee_Manager::getManager()->displayInfo();
            break;
        case 2:
            menuInsert();
            break;
        case 3:
            std::cout << "Find name: ";
            std::getline(std::cin, name);
            Employee_Manager::getManager()->update_name(name);
            break;
        case 4:
            std::cout << "Find id to delete: ";
            std::getline(std::cin, name);
            Employee_Manager::getManager()->delete_id(name);
            break;
        case 5:
            sort_name(Employee_Manager::getManager()->getListEmployee(), descending);
            break;
        case 6: 
            std::cout << "Find name : ";
            std::getline(std::cin, name);
            Employee_Manager::getManager()->find_name(name);
            break;
        case 7: 
            return;
        default:
            std::cout << "Lựa chọn không hợp lệ." << std::endl;
            break;
        }
    }
}



int main() {
    EmployeeApp app;
    app.inputdata();
    app.start();
    return 0;
}