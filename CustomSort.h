/******************************************************************************
* TODO Library summary
******************************************************************************/

#ifndef SORT_H
#define SORT_H

namespace Sort
{
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

    void custom(int ara[], const int VALUE_MAX, const int SIZE);
    // Function to be called by the user in main. Requires an array of unique
    // integers, the size of the array, and the highest value in the array.
    // SortArray will then sort the array using the sort methods in the sort
    // class.
    void bubble(int ara[], int SIZE);
    void selection(int ara[], int SIZE);
    void insertion(int ara[], int start, int SIZE);


}
#endif // SORT_H
