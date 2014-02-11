/******************************************************
 ** FILE: employee.cpp
 **
 ** ABSTRACT:
 ** Provides implementation of the Employee, Faculty,
 ** and Staff classes.
 **
 ** AUTHOR:
 ** Nick Durak
 ** Barend Ungrodt
 **
 ** CREATION DATE:
 ** 05/02/2014
 **
 *******************************************************/

#include "employee.h"
#include <string>

using namespace std;


/**
 constructor for Employee
 */
Employee::Employee(unsigned int id, string name, unsigned int salary, unsigned int year)
{
    m_id = id;
    m_name = name;
    m_salary = salary;
    m_year = year;
}

/**
 print data stored in Employee
 */
void Employee::print()
{
    cout << m_id << " " << m_name << " " << m_salary << " " << m_year;
}

int Employee::getSalary()
{
    return m_salary;
}

int Employee::getYear()
{
    return m_year;
}



/**
 constructor for Faculty
 */
Faculty::Faculty(unsigned int id, string name, unsigned int salary, unsigned int year, unsigned int numStudents)
: Employee(id, name, salary, year)
{
    m_numStudents = numStudents;
}

/**
 print data stored in Faculty
 */
void Faculty::print()
{
    Employee::print();
    cout << " " << m_numStudents << endl;
}


/**
 constructor for Staff
 */
Staff::Staff(unsigned int id, string name, unsigned int salary, unsigned int year, string dep)
: Employee(id, name, salary, year)
{
    m_dep = dep;
}

/**
 print data stored in Staff
 */
void Staff::print()
{
    Employee::print();
    cout << " " << m_dep << endl;
}
