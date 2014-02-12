/* 
 * File:   abstractsort.h
 * Author: njd
 *
 * Created on February 11, 2014, 3:33 PM
 */

#ifndef ABSTRACTSORT_H
#define	ABSTRACTSORT_H

class AbstractDatabase;

class AbstractSort 
{
public:
    AbstractSort() {}
    virtual void sort(AbstractDatabase*) = 0;
    virtual ~AbstractSort();

};

class BubbleSort : public AbstractSort
{
public:
    BubbleSort() {}
    virtual void sort(AbstractDatabase*);
    virtual ~BubbleSort();
};

#endif	/* ABSTRACTSORT_H */

