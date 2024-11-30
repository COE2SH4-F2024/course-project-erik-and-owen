#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    arrayCapacity = ARRAY_MAX_CAP; // Set in header file
    listSize = 0;
    aList = new objPos[arrayCapacity]; // create the list on the heap with the capacity set to the max cap constant 
    
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if (listSize >= arrayCapacity) { // ensure the list is not too big
        throw std::out_of_range("Invalid indexes.");
    } else {
        for (int i = listSize; i > 0; i--) { // Shift every array element one index higher
            aList[i] = aList[i-1];     
        }

        aList[0] = thisPos; // insert the paramater position to the first index that was empty after the shift
        listSize++;  
    }
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if (listSize >= arrayCapacity) { // Ensure the list is within range
        throw std::out_of_range("Invalid indexes.");
    } else {
        aList[listSize] = thisPos; // Add the position to the last index becoming the new tail
    }
    listSize++;
}

void objPosArrayList::removeHead()
{
    if (listSize > 0) {
        for (int i = 0; i < listSize; i++) {
            aList[i] = aList[i + 1]; // Shift every element down one, overwriting the original first element therefore removing the head
        }
        listSize--;
    } else {
        throw std::out_of_range("Empty Array");
    }
}

void objPosArrayList::removeTail()
{
    if (listSize > 0) {
        listSize--; // Decrement the list size, meaning the previous tail effectively no longer exists
    } else {
        throw std::out_of_range("Empty Array");
    }
}

objPos objPosArrayList::getHeadElement() const
{
    return aList[0];
}

objPos objPosArrayList::getTailElement() const
{
    return aList[listSize - 1];
}

objPos objPosArrayList::getElement(int index) const
{
    if (index < 0 || index > ARRAY_MAX_CAP) {
        throw std::out_of_range("Invalid Index");
    }

    return aList[index];
}