#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"

class Student : public Person
{
private:
    float GPA;

public:
    // Constructor and Destructor
    Student();
    Student(int ID, const std::string &firstName, const std::string &lastName, float GPA);
    Student(const Student &other);
    ~Student();
    // Setters
    void setGPA(float GPA);
    // Getters
    float getGPA() const;
    // Helper methods
    std::string toString();
};

#endif