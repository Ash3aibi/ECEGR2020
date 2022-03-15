#include "employee.h"
#include <sstream>

// Constructors
Employee::Employee() : Employee(0, "", "", 0) {}

Employee::Employee(int ID, const std::string &firstName, const std::string &lastName, float salary) : Employee(ID, firstName, lastName, salary, EMPLOYEE) {}

Employee::Employee(int ID, const std::string &firstName, const std::string &lastName, float salary, char type) : Person::Person(ID, firstName, lastName, type)
{
    setSalary(salary);
}

Employee::Employee(const Employee &other) : Employee(other.getID(), other.getFirstName(), other.getLastName(), other.getSalary(), other.getType()) {}

// Destructor
Employee::~Employee() {}

// Setters
void Employee::setSalary(float salary) { this->salary = salary; }

// Getters
float Employee::getSalary() const { return salary; }

// Additional methods
std::string Employee::toString()
{
    std::stringstream stringBuilder;
    stringBuilder << EMPLOYEE << Person::toString().substr(1) << " " << salary;
    return stringBuilder.str();
}