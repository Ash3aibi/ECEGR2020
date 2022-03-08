/*

The whole file structure needed to be updated as specified in prenote in report. 
The new file sample is as follows.

5
1 James Robert 1
2 John David 1.5
3 Daniel Charles 2
4 Mathew Anthony 2.5
5 Mark Donald 3

The file structure is as follows.

noOfRecords
ID1 FirstName1 LastName1 GPA1
ID2 FirstName2 LastName2 GPA2
ID3 FirstName3 LastName3 GPA3
*/

#include "student.h"

// Included fstream and iostream for file and console I/O
#include <fstream>
#include <string>

#define STUDENT_FILE "students.txt"

// Standardizing namespaces
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::ios;
using std::ofstream;
using std::string;

// A node struct has been created that contains the student data as well as next reference
struct Node
{
    Student student;
    Node *next = nullptr;
};

// Function declarations
void feedRecords(Node *, int &);
void addStudent(int, string, string, float, Node *&, int &);
void removeStudent(int, Node *&, int &);
void updateStudentsInfo(int, Node *&, int &);
void displayStudents(Node *);
void studentInfo(Node *&, int &);
void readStudentFile(Node *&, int &);
void displayMenu();
void studentController(Node *&, int &);

// Main function
int main()
{
    Node *head = nullptr;
    int noOfStudents = 0;
    studentController(head, noOfStudents);
    return 0;
}

// Function definitions
void feedRecords(Node *head, int &noOfStudents)
{
    // Opening file for writing
    ofstream outputFileStream;
    outputFileStream.open(STUDENT_FILE, ios::out);
    if (!outputFileStream.is_open())
    {
        cerr << "Error opening file" << endl;
        exit(-1);
    }

    outputFileStream << noOfStudents << endl;
    for (Node *current = head; current != nullptr; current = current->next)
        outputFileStream << current->student.getID() << " " << current->student.getFirstName() << " " << current->student.getLastName() << " " << current->student.getGPA() << endl;

    outputFileStream.close(); // Closing output file stream
}

void addStudent(int id, string fn, string ln, float GPA, Node *&head, int &noOfStudents)
{
    Node *temp = new Node;
    temp->student.setFirstName(fn);
    temp->student.setLastName(ln);
    temp->student.setID(id);
    temp->student.setGPA(GPA);

    // printf("Enter id: ");
    // scanf("%d",&temp->ID);
    // printf("Enter firstName: ");
    // scanf("%s",temp->firstName);
    // printf("Enter lastName: ");
    // scanf("%s",temp->lastName);
    // printf("Enter GPA: ");
    // scanf("%f",&temp->GPA);

    cout << "ID: " << id << endl
         << "First Name: " << fn << endl
         << "Last Name: " << ln << endl
         << "GPA: " << GPA << endl;

    if (head == NULL || head->student.getGPA() < temp->student.getGPA())
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        Node *current = head;
        Node *previous = nullptr;
        for (Node *current = head; current != nullptr; current = current->next)
        {
            if (temp->student.getGPA() > current->student.getGPA())
                break;
            previous = current;
        }

        if (previous->next == nullptr)
            previous->next = temp;
        else
        {
            temp->next = previous->next;
            previous->next = temp;
        }
    }
    cout << "Added" << endl;
    ++noOfStudents;
    feedRecords(head, noOfStudents);
}

void removeStudent(int id, Node *&head, int &noOfStudents)
{
    Node *temp1 = head;
    Node *temp2 = head;
    for (Node *temp1 = head; temp1 != nullptr; temp1 = temp1->next)
    {
        if (temp1->student.getID() == id)
        {
            cout << "Record with ID " << id << " Found!!!" << endl;
            if (temp1 == temp2)
                head = head->next;
            else
                temp2->next = temp1->next;
            delete temp1;

            cout << "Record Successfully Deleted !!!" << endl;
            --noOfStudents;
            feedRecords(head, noOfStudents);
            return;
        }
        temp2 = temp1;
    }
    cout << "Student with ID " << id << " is not found!!!" << endl;
}

void updateStudentsInfo(int id, Node *&head, int &noOfStudents)
{
    for (Node *temp = head; temp != nullptr; temp = temp->next)
    {
        if (temp->student.getID() == id)
        {
            string firstName, lastName;
            cout << "Record with ID " << id << " Found !!!" << endl
                 << "Enter new first name: ";
            cin.ignore();
            getline(cin, firstName);
            temp->student.setFirstName(firstName);

            // New string input method
            cout << "Enter new last name: ";
            getline(cin, lastName);
            temp->student.setLastName(lastName);

            float gpa;
            cout << "Enter new GPA: ";
            cin >> gpa;
            temp->student.setGPA(gpa);

            cout << "Updation Successful!!!" << endl;
            feedRecords(head, noOfStudents);
            return;
        }
    }
    cout << "Student with roll number " << id << " is not found !!!" << endl;
}

