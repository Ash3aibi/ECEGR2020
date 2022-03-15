#include "professor.h"
#include "student.h"
#include <fstream>
#include <string>
#include <sstream>

// Symbolic constants
#define DATA_FILE "data.txt"
#define LIST 1
#define ADD 2
#define REMOVE 3
#define UPDATE 4
#define QUIT 5

// Standardizing namespace
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::ofstream;
using std::string;
using std::stringstream;

// Linked list node
struct Node
{
     Person *data = nullptr;
     Node *next = nullptr;
};

// Function declarations
void formattedDisplay(Person *person);
Person *getPersonFromConsole();
void displayMenu();
int getUserInput();
bool loadFromFile(Node *&head, string fileName);
bool saveToFile(Node *head, string fileName);
bool add(Node *&head, Person *person);
bool remove(Node *&head, int id);
void list(Node *head);
bool update(Node *&head, int id);

int main()
{
     // Initialize linked list and load from file
     Node *head = nullptr;
     loadFromFile(head, DATA_FILE);

     // Program loop
     while (true)
     {
          // Display menu and get user input
          displayMenu();
          cout << endl;
          int userChoice = getUserInput();
          cout << endl;

          // Perform appropriate operaiton on user input
          if (userChoice == LIST)
               list(head);
          else if (userChoice == ADD)
          {
               if (add(head, getPersonFromConsole()))
                    cout << "Record added!" << endl;
               else
                    cout << "Person with that ID already exists" << endl;
          }
          else if (userChoice == REMOVE)
          {
               int userID;
               cout << "Enter user id to remove: ";
               cin >> userID;
               if (remove(head, userID))
                    cout << "Record deleted!" << endl;
               else
                    cout << "Record with that ID not found" << endl;
          }
          else if (userChoice == UPDATE)
          {
               int userID;
               cout << "Enter user id to update: ";
               cin >> userID;
               if (update(head, userID))
                    cout << "Record updated!" << endl;
               else
                    cout << "Record with that ID not found" << endl;
          }
          else
               break;
          saveToFile(head, DATA_FILE);
          cout << endl;
     }
}

bool loadFromFile(Node *&head, string fileName)
{
     // Opening and validating the file streams
     ifstream inputFileStream;
     inputFileStream.open(fileName);
     if (!inputFileStream.is_open())
          return false;
     string line;

     // Keep inputting file line by line
     while (getline(inputFileStream, line))
     {
          if (line.empty())
               continue;
          // Read the attributes from the inputted line
          stringstream lineStream;
          lineStream << line;
          char userType;
          int id;
          string firstName, lastName;
          lineStream >> userType >> id >> firstName >> lastName;

          // If the record is for a student
          Person *toInsert = nullptr;
          if (userType == STUDENT)
          {
               float gpa;
               lineStream >> gpa;
               toInsert = new Student(id, firstName, lastName, gpa);
          }
          else
          {
               // Input the salary and check if the record is for employee or professor
               float salary;
               lineStream >> salary;
               if (userType == EMPLOYEE)
                    toInsert = new Employee(id, firstName, lastName, salary);
               else if (userType == PROFESSOR)
               {
                    bool tenured;
                    std::string dept;
                    lineStream >> tenured >> dept;
                    Department department = departmentFromInput(dept);
                    toInsert = new Professor(id, firstName, lastName, salary, tenured, department);
               }
          }
          if (toInsert != nullptr)
               add(head, toInsert);
     }
     inputFileStream.close();
     return true;
}

bool saveToFile(Node *head, string fileName)
{
     // Opening and validating file streams
     ofstream outputFileStream;
     outputFileStream.open(fileName, std::ios::out);
     if (!outputFileStream.is_open())
          return false;

     // Outputting each record to output file
     for (Node *current = head; current != nullptr; current = current->next)
          outputFileStream << current->data->toString() << endl;

     // Closing the file sream
     outputFileStream.close();
     return true;
}

void displayMenu()
{
     cout << LIST << ") List" << endl
          << ADD << ") Add" << endl
          << REMOVE << ") Remove" << endl
          << UPDATE << ") Update" << endl
          << QUIT << ") Quit" << endl;
}

