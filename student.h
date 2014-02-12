/******************************************************
 ** FILE: student.h
 **
 ** ABSTRACT:
 ** Provides declarations for the Student, UndergradStudent,
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

#ifndef STUDENT_H
#define	STUDENT_H

#include <iostream>

/**
    Student
    Purpose: create a student
*/
class Student
{
public:
    
    /**
        constructor for student
     */
    Student(unsigned int id = 0, std::string name = "", unsigned int year = 0, float grade = 0.0);
    
    /**
        print data stored in student
     */
    virtual void print() const;
    
    int getGrade() const;
    std::string getName() const;
    
    
protected:
    
    unsigned int m_id;
    std::string m_name;
    unsigned int m_year;
    float m_grade; // GPA
};


class UndergradStudent: public Student
{
public:
    
    /**
        constructor for UndergradStudent
     */
    UndergradStudent(unsigned int id, std::string name, unsigned int year, float grade, std::string major = "", std::string minor = "");
    
    /**
        print data stored in UndergradStudent
     */
    virtual void print() const;
    
private:
    std::string m_major;
    std::string m_minor;
    
    
};


class GraduateStudent: public Student
{
public:
    
    /**
        constructor for GraduateStudent
     */
    GraduateStudent(unsigned int id, std::string name, unsigned int year, float grade, std::string dep = "", std::string advisor = "");
    
    /**
        print data stored in GraduateStudent
     */
    virtual void print() const;
    
private:
    std::string m_dep;
    std::string m_advisor;
};

#endif	/* STUDENT_H */

