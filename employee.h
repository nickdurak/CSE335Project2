/* 
 * File:   employee.h
 * Author: njd
 *
 * Created on February 11, 2014, 12:05 PM
 */

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H

#include <iostream>
#include <string>

using std::string;

/**
 Employee
 Purpose: create an Employee
 */
class Employee
{
public:
    
    /**
     constructor for Employee
     */
    Employee(unsigned int id = 0, string name = "", unsigned int salary = 0, unsigned int year = 0);
    
    /**
     print data stored in Employee
     */
    virtual void print();
    
protected:
    
    int m_id;
    string m_name;
    unsigned m_salary;
    int m_year; // entrance year
};

/**
 Employee
 Purpose: create a faculty Employee
 */
class Faculty: public Employee
{
public:
    
    /**
     constructor for Faculty
     */
    Faculty(unsigned int id, string name, unsigned int salary, unsigned int year, unsigned int numStudents = 0);
    
    /**
     print data stored in Faculty
     */
    virtual void print();
    
private:
    unsigned int m_numStudents;
    
    
};

/**
 Employee
 Purpose: create a staff Employee
 */
class Staff: public Employee
{
public:
    
    /**
     constructor for Staff
     */
    Staff(unsigned int id, string name, unsigned int salary, unsigned int year, string dep = "");
    
    /**
     print data stored in Staff
     */
    virtual void print();
    
private:
    string m_dep;
};



#endif	/* EMPLOYEE_H */

