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

#include <iostream>
#include <ctime>
#include "RandArray.h"
#include "CustomSort.h"

template<class T>
void copyAra(const T ara1[], T ara2[], int SIZE);
template <class T>
void printArray(const T ara[], const int SIZE, std::string araName);
void printTime(std::clock_t time, std::string text);

int main()
{
    const int SIZE = 100000;
    std::clock_t time;

    int ara[SIZE];
    int bubbleAra[SIZE],
        selectionAra[SIZE],
        insertionAra[SIZE], 
        customAra[SIZE];

    Random<int> randomizer;

    randomizer.fillUnique(ara, 100000, 0, SIZE);
    //copyAra(ara, bubbleAra, SIZE);
    copyAra(ara, selectionAra, SIZE);
    copyAra(ara, insertionAra, SIZE);
    copyAra(ara, customAra, SIZE);

    Sort<int> sort;

   // time = std::clock();
   // sort.bubble(bubbleAra, SIZE);
   // time = std::clock() - time;
   // printTime(time, "Bubble Sort ");

    time = std::clock();
    sort.selection(selectionAra, SIZE);
    time = std::clock() - time;
    printTime(time, "selectionSort ");

    time = std::clock();
    sort.insertion(insertionAra, 1, SIZE);
    time = std::clock() - time;
    printTime(time, "Insertion Sort ");
    
    time = std::clock();
    sort.custom(customAra, 100000, SIZE);
    time = std::clock() - time;
    printTime(time, "Custom Sort ");

    return 0;
}

template<class T>
void copyAra(const T ara1[], T ara2[], int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        ara2[i] = ara1[i];
    }
    return;
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

void printTime(std::clock_t time, std::string text)
{
    std::cout << text;
    std::cout << "Time: " << time / (double)(CLOCKS_PER_SEC / 1000) << " ms\n";
    return;
}
