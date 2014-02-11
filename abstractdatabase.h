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
#include "student.h"
#include "employee.h"
#include "abstractsort.h"

using namespace std;


class AbstractDatabase {
    
public:
    virtual void buildDatabase(string) = 0;
    virtual void swap(int,int) = 0;
    virtual bool compare(int,int) = 0;
    virtual void sort(AbstractSort) = 0;
    virtual void print() = 0;
    virtual int getSize() = 0;
    AbstractDatabase();
    virtual ~AbstractDatabase();
    
};

class StudentDatabase : public AbstractDatabase{
    
public:
    virtual int getSize();
    virtual void buildDatabase(string);
    virtual void swap(int,int);
    virtual bool compare(int,int);
    virtual void sort(AbstractSort*);
    virtual void print(); 
    StudentDatabse();
    virtual ~StudentDatabse();
    
private:
    vector<Student*> students;
};

class EmployeeDatabase : public AbstractDatabase{
    
public:
    virtual int getSize();
    virtual void buildDatabase(string);
    virtual void swap(int,int);
    virtual bool compare(int,int);
    virtual void sort(AbstractSort*);
    virtual void print(); 
    EmployeeDatabase();
    virtual ~EmployeeDatabase();
    
private:
    vector<Employee*> employees;
};

#endif	/* ABSTRACTDATABASE_H */

