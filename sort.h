/******************************************************************************
* Class: Sort
*
* Description: Sort class provides the user with a variety of methods to sort an 
* array of a primitive data type. Current sort methods are bubble, selection, 
* insertion, and quick sort. 
* 
* Modifications:
*
* 07-APR-18 - Refactored Sort class. Got rid of "sort" namespace and moved the 
*             custom sort into the sort class as a private member.
*
* 07-APR-18 - Templated all sort methods except custom sort
*
* 08-APR-18 - Implemented recursive quick sort function. quick sort relies on 
*             the partition function to perform its sort. partition is a private
*             member function
*
* TODO Add heap, merge, and other sort methods
* TODO Modify custom sort to be implemented as a proper counter sort
* TODO Figure out a way to accept custom objects and sort them if their 
*      comparison operators are overloaded
******************************************************************************/

#ifndef SORT_H
#define SORT_H

template<class T>
class Sort
{

public:

    void custom(int ara[], const int VALUE_MAX, const int SIZE);
    // Best Case: 
    // Worst Case: 
    // Average: 
    // Space: 
    
    void bubble(T ara[], int SIZE);
    // Best Case: O(n)
    // Worst Case: O(n^2)
    // Average: O(n^2)
    // Space: O(1)

    void selection(T ara[], int SIZE);
    // Best Case: O(n^2) comparisons, O(n) swaps
    // Worst Case: O(n^2) comparisons, O(n) swaps
    // Average: O(n^2) comparisons, O(n) swaps
    // Space: O(1) 

    void insertion(T ara[], int start, int SIZE);
    // Best Case: O(n)
    // Worst Case: O(n^2)
    // Average: O(n^2)
    // Space: O(1)

    void quick(T ara[], int left, int right);
    // Best Case: O(n log n)
    // Worst Case: O(n^2)
    // Average: O(n log n)
    // Space: log n best, n avg

private:

    int partition(T ara[], int left, int right);
    // Chooses right element as pivot value and partitions all values left or 
    // right of the pivot based on less than or greater than comparisons.

    class Custom
    {
    public:

        Custom(const int VALUE_MAX);
        // Constructor allocates memory for an int array of size VALUE_MAX and
        // initializes each element to -1.
        ~Custom();
        // Destructor deletes the dynamic array and points it to 0.
        
        void imprintValues(const int ara[], const int SIZE);
        // Precondition: Assumes that the highest value of any element in ara
        // is less than VALUE_MAX (m_size).
        // Postcondition: Takes every value in ara and assigns it to the
        // corresponding index in m_initArray. I.E. if the value is 71 then
        // m_initArray[71] will equal 71.

        void getSortedValues(int ara[], const int SIZE);
        // Iterates through m_initArray copies over any value greater than -1
        // to the given array.

    private:

        unsigned int m_size;
        int * m_initArray;
    };
};

// explicit instantiations
template class Sort<int>;
template class Sort<short>;
template class Sort<long>;
template class Sort<float>;
template class Sort<double>;
template class Sort<char>;

#endif // SORT_H
