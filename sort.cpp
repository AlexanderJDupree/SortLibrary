#include "sort.h"

template<class T>
Sort<T>::Custom::Custom(const int VALUE_MAX) : m_size(VALUE_MAX)
{
    m_initArray = new int[m_size];
    for (unsigned int i = 0; i < m_size; i++)
    {
        m_initArray[i] = -1;
    }
}

template<class T>
Sort<T>::Custom::~Custom()
{
    delete [] m_initArray;
    m_initArray = 0;
}

template<class T>
void Sort<T>::Custom::imprintValues(const int ara[], const int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        m_initArray[ara[i]] = ara[i];
    }
    return;
}

template<class T>
void Sort<T>::Custom::getSortedValues(int ara[], const int SIZE)
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

template<class T>
void Sort<T>::custom(int ara[], const int VALUE_MAX, const int SIZE)
{
    Sort::Custom customSort(VALUE_MAX);
    customSort.imprintValues(ara, SIZE);
    customSort.getSortedValues(ara, SIZE);
    return;
}

template<class T>
void Sort<T>::bubble(T ara[], int SIZE)
{
    bool isSwap = false;

    // Base case
    if (SIZE == 1) { return; }

    for (int i = 0; i < SIZE - 1; i++)
    {
        if (ara[i] > ara[i+1])
        {
            T temp = ara[i];
            ara[i] = ara[i+1];
            ara[i+1] = temp;
            isSwap = true;
        }
    }
    if (isSwap) { bubble(ara, SIZE - 1); }
    else { return; }
}

template<class T>
void Sort<T>::selection(T ara[], int SIZE)
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
    T temp = ara[largest];
    ara[largest] = ara[SIZE-1];
    ara[SIZE-1] = temp;
    selection(ara, SIZE - 1);
}

template<class T>
void Sort<T>::insertion(T ara[], int start, int SIZE)
{
    // base case
    if (start >= SIZE ) { return; }

    int i;
    // i is declared in function scope so we can use it later on
    
    for(i = start; i > 0; i--)
    {
        if (ara[start] > ara[i-1]) { break; }
    }

    // Shift every element larger than ara[start] over one position.
    for (int j = start; j > i; j--)
    {
        T temp = ara[j-1];
        ara[j-1] = ara[j];
        ara[j] = temp;
    }
    insertion(ara, start + 1, SIZE);
}

template<class T>
void Sort<T>::quick(T ara[], int left, int right)
{
    // Base case
    if (left >= right) { return; }

    int part = partition(ara, left, right);
    
    quick(ara, left, part - 1);
    // Quick sort left partition
    
    quick(ara, part + 1, right);
    // Quick sort right partition
}

// private 

template<class T>
int Sort<T>::partition(T ara[], int left, int right)
{
    /* Partition takes the right most element as the pivot, places the pivot in
       correct index in the array and arranges elements greater than pivot to 
       the right and less than or equal to pivot to the left */

    const T pivot = ara[right];
    int i = left - 1;
    // index of smaller element

    for (int j = left; j <= right - 1; j++)
    {
        // if current element is smaller or equal to pivot we switch with i
        if (ara[j] <= pivot)
        {
            i++;
            T temp = ara[i];
            ara[i] = ara[j];
            ara[j] = temp;
        }
    }
    // Swap pivot to the correct index in the array
    T temp = ara[i+1];
    ara[i+1] = ara[right];
    ara[right] = temp;

    return (i + 1);

}
