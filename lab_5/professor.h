#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "department.h"

class Professor
{
private:
    int ID;
    char *firstName;
    char *lastName;
    float salary;
    bool tenured;
    Department department;

public:
    // Constructor
    Professor();
    Professor(int ID, const char *firstName, const char *lastName, float salary, bool tenured, Department department);
	Professor(Professor &other);
    // Destructor
    ~Professor();
    // Setters
    void setID(int ID);
    void setFirstName(const char *firstName);
    void setLastName(const char *lastName);
    void setSalary(float salary);
    void setTenured(bool tenured);
    void setDepartment(Department department);
    // Getters
    int getID();
    const char *getFirstName();
    const char *getLastName();
    float getSalary();
    bool getTenured();
    Department getDepartment();
};

#endif