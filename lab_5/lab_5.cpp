/**
 * The program should not contain any memory leaks
 * That's because pointers pointing to the dynamically allocated memory are first deallocated before reassigning to any other value
 * The destructor also clears all the memory pointed by the pointer variables
 */

#include "student.h"

#include <iostream>

using std::cout;
using std::endl;

void printStudent(Student& student);

int main()
{
	// Testing parametrized constructor
    cout << "[+] Creating a student object using parameterized constructor by name 'Benjamin Oliver', ID 3, GPA 3.5" << endl
         << endl;
    Student newStudent(3, "Benjamin", "Oliver", 3.5);
    printStudent(newStudent);
	
	// Testing copy constructor
	cout << "[+] Creating a deep copy student object using above object" << endl
	     << endl;
	Student anotherNewStudent(newStudent);
	printStudent(anotherNewStudent);
	
    // The default constructor should create the student object with default values
    cout << "[+] Creating default student object" << endl
         << endl;
    Student student;
    printStudent(student);

    // The first name should be now John
    cout << "[+] Setting first name as John, The first name should be John now" << endl
         << endl;
    student.setFirstName("John");
    printStudent(student);

    // The last name should be now Doe
    cout << "[+] Setting last name as Doe, The last name should be Doe now" << endl
         << endl;
    student.setLastName("Doe");
    printStudent(student);

    // The ID should be now 1
    cout << "[+] Setting ID as 1, The ID should be 1 now" << endl
         << endl;
    student.setID(1);
    printStudent(student);

    // The GPA should be now 3.7
    cout << "[+] Setting GPA as 3.7, The GPA should be 3.7 now" << endl
         << endl;
    student.setGPA(3.7);
    printStudent(student);

    // Modifying the first name as Williams
    cout << "[+] Modifying first name as Williams, The first name should be now Williams" << endl
         << endl;
    student.setFirstName("Williams");
    printStudent(student);

    // Modifying last name as Smith
    cout << "[+] Modifying last name as Smith, The last name should be Smith now" << endl
         << endl;
    student.setLastName("Smith");
    printStudent(student);

    // Modifying GPA as 2.7
    cout << "[+] Modifying GPA as 2.7, The GPA should be 2.7 now" << endl
         << endl;
    student.setGPA(2.7);
    printStudent(student);

    // Modifying ID as 2
    cout << "[+] Modifying ID as 2, The ID should be 2 now" << endl
         << endl;
    student.setID(2);
    printStudent(student);

    return 0;
}

void printStudent(Student& student)
{
    cout << "ID         : " << student.getID() << endl
         << "First Name : " << student.getFirstName() << endl
         << "Last Name  : " << student.getLastName() << endl
         << "GPA        : " << student.getGPA() << endl
         << endl;
}