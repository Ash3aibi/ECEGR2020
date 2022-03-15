#ifndef PERSON_H
#define PERSON_H

#define STUDENT 'S'
#define EMPLOYEE 'E'
#define PROFESSOR 'P'
#define PERSON 'B'

#include <iostream>

class Person
{
private:
    int ID;
    std::string firstName;
    std::string lastName;
    char type;

public:
    // Constructor and Destructor
    Person();
    Person(int ID, const std::string &firstName, const std::string &lastName, char type = 'P');
    Person(const Person &other);
    virtual ~Person();
    // Setters
    void setFirstName(const std::string &firstName);
    void setLastName(const std::string &lastName);
    void setID(int ID);
    void setType(char type);
    // Getters
    std::string getFirstName() const;
    std::string getLastName() const;
    int getID() const;
    char getType() const;
    // Virtual method
    virtual std::string toString();
};

#endif