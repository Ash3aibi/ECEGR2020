#include "student.h"

// Constructors
Student::Student()
{
    setID(0);
    setFirstName("");
    setLastName("");
    setGPA(0.0);
}

Student::Student(int ID, std::string firstName, std::string lastName, float GPA)
{
    setID(ID);
    setFirstName(firstName);
    setLastName(lastName);
    setGPA(GPA);
}

Student::Student(Student &other) : Student(other.getID(), other.getFirstName(), other.getLastName(), other.getGPA()) {}

// Destructor
Student::~Student()
{
    // Allocation/Deallocation is being handled by the string class now
}

// Setters
void Student::setFirstName(std::string firstName) { this->firstName = firstName; }
void Student::setLastName(std::string lastName) { this->lastName = lastName; }
void Student::setID(int ID) { this->ID = ID; }
void Student::setGPA(float GPA) { this->GPA = GPA; }

// Getters
std::string Student::getFirstName() { return firstName; }
std::string Student::getLastName() { return lastName; }
int Student::getID() { return ID; }
float Student::getGPA() { return GPA; }