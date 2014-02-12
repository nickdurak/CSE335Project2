/* 
 * File:   main.cpp
 * Author: njd
 *
 * Created on February 11, 2014, 11:59 AM
 */

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>

#include "student.h"
#include "employee.h"
#include "abstractdatabase.h"
#include "abstractsort.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    StudentDatabase* students = new StudentDatabase();
    students->buildDatabase("input1");  //store the list of students from input 1 in the students StudentDatabase

    BubbleSort* BS = new BubbleSort();
    
    students->print();

    students->sort(BS); //sorts the database of students using bubblesort
    
    students->print();
}

