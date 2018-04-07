/******************************************************************************
* File: wk10_sortOperations_adupree.cpp
*
* Description: Generates an array of positive unique random integers and then
               Uses a newly developed "Custom" sort algorithm to sort it.

* Author: Alexander DuPree
*
* Date: 3/14/2018
*
* Compiler: GNU CC Compiler 5.4.0
*
* Modifications:
******************************************************************************/

#include "RandArray.h"
#include <iostream>

template <class T>
void printArray(const T ara[], const int SIZE, std::string araName);

int main()
{
    const int SIZE = 50;
    const int VALUE_MAX = 100;

    float ara[SIZE];
    Random<float> randomizer;

    randomizer.fillFloat(ara, VALUE_MAX, 0, SIZE);
    
    printArray(ara, SIZE, "Unsorted Array: ");

    randomizer.shuffle(ara, SIZE);

    printArray(ara, SIZE, "SHUFFLED: ");

    return 0;
}

template<class T>
void printArray(const T ara[], const int SIZE, std::string araName)
{
    std::cout << araName << std::endl;
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << ara[i] << " ";
    }
    std::cout << std::endl;
    return;
}
