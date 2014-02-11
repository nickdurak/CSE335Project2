/* 
 * File:   main.cpp
 * Author: njd
 *
 * Created on February 11, 2014, 11:59 AM
 */

#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

#include "student.h"
#include "employee.h"

/*
 * 
 */
int main(int argc, char** argv) 
{
    ifstream studentFile ("input1.txt");
    ifstream employeeFile ("input2.txt");
    string line = "";
    unsigned int id = 0;
    unsigned int year = 0;
    float grade = 0;
    string name = "";
    string major = "";
    string minor = "";
    string dep = "";
    string advisor = "";
    unsigned int salary = 0;
    unsigned int numStudents = 0;
    string dummy = "";
    
    
    vector<Student*> studentList;
    vector<Employee*> employeeList;
    
    if (studentFile.is_open())
    {
        while (getline (studentFile, line))
        {
            if (line[0] == 'U')
            {
                stringstream undergradStream;
                undergradStream << line;
                
                
                undergradStream >> dummy >> id >> name >> year >> grade >> major >> minor;
                
                studentList.push_back(new UndergradStudent(id, name, year, grade, major, minor));
                
            }
            
            if (line[0] == 'G')
            {
                stringstream graduateStream;
                graduateStream << line;
                
                graduateStream >> dummy >> id >> name >> year >> grade >> dep >> advisor;
                
                studentList.push_back(new GraduateStudent(id, name, year, grade, dep, advisor));
            }
        }
    }
    
    studentFile.close();
    
    if (employeeFile.is_open())
    {
        while (getline (employeeFile, line))
        {
            if (line[0] == 'F')
            {
                stringstream facultyStream;
                facultyStream << line;
                
                facultyStream >> dummy >> id >> name >> salary >> year >> numStudents;
                
                employeeList.push_back(new Faculty(id, name, salary, year, numStudents));
                
            }
            
            if (line[0] == 'S')
            {
                stringstream staffStream;
                staffStream << line;
                
                staffStream >> dummy >> id >> name >> salary >> year >> numStudents;
                
                employeeList.push_back(new Staff(id, name, salary, year, dep));
            }
        }
    }
    
    studentList.push_back(new UndergradStudent(100, "test", 2000, 4.0, "test", "test"));
    
    studentList[0]->print();
    
    employeeFile.close();
    
}

