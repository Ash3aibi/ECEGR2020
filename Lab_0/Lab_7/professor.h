#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "employee.h"
#include "department.h"

class Professor : public Employee
{
private:
    bool tenured;
    Department department;

public:
    // Constructor
    Professor();
    Professor(int ID, const std::string &firstName, const std::string &lastName, float salary, bool tenured, Department department);
    Professor(const Professor &other);
    // Destructor
    ~Professor();
    // Setters
    void setTenured(bool tenured);
    void setDepartment(Department department);
    // Getters
    bool getTenured() const;
    Department getDepartment() const;
    // Additional methods
    std::string toString();
};

#endif
