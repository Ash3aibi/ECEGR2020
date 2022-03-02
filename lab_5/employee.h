#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee
{
private:
    int ID;
    char *firstName;
    char *lastName;
    float salary;

public:
    // Constructor
    Employee();
    Employee(int ID, const char *firstName, const char *lastName, float salary);
	Employee(Employee &other);
    // Destructor
    ~Employee();
    // Setters
    void setID(int ID);
    void setFirstName(const char *firstName);
    void setLastName(const char *lastName);
    void setSalary(float salary);
    // Getters
    float getID();
    const char *getFirstName();
    const char *getLastName();
    float getSalary();
};

#endif