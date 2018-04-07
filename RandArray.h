/******************************************************************************
* RandArray class purpose is to generate an array of random unique positive
* integers from 0 - n. It utilizes a set container to achieve this, and then
* Shuffles the array. RandArray utilizes name space Random to further abstract
* Its functions from the user. The user just has to call Random::randomize()
* to generate a set of unique random positive integers.
******************************************************************************/


#ifndef RANDARRAY_H
#define RANDARRAY_H


class Random
{

public:

    Random();
    // Constructor not implemented

    void fillUnique(int ara[], int _max, int _min, int SIZE);
    // fills array with random unique integers from _min - _max. Utilizes a
    // set to find unique integers then copies the sets values over to the
    // array. 

    void fillRandom(int ara[], int _max, int _min, int SIZE);
    // fillRandom will accept an array and generate random numbers between 
    // _min - _max. numbers may be duplicated

    void fillUniqueSorted(int ara[], int _max, int _min, int SIZE);
    // fillUniqueSorted accepts an array and generates random unique numbers in 
    // ascending order.

    void shuffle(int ara[], int SIZE);
    // shuffles a m_randAra to make it unsorted. Used in conjunction with
    // fillUnique. The nature of using a set to fill an array requires
    // that we shuffle it afterwards.

};


#endif // RANDARRAY_H
