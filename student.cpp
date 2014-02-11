/******************************************************
 ** FILE: student.cpp
 **
 ** ABSTRACT:
 ** Provides implementation of the Student, UndergradStudent,
 ** and GraduateStudent classes.
 **
 ** AUTHOR:
 ** Nick Durak
 ** Barend Ungrodt
 **
 ** CREATION DATE:
 ** 15/01/2014
 **
 *******************************************************/

#include <iomanip>

#include "student.h"


/**
    constructor for student
 */
Student::Student(unsigned int id, string name, unsigned int year, float grade)
{
    m_id = id;
    m_name = name;
    m_year = year;
    m_grade = grade;
}



/**
    print data stored in student
 */
void Student::print()
{
    cout << std::setprecision(3) << m_id << " " << m_name << " " << m_year << " " << m_grade;
}


/**
    constructor for UndergradStudent
 */
UndergradStudent::UndergradStudent(unsigned int id, string name, unsigned int year, float grade, string major, string minor)
: Student(id, name, year, grade)
{
    m_major = major;
    m_minor = minor;
}

/**
    print data stored in UndergradStudent
 */
void UndergradStudent::print()
{
    Student::print();
    cout << " " << m_major << " " << m_minor << endl;
}


/**
    constructor for GraduateStudent
 */
GraduateStudent::GraduateStudent(unsigned int id, string name, unsigned int year, float grade, string dep, string advisor)
: Student(id, name, year, grade)
{
    m_dep = dep;
    m_advisor = advisor;
}

/**
    print data stored in GraduateStudent
 */
void GraduateStudent::print()
{
    Student::print();
    cout << " " << m_dep << " " << m_advisor << endl;
}