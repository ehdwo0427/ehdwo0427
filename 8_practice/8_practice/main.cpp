#include<iostream>
#include<cstring>
using namespace std;

class Employee{
private:
    char name[100];
public:
    Employee(char * name){
        strcpy(this->name, name);
    }
    void ShowYourName() const{
        cout<< "name : " << name << '\n';
    }
};

class PermanentWorker : public Employee{
private:
    int salary;
public:
    PermanentWorker(char * name, int money) : Employee(name), salary(money)
    { }
    int GetPay() const{
        return salary;
    }
    void ShowSalaryInfo() const{
        ShowYourName();
        cout<<"salary: "<< GetPay() << '\n' << '\n';
    }
};

class EmployeeHandler
{
private:
    Employee * empList[50];
    int empNum;
public:
    EmployeeHandler() : empNum(0)
    {}
    void AddEmployee(Employee * emp){
        empList[empNum++] = emp;
    }
    void ShowAllSalaryInfo() const{
        int sum = 0;
        cout<<"salary sum: " << sum << '\n';
    }
    void ShowTotalSalary() const{
        int sum = 0;
        cout<< "salary sum: "<<sum << '\n';
    }
    ~EmployeeHandler(){
        for(int i = 0; i < empNum; i++) delete empList[i];
    }
};

int main(){
    EmployeeHandler handler; //직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성
    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("Lee", 1500));
    handler.AddEmployee(new PermanentWorker("Choi", 2000));
    
    handler.ShowAllSalaryInfo();
    
    handler.ShowTotalSalary();
    return 0;
}
