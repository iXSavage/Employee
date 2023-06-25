#include <iostream>
#include <vector>
#include <algorithm>

class Employee{
private:
    std::string Name;
    int ID;
    int Salary;

public:
    Employee(std::string name, int id, int salary){
        Name=name;
        ID=id;
        Salary=salary;
    }
    void setName(std::string name){
        Name=name;
    }
    std::string getName(){
        return Name;
    }
    void setID(int id){
        ID=id;
    }
    int getID() {
        return ID;
    }
    void setSalary(int salary){
        Salary=salary;
    }
    int getSalary(){
        return Salary;
    }

   void EmployeeInformation() {
        std::cout << "Name: " << Name << ", ID: "<< ID << ", Salary: " << Salary << std::endl;
    }
};

class EmployeeManagementSystem{
private:
    std::vector<Employee> Employees;

public:
    void AddNewEmployee(){
        std::string Name;
        int ID;
        int Salary;

        std::cout << "Enter employee name" << std::endl;
        std::cin >> Name;
        std::cout << "Enter employee ID" << std::endl;
        std::cin >> ID;
        std::cout << "Enter employee salary" << std::endl;
        std::cin >> Salary;

        Employee employee (Name, ID, Salary);
        Employees.push_back(employee);
        std::cout << "Employee added successfully" << std::endl;

    }
    void RemoveEmployee(){
        int id;
        std::cout << "Enter employee ID to remove: ";
        std::cin >> id;

        auto it = std::find_if(Employees.begin(), Employees.end(), [id]( Employee& emp) {
            return emp.getID() == id;
        });

        if (it != Employees.end()) {
            Employees.erase(it);
            std::cout << "Employee removed successfully!" << std::endl;
        } else {
            std::cout << "Employee not found." << std::endl;
        }
    }
    void DisplayEmployee(){
           if (Employees.empty()) {
            std::cout << "No employees found." << std::endl;
        } else {
            std::cout << "Employee List:" << std::endl;
            for (auto& employee : Employees) {
                employee.EmployeeInformation();
            }
        }
    }
};
int main(){
    Employee Employee1 = Employee("ixsavage", 75873, 1000);
    Employee1.EmployeeInformation();

 EmployeeManagementSystem ems;
    char choice;

    do {
    std::cout << "Employee Management System" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "1. Add Employee" << std::endl;
    std::cout << "2. Remove Employee" << std::endl;
    std::cout << "3. Display Employees" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
        case '1':
            ems.AddNewEmployee();
            break;
        case '2':
            ems.RemoveEmployee();
            break;
        case '3':
            ems.DisplayEmployee();
            break;
        case '4':
            std::cout << "Exiting..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
    }
} while (choice != '4');
   
}

 