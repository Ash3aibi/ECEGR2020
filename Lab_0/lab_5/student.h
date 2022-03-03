#ifndef STUDENT_H
#define STUDENT_H

class Student
{
private:
    int ID;
    char *firstName;
    char *lastName;
    float GPA;

public:
    // Constructor and Destructor
    Student();
    Student(int ID, const char *firstName, const char *lastName, float GPA);
	Student(Student &other);
    ~Student();
    // Setters
    void setFirstName(const char *firstName);
    void setLastName(const char *lastName);
    void setID(int ID);
    void setGPA(float GPA);
    // Getters
    const char *getFirstName();
    const char *getLastName();
    int getID();
    float getGPA();
};

#endif