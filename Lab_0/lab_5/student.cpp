#include "student.h"

#include <cstring>

// Constructors
Student::Student()
{
    firstName = nullptr;
    lastName = nullptr;
    setID(0);
    setFirstName("");
    setLastName("");
    setGPA(0.0);
}

Student::Student(int ID, const char *firstName, const char *lastName, float GPA)
{
    this->firstName = nullptr;
    this->lastName = nullptr;
    setID(ID);
    setFirstName(firstName);
    setLastName(lastName);
    setGPA(GPA);
}

Student::Student(Student& other) : Student(other.getID(), other.getFirstName(), other.getLastName(), other.getGPA()) {}

// Destructor
Student::~Student()
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
void Student::setFirstName(const char *firstName)
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

void Student::setLastName(const char *lastName)
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

void Student::setID(int ID) { this->ID = ID; }
void Student::setGPA(float GPA) { this->GPA = GPA; }

// Getters
const char *Student::getFirstName() { return firstName; }
const char *Student::getLastName() { return lastName; }
int Student::getID() { return ID; }
float Student::getGPA() { return GPA; }