int getUserInput()
{
     while (true)
     {
          int userChoice;
          cout << "Enter your choice: ";
          cin >> userChoice;
          if (userChoice < LIST || userChoice > QUIT)
               cout << "Invalid choice!" << endl;
          else
               return userChoice;
     }
}

bool add(Node *&head, Person *person)
{
     if (head == nullptr)
     {
          head = new Node;
          head->data = person;
     }
     else
     {
          int personID = person->getID();
          Node *prev = nullptr;
          for (Node *current = head; current != nullptr; current = current->next)
          {
               if (current->data->getID() == personID)
                    return false;
               else
                    prev = current;
          }
          prev->next = new Node;
          prev->next->data = person;
     }
     return true;
}

bool remove(Node *&head, int id)
{
     Node *prev = nullptr;
     for (Node *current = head; current != nullptr; current = current->next)
     {
          if (current->data->getID() == id)
          {
               if (prev == nullptr)
                    head = head->next;
               else
                    prev->next = current->next;
               delete current->data;
               delete current;
               return true;
          }
          else
               prev = current;
     }
     return false;
}

void list(Node *head)
{
     int itemNumber = 1;
     for (Node *current = head; current != nullptr; current = current->next, ++itemNumber)
     {
          cout << itemNumber << "). " << endl;
          formattedDisplay(current->data);
          cout << endl;
     }
}

bool update(Node *&head, int id)
{
     for (Node *current = head; current != nullptr; current = current->next)
     {
          if (current->data->getID() == id)
          {
               delete current->data;
               current->data = getPersonFromConsole();
               return true;
          }
     }
     return false;
}

Person *getPersonFromConsole()
{
     char type = '1';
     while (true)
     {
          cout << "Enter the person type in single character: ";
          cin >> type;
          if (type == STUDENT || type == EMPLOYEE || type == PROFESSOR)
               break;
          else
               cout << "Invalid value, Valid values are 'S' for student, 'E' for employee and 'P' for professor" << endl;
     }
     int id;
     string firstName, lastName;
     cout << "Enter id: ";
     cin >> id;
     cout << "Enter first name: ";
     cin >> firstName;
     cout << "Enter last name: ";
     cin >> lastName;
     if (type == STUDENT)
     {
          float gpa;
          cout << "Enter gpa: ";
          cin >> gpa;
          return new Student(id, firstName, lastName, gpa);
     }
     else
     {
          float salary;
          cout << "Enter salary: ";
          cin >> salary;
          if (type == PROFESSOR)
          {
               int input;
               bool tenured;
               cout << "Enter 0 if professor is not tenured or any other number if tenured: ";
               cin >> input;
               tenured = (input == 0) ? false : true;
               Department department = getDepartmentFromConsole();
               return new Professor(id, firstName, lastName, salary, tenured, department);
          }
          else
               return new Employee(id, firstName, lastName, salary);
     }
     return nullptr;
}

void formattedDisplay(Person *person)
{
     int id = person->getID();
     char type = person->getType();
     string firstName = person->getFirstName();
     string lastName = person->getLastName();
     string designation;

     if (type == STUDENT)
          designation = "Student";
     else if (type == EMPLOYEE)
          designation = "Employee";
     else if (type == PROFESSOR)
          designation = "Professor";

     cout << "Type: " << designation << endl
          << "ID: " << id << endl
          << "Name: " << firstName + " " + lastName << endl;
     if (type == STUDENT)
     {
          Student *student = dynamic_cast<Student *>(person);
          float gpa = student->getGPA();
          cout << "GPA: " << gpa << endl;
     }
     else
     {
          Employee *employee = dynamic_cast<Employee *>(person);
          float salary = employee->getSalary();
          cout << "Salary: " << salary << endl;
          if (employee->getType() == PROFESSOR)
          {
               Professor *professor = dynamic_cast<Professor *>(employee);
               string department = departmentToString(professor->getDepartment());
               string tenured = professor->getTenured() ? "Yes" : "No";
               cout << "Department: " << department << endl
                    << "Tenured: " << tenured << endl;
          }
     }
}