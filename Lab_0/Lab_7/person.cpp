#include "person.h"
#include <sstream>

// Constructors
Person::Person() : Person(0, "", "") {}

Person::Person(int ID, const std::string &firstName, const std::string &lastName, char type)
{
    setID(ID);
    setFirstName(firstName);
    setLastName(lastName);
    setType(type);
}

Person::Person(const Person &other) : Person(other.getID(), other.getFirstName(), other.getLastName(), other.getType()) {}

// Destructor
Person::~Person() {}

// Setters
void Person::setFirstName(const std::string &firstName) { this->firstName = firstName; }
void Person::setLastName(const std::string &lastName) { this->lastName = lastName; }
void Person::setID(int ID) { this->ID = ID; }
void Person::setType(char type) { this->type = type; }

// Getters
std::string Person::getFirstName() const { return firstName; }
std::string Person::getLastName() const { return lastName; }
int Person::getID() const { return ID; }
char Person::getType() const { return type; }

// Virtual methods
std::string Person::toString()
{
    std::stringstream stringBuilder;
    stringBuilder << type << " " << ID << " " + firstName + " " + lastName;
    return stringBuilder.str();
}