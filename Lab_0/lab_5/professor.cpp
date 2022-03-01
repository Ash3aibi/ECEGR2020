#include "professor.h"

#include <cstring>

// Constructor
Professor::Professor()
{
    firstName = nullptr;
    lastName = nullptr;
    setID(0);
    setFirstName("");
    setLastName("");
    setSalary(0.0);
    setTenured(false);
    setDepartment(Department::uninitialized);
}

Professor::Professor(int ID, const char *firstName, const char *lastName, float salary, bool tenured, Department department)
{
    this->firstName = nullptr;
    this->lastName = nullptr;
    setID(ID);
    setFirstName(firstName);
    setLastName(lastName);
    setSalary(salary);
    setTenured(tenured);
    setDepartment(department);
}

Professor::Professor(Professor &other) : Professor(other.getID(), other.getFirstName(), other.getLastName(), other.getSalary(), other.getTenured(), other.getDepartment()) {}

// Destructor
Professor::~Professor()
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
void Professor::setID(int ID) { this->ID = ID; }

void Professor::setFirstName(const char *firstName)
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

void Professor::setLastName(const char *lastName)
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

void Professor::setSalary(float salary) { this->salary = salary; }

void Professor::setTenured(bool tenured) { this->tenured = tenured; }

void Professor::setDepartment(Department department) { this->department = department; }

// Getters
int Professor::getID() { return ID; }

const char *Professor::getFirstName() { return firstName; }

const char *Professor::getLastName() { return lastName; }

float Professor::getSalary() { return salary; }

bool Professor::getTenured() { return tenured; }

Department Professor::getDepartment() { return department; }