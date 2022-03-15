#include "student.h"
#include <sstream>

// Constructors
Student::Student() : Student(0, "", "", 0) {}

Student::Student(int ID, const std::string &firstName, const std::string &lastName, float gpa) : Person::Person(ID, firstName, lastName, STUDENT)
{
    setGPA(gpa);
}

Student::Student(const Student &other) : Student(other.getID(), other.getFirstName(), other.getLastName(), other.getGPA()) {}

// Destructor
Student::~Student() {}

// Setters
void Student::setGPA(float GPA) { this->GPA = GPA; }

// Getters
float Student::getGPA() const { return GPA; }

// Heelper methods
std::string Student::toString()
{
    std::stringstream stringBuilder;
    stringBuilder << getType() << Person::toString().substr(1) << " " << GPA;
    return stringBuilder.str();
}