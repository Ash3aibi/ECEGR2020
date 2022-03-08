#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

class Student
{
private:
    int ID;
    std::string firstName;
    std::string lastName;
    float GPA;

public:
    // Constructor and Destructor
    Student();
    Student(int ID, std::string firstName, std::string lastName, float GPA);
	Student(Student &other);
    ~Student();
    // Setters
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setID(int ID);
    void setGPA(float GPA);
    // Getters
    std::string getFirstName();
    std::string getLastName();
    int getID();
    float getGPA();
};

#endif


