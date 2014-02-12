/* 
 * File:   abstractdatabase.h
 * Author: njd
 *
 * Created on February 11, 2014, 2:05 PM
 */

#ifndef ABSTRACTDATABASE_H
#define	ABSTRACTDATABASE_H

#include <string>
#include <vector>

class Student;
class Employee;
class AbstractSort;

class AbstractDatabase
{
    
public:
    virtual void buildDatabase(std::string) = 0;
    virtual void swap(int,int) = 0;
    virtual bool compare(int,int) = 0;
    virtual void sort(AbstractSort*) = 0;
    virtual void print() = 0;
    virtual int getSize() = 0;
    AbstractDatabase();
    virtual ~AbstractDatabase() = 0;
    
};

class StudentDatabase : public AbstractDatabase
{
    
public:
    virtual int getSize();
    virtual void buildDatabase(std::string);
    virtual void swap(int,int);
    virtual bool compare(int,int);
    virtual void sort(AbstractSort*);
    virtual void print(); 
    StudentDatabase();
    virtual ~StudentDatabase();
    
private:
    std::vector<Student*> students;
};

class EmployeeDatabase : public AbstractDatabase
{
    
public:
    virtual int getSize();
    virtual void buildDatabase(std::string);
    virtual void swap(int,int);
    virtual bool compare(int,int);
    virtual void sort(AbstractSort*);
    virtual void print(); 
    EmployeeDatabase();
    virtual ~EmployeeDatabase();
    
private:
    std::vector<Employee*> employees;
};

#endif	/* ABSTRACTDATABASE_H */

