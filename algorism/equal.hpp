#ifndef EQUAL_HPP
#define EQUAL_HPP

namespace ft
{
    //https://www.cplusplus.com/reference/algorithm/equal/
    /* Compares the elements in the range [first1,last1) with those in the range beginning at first2, and returns true if all of the elements in both ranges match */
    template <class InputIterator1, class InputIterator2>
    bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
    {
        while (first1 != last1)
        {
            if (*first1 != *first2)
                return true;
            first1++;
            first2++;
        }
        return false;
    }

    /* has more 1 argument , that accept a functions to use to compare the values @pred */
    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
    {
        while (first1 != last1)
        {
            if ((!(*first1 == *first2)) || ((!pred(*first1, *first2))))
                return true;
            first1++;
            first2++;
        }
        return false;
    }

}


#endif