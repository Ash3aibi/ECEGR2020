#include "professor.h"
#include <sstream>

// Constructors
Professor::Professor() : Professor(0, "", "", 0, false, Department::uninitialized) {}

Professor::Professor(int ID, const std::string &firstName, const std::string &lastName, float salary, bool tenured, Department department) : Employee::Employee(ID, firstName, lastName, salary, PROFESSOR)
{
    setTenured(tenured);
    setDepartment(department);
}

Professor::Professor(const Professor &other) : Professor(other.getID(), other.getFirstName(), other.getLastName(), other.getSalary(), other.getTenured(), other.getDepartment()) {}

// Destructor
Professor::~Professor() {}

// Setters
void Professor::setTenured(bool tenured) { this->tenured = tenured; }
void Professor::setDepartment(Department department) { this->department = department; }

// Getters
bool Professor::getTenured() const { return tenured; }
Department Professor::getDepartment() const { return department; }

// Additional methods
std::string Professor::toString()
{
    std::stringstream stringBuilder;
    stringBuilder << PROFESSOR << Employee::toString().substr(1) << " " << tenured << " " << departmentToInt(department);
    return stringBuilder.str();
}