#include "ArrayBag.h"
#include <iostream>
#include <cstddef>

#ifndef ARRAY_BAG_H
#define ARRAY_BAG_H
// *** Add new method code to the ADT implementation file

template<class ItemType>
ArrayBag<ItemType>::ArrayBag(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}  // end default constructor

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
    return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
    return itemCount == 0;
}  // end isEmpty

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
    bool hasRoomToAdd = (itemCount < maxItems);
    if (hasRoomToAdd)
    {
        items[itemCount] = newEntry;
        itemCount++;
    }  // end if

    return hasRoomToAdd;
}  // end add

template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
    int locatedIndex = getIndexOf(anEntry);
    bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
    if (canRemoveItem)
    {
        itemCount--;
        items[locatedIndex] = items[itemCount];
    }  // end if

    return canRemoveItem;
}  // end remove

template<class ItemType>
void ArrayBag<ItemType>::clear()
{
    itemCount = 0;
}  // end clear

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
    int frequency = 0;
    int curIndex = 0;       // Current array index
    while (curIndex < itemCount)
    {
        if (items[curIndex] == anEntry)
        {
            frequency++;
        }  // end if

        curIndex++;          // Increment to next entry
    }  // end while

    return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
    return getIndexOf(anEntry) > -1;
}  // end contains

// Public method to find and return the largest value in the array
template<class ItemType>
int ArrayBag<ItemType>::FindGreatestValue(int fstidex, int lastindex)
{
    if (fstidex == lastindex) {
        return items[fstidex]; // Base case if there is only one value in list segment
    }
    int midindex = (fstidex + lastindex) / 2; // Compute the middle index
    int start = FindGreatestValue(fstidex, midindex); // Checks lower half
    int last = FindGreatestValue(midindex + 1, lastindex); // Checks upper half
    if (start > last) { // Finds larger value, and outputs it
        return start;
    }
    return last;
} // End of FindGreatestValue

// Public method to find and return the smallest value in the array
template<class ItemType>
int ArrayBag<ItemType>::FindSmallestValue(int fstidex, int lastindex)
{
    if (fstidex == lastindex) {
        return items[fstidex]; // Base case if there is only one value in list segment
    }
    int midindex = (fstidex + lastindex) / 2; // Compute the middle index
    int start = FindSmallestValue(fstidex, midindex); // Checks lower half
    int last = FindSmallestValue(midindex + 1, lastindex); // Checks upper half
    if (start < last) { // Finds smaller value, and outputs it
        return start;
    }
    return last;
} // End of FindSmallestValue

template<class ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const
{
    std::vector<ItemType> bagContents;
    for (int i = 0; i < itemCount; i++)
        bagContents.push_back(items[i]);

    return bagContents;
}  // end toVector

template<class ItemType>
ItemType& ArrayBag<ItemType>::operator[](int index)
{
    if (index >= 0 && index < itemCount)
    {
        return items[index];
    }
    else
    {
        throw std::out_of_range("Index is out of range.");
    }
}

// private
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
    bool found = false;
    int result = -1;
    int searchIndex = 0;

    // If the bag is empty, itemCount is zero, so loop is skipped
    while (!found && (searchIndex < itemCount))
    {
        if (items[searchIndex] == target)
        {
            found = true;
            result = searchIndex;
        }
        else
        {
            searchIndex++;
        }  // end if
    }  // end while

    return result;
}  // end getIndexOf

#endif
