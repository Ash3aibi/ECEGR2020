#include <iostream>

enum class Department
{
    uninitialized,
    computerScience,
    textileEngineering,
    commerce
};

// Helper functions
Department departmentFromInput(std::string department);
Department getDepartmentFromConsole();
int departmentToInt(Department department);
std::string departmentToString(Department department);