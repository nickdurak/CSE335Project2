/* 
 * File:   abstractdatabase.cpp
 * Author: njd
 * 
 * Created on February 11, 2014, 2:20 PM
 */

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>

#include "student.h"
#include "employee.h"
#include "abstractsort.h"
#include "abstractdatabase.h"

using namespace std;

void StudentDatabase::buildDatabase(string file)
{
    string line = "";
    unsigned int id = 0;
    unsigned int year = 0;
    float grade = 0;
    string name = "";
    string major = "";
    string minor = "";
    string dep = "";
    string advisor = "";
    string dummy = "";
    ifstream studentFile (file);
    
    
    if (studentFile.is_open())
    {
        while (getline (studentFile, line))
        {
            if (line[0] == 'U')
            {
                stringstream undergradStream;
                undergradStream << line;
                
                
                undergradStream >> dummy >> id >> name >> year >> grade >> major >> minor;
                
                students.push_back(new UndergradStudent(id, name, year, grade, major, minor));
                
            }
            
            if (line[0] == 'G')
            {
                stringstream graduateStream;
                graduateStream << line;
                
                graduateStream >> dummy >> id >> name >> year >> grade >> dep >> advisor;
                
                students.push_back(new GraduateStudent(id, name, year, grade, dep, advisor));
            }
        }
    }
    
    studentFile.close();
}

int StudentDatabase::getSize()
{
    return students.size();
}

void StudentDatabase::swap(int i, int j)
{
    Student* temp = students[i];
    students[i] = students[j];
    students[j] = temp;   
}

bool StudentDatabase::compare(int j, int i)
{
    if(students[i]->getGrade() < students[j]->getGrade()) return true;
    
    else if(students[i]->getGrade() == students[j]->getGrade())
    {
        if(students[i]->getName() > students[j]->getName()) return true;
    }
    else return false;
        
}

void StudentDatabase::sort(AbstractSort *sortType)
{
    sortType->sort(this);
}

void StudentDatabase::print()
{
    for(unsigned int i = 0; i < students.size(); i++){
            students[i]->print();	
    }
}

StudentDatabase::~StudentDatabase()
{
    int size = students.size();
    
    for(unsigned int i = 0; i < size; i++)
    {
         students.pop_back();	
    }
}




void EmployeeDatabase::buildDatabase(string file)
{
    ifstream employeeFile (file);
    string line = "";
    unsigned int id = 0;
    unsigned int year = 0;
    float grade = 0;
    string dep = "";
    string name = "";
    unsigned int salary = 0;
    unsigned int numStudents = 0;
    string dummy = "";
    
    
    if (employeeFile.is_open())
    {
        while (getline (employeeFile, line))
        {
            if (line[0] == 'F')
            {
                stringstream facultyStream;
                facultyStream << line;
                
                facultyStream >> dummy >> id >> name >> salary >> year >> numStudents;
                
                employees.push_back(new Faculty(id, name, salary, year, numStudents));
                
            }
            
            if (line[0] == 'S')
            {
                stringstream staffStream;
                staffStream << line;
                
                staffStream >> dummy >> id >> name >> salary >> year >> numStudents;
                
                employees.push_back(new Staff(id, name, salary, year, dep));
            }
        }
    }
    
    employeeFile.close();
}

void EmployeeDatabase::swap(int i, int j)
{
    Employee* temp = employees[i];
    employees[i] = employees[j];
    employees[j] = temp;   
}

int EmployeeDatabase::getSize()
{
    return employees.size();
}

bool EmployeeDatabase::compare(int j, int i)
{
    if(employees[i]->getSalary() > employees[j]->getSalary()) return true;
    
    else if(employees[i]->getSalary() == employees[j]->getSalary())
    {
        if(employees[i]->getYear() > employees[j]->getYear()) return true;
    }
    else return false;
}

void EmployeeDatabase::sort(AbstractSort *sortType)
{
    sortType->sort(this);
}

void EmployeeDatabase::print()
{
    for(unsigned int i = 0; i < employees.size(); i++)
    {
         employees[i]->print();	
    }
}

EmployeeDatabase::~EmployeeDatabase()
{
    int size = employees.size();
    
    for(unsigned int i = 0; i < size; i++)
    {
         employees.pop_back();	
    }
}