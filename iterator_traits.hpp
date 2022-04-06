#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

#include <cstddef>

//https://www.cplusplus.com/reference/iterator/iterator_traits/
/* a interface to the iteretors, For every iterator type, a 
corresponding specialization of iterator_traits class template shall be defined
with at least the following member types defined: */
namespace ft {

    struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct forward_iterator_tag : public input_iterator_tag {};
    struct bidirectional_iterator_tag : public forward_iterator_tag {};
    struct random_access_iterator_tag : public bidirectional_iterator_tag {};


    template<class Iter>
    struct iterator_traits {
    typedef typename Iter::difference_type difference_type;
    typedef typename Iter::value_type value_type;
    typedef typename Iter::pointer pointer;
    typedef typename Iter::reference reference;
    typedef typename Iter::iterator_category	iterator_category;
    };

    template<class T>
    struct iterator_traits<T*> {
    typedef std::ptrdiff_t difference_type;
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
    typedef random_access_iterator_tag iterator_category;
    };

    template<class T>
    struct iterator_traits<const T*> {
    typedef std::ptrdiff_t difference_type;
    typedef T value_type;
    typedef const T* pointer;
    typedef const T& reference;
    typedef random_access_iterator_tag iterator_category;
    };
}

#endif