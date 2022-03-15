#include "department.h"
#include <iostream>

Department departmentFromInput(std::string department)
{
    if (department == "1")
        return Department::computerScience;
    else if (department == "2")
        return Department::textileEngineering;
    else if (department == "3")
        return Department::commerce;
    else
        return Department::uninitialized;
}

Department getDepartmentFromConsole()
{
    std::cout << "Enter the department of professor: ";
    while (true)
    {
        std::string dept;
        std::cin >> dept;
        Department department = departmentFromInput(dept);
        if (department == Department::textileEngineering || department == Department::commerce || department == Department::computerScience)
            return department;
        else
            std::cout << "Invalid department, Provide '1' for computer science, '2' for textile engineering, '3' for commerce" << std::endl;
    }
}

std::string departmentToString(Department department)
{
    if (department == Department::computerScience)
        return "Computer Science";
    else if (department == Department::textileEngineering)
        return "Textile Engineering";
    else if (department == Department::commerce)
        return "Commerce";
    return "Invalid";
}

int departmentToInt(Department department)
{
    return static_cast<int>(department);
}