void displayStudents(Node *head)
{
    for (Node *current = head; current != nullptr; current = current->next)
        cout << "Roll Number: " << current->student.getID() << endl
             << "First Name: " << current->student.getFirstName() << endl
             << "Last Name: " << current->student.getLastName() << endl
             << "GPA: " << current->student.getGPA() << endl;
}

void studentInfo(Node *&head, int &noOfStudents)
{
    cout << endl
         << "-------- Func B --------" << endl
         << endl
         << "Enter number of students in class: ";
    cin >> noOfStudents;
    for (int i = 0; i < noOfStudents; ++i)
    {
        Node *temp = new Node;

        // get input
        cout << "Enter id: ";
        int id;
        cin >> id;

        cout << "Enter first name: ";
        string firstName;
        cin.ignore();
        getline(cin, firstName);

        string lastName;
        cout << "Enter last name: ";
        getline(cin, lastName);

        cout << "Enter GPA: ";
        float gpa;
        cin >> gpa;

        addStudent(id, firstName, lastName, gpa, head, noOfStudents);
        cout << endl;
    }
    feedRecords(head, noOfStudents);
}

void readStudentFile(Node *&head, int &noOfStudents)
{
    cout << "\n-------- Func C --------\n\n";
    ifstream inputFileStream;
    inputFileStream.open(STUDENT_FILE, ios::in);

    if (!inputFileStream.is_open())
    {
        cerr << "\nError opening file" << endl;
        exit(-1);
    }
    inputFileStream >> noOfStudents;
    cout << "\nNumber of students: " << noOfStudents << endl;
    head = nullptr;

    for (int i = 0; i < noOfStudents; ++i)
    {
        char firstName[1000], lastName[1000];
        firstName[999] = '\0';
        lastName[999] = '\0';
        int id;
        float gpa;
        inputFileStream >> id >> firstName >> lastName >> gpa;
        cout << "ID: " << id << endl
             << "First Name: " << firstName << endl
             << "Last Name: " << lastName << endl
             << "GPA: " << gpa << endl;
        Node *newNode = new Node;
        newNode->student.setID(id);
        newNode->student.setFirstName(firstName);
        newNode->student.setLastName(lastName);
        newNode->student.setGPA(gpa);
        if (head == nullptr)
            head = newNode;
        else
        {
            for (Node *current = head; current != nullptr; current = current->next)
            {
                if (current->next == nullptr)
                {
                    current->next = newNode;
                    break;
                }
            }
        }
    }

    // find avg
    float sum = 0;
    for (Node *current = head; current != nullptr; current = current->next)
        sum += current->student.getGPA();
    float avg;
    if (noOfStudents == 0)
        avg = 0;
    else
        avg = sum / noOfStudents;

    cout << "Average GPA: " << avg << endl;
    inputFileStream.close();
}

void displayMenu()
{
    cout << "\n1) List all Students\n"
         << "2) Add Student\n"
         << "3) Remove Student\n"
         << "4) Update Student\n"
         << "5) Quit\n";
}

void studentController(Node *&head, int &noOfStudents)
{
    readStudentFile(head, noOfStudents);
    displayMenu();

    int exit = 0;
    while (exit != 1)
    {
        int ch;
        cout << "Select >> ";
        cin >> ch;
        if (ch == 1)
            displayStudents(head);
        else if (ch == 2)
        {
            // get input
            cout << "Enter id: ";
            int id;
            cin >> id;

            cout << "Enter first name: ";
            string firstName;
            cin.ignore();
            getline(cin, firstName);

            string lastName;
            cout << "Enter last name: ";
            getline(cin, lastName);

            cout << "Enter GPA: ";
            float gpa;
            cin >> gpa;

            addStudent(id, firstName, lastName, gpa, head, noOfStudents);
        }
        else if (ch == 3)
        {
            int id;
            cout << "Enter Student Id to remove: ";
            cin >> id;
            removeStudent(id, head, noOfStudents);
        }
        else if (ch == 4)
        {
            int id;
            cout << "Enter Student Id to update: ";
            cin >> id;
            updateStudentsInfo(id, head, noOfStudents);
        }
        else if (ch == 5)
            exit = 1;
    }
}