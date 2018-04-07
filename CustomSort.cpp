#include "CustomSort.h"

Sort::Custom::Custom(const int VALUE_MAX) : m_size(VALUE_MAX)
{
    m_initArray = new int[m_size];
    for (unsigned int i = 0; i < m_size; i++)
    {
        m_initArray[i] = -1;
    }
}

Sort::Custom::~Custom()
{
    delete [] m_initArray;
    m_initArray = 0;
}

void Sort::Custom::imprintValues(const int ara[], const int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        m_initArray[ara[i]] = ara[i];
    }
    return;
}

void Sort::Custom::getSortedValues(int ara[], const int SIZE)
{
    int i = 0;
    int index = 0;
    while (index < SIZE)
    {
        if (m_initArray[i] != -1)
        {
            ara[index] = m_initArray[i];
            index++;
        }
        i++;
    }
    return;
}

void Sort::custom(int ara[], const int VALUE_MAX, const int SIZE)
{
    Sort::Custom customSort(VALUE_MAX);
    customSort.imprintValues(ara, SIZE);
    customSort.getSortedValues(ara, SIZE);
    return;
}

void Sort::bubble(int ara[], int SIZE)
{
    bool isSwap = false;

    // Base case
    if (SIZE == 1) { return; }

    for (int i = 0; i < SIZE - 1; i++)
    {
        if (ara[i] > ara[i+1])
        {
            int temp = ara[i];
            ara[i] = ara[i+1];
            ara[i+1] = temp;
            isSwap = true;
        }
    }
    if (isSwap) { bubble(ara, SIZE - 1); }
    else { return; }
}

void Sort::selection(int ara[], int SIZE)
{
    // Base case
    if (SIZE == 0) { return; }

    int largest = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (ara[i] > ara[largest])
        {
            largest = i;
        }
    }
    int temp = ara[largest];
    ara[largest] = ara[SIZE-1];
    ara[SIZE-1] = temp;
    selection(ara, SIZE - 1);
}

void Sort::insertion(int ara[], int start, int SIZE)
{
    // base case
    if (start >= SIZE ) { return; }

    int i = start;
    for(i; i > 0; i--)
    {
        if (ara[start] > ara[i-1]) { break; }
    }

    // Shift every element larger than ara[start] over one position.
    for (int j = start; j > i; j--)
    {
        int temp = ara[j-1];
        ara[j-1] = ara[j];
        ara[j] = temp;
    }
    insertion(ara, start + 1, SIZE);
}

