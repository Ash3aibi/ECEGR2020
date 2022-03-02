#include "employee.h"

#include <cstring>

// Constructor
Employee::Employee()
{
    firstName = nullptr;
    lastName = nullptr;
    setID(0);
    setFirstName("");
    setLastName("");
    setSalary(0.0);
}

Employee::Employee(int ID, const char *firstName, const char *lastName, float salary)
{
    this->firstName = nullptr;
    this->lastName = nullptr;
    setID(ID);
    setFirstName(firstName);
    setLastName(lastName);
    setSalary(salary);
}

Employee::Employee(Employee &other) : Employee(other.getID(), other.getFirstName(), other.getLastName(), other.getSalary()) {}

// Destructor
Employee::~Employee()
{
    if (firstName)
    {
        delete[] firstName;
        firstName = nullptr;
    }
    if (lastName)
    {
        delete[] lastName;
        lastName = nullptr;
    }
}

// Setters
void Employee::setID(int ID) { this->ID = ID; }

void Employee::setFirstName(const char *firstName)
{
    if (this->firstName)
    {
        delete[] this->firstName;
        this->firstName = nullptr;
    }
    this->firstName = new char[strlen(firstName) + 1];
    strcpy(this->firstName, firstName);
    this->firstName[strlen(firstName)] = '\0';
}

void Employee::setLastName(const char *lastName)
{
    if (this->lastName)
    {
        delete[] this->lastName;
        this->lastName = nullptr;
    }
    this->lastName = new char[strlen(lastName) + 1];
    strcpy(this->lastName, lastName);
    this->lastName[strlen(lastName)] = '\0';
}

void Employee::setSalary(float salary) { this->salary = salary; }

// Getters
float Employee::getID() { return ID; }

const char *Employee::getFirstName() { return firstName; }

const char *Employee::getLastName() { return lastName; }

float Employee::getSalary() { return salary; }