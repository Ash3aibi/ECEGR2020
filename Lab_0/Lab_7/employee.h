#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "person.h"

class Employee : public Person
{
private:
    float salary;

protected:
    Employee(int ID, const std::string &firstName, const std::string &lastName, float salary, char type);

public:
    // Constructor and Destructor
    Employee();
    Employee(int ID, const std::string &firstName, const std::string &lastName, float salary);
    Employee(const Employee &other);
    ~Employee();
    // Setters
    void setSalary(float salary);
    // Getters
    float getSalary() const;
    // Addtional methods
    virtual std::string toString();
};

#endif