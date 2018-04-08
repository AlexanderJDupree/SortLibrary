/******************************************************************************
* TODO Library summary
* TODO Add quick, heap, and other sort methods
* TODO Template library to work with all primitive data types
* TODO Modify custom sort to accept all real numbers (- to +)
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
    // Function to be called by the user in main. Requires an array of unique
    // integers, the size of the array, and the highest value in the array.
    // SortArray will then sort the array using the sort methods in the sort
    // class.
    void bubble(T ara[], int SIZE);

    void selection(T ara[], int SIZE);

    void insertion(T ara[], int start, int SIZE);

private:

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

template class Sort<int>;
template class Sort<short>;
template class Sort<long>;
template class Sort<float>;
template class Sort<double>;
template class Sort<char>;

#endif // SORT_H
