/* 
 * File:   abstractsort.h
 * Author: njd
 *
 * Created on February 11, 2014, 3:33 PM
 */

#ifndef ABSTRACTSORT_H
#define	ABSTRACTSORT_H

#include "abstractdatabase.h"

using namespace std;

class AbstractSort {
public:
    virtual void sort(AbstractDatabase*) = 0;
    AbstractSort();
    virtual ~AbstractSort();

};

class BubbleSort : public AbstractSort
{
public:
    virtual void sort(AbstractDatabase*);
    BubbleSort();
};

#endif	/* ABSTRACTSORT_H */

