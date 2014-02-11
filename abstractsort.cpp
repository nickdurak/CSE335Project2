/* 
 * File:   abstractsort.cpp
 * Author: njd
 * 
 * Created on February 11, 2014, 3:33 PM
 */

#include "abstractsort.h"
#include "abstractdatabase.h"

using namespace std;

void BubbleSort::sort(AbstractDatabase* database)
{
    for(int i = database->getSize()-1; i > 0; --i)
        for(int j = 0; j < i; j++)
            if(database->compare(j, i)) database->swap(j, i);
}

