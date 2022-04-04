#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
    template <class Iterator>
    class reverse_iterator
    {
        public:
            /* iterator Member types Header */
            typedef Iterator	iterator_type;
            typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
            typedef typename iterator_traits<Iterator>::value_type value_type;
            typedef typename iterator_traits<Iterator>::difference_type difference_type;
            typedef typename iterator_traits<Iterator>::pointer pointer;
            typedef typename iterator_traits<Iterator>::reference reference;

            /* Default Contructors pointing to nullptr */
            reverse_iterator():_container_ptr(nullptr) {}

            /* Overload contructor pointing to container_ptr */
            reverse_iterator(pointer container_ptr): _container_ptr(container_ptr) {}

            /* Cpy constructor */
            reverse_iterator(const reverse_iterator &new_objct) {*this = new_objct;}
            /*Overload operators*/
            /*https://www.cplusplus.com/reference/iterator/RandomAccessIterator/*/
            reverse_iterator &operator=(const reverse_iterator &new_object)
            {
                _container_ptr = new_object._container_ptr;
                return (*this);
            }

            bool operator==(const reverse_iterator &obj2) const
            {return _container_ptr == obj2._container_ptr;}

            bool operator !=(const reverse_iterator &obj2) const
            {return !(*this == obj2);}

            pointer operator->() const
            {return _container_ptr;}
            
            reference operator*() const
            {return *_container_ptr;}

            //Prefix increment
            reverse_iterator &operator++()
            {--_container_ptr;return *this;}

            //Posfix increment create a copy, increment and return, @Tip Posfix uses more memory then Prefix
            reverse_iterator &operator++(int)
            {
                static reverse_iterator temp = *this;
                ++*this;
                return (temp);
            }

            //Prefix decrement
            reverse_iterator &operator--()
            {++_container_ptr; return *this;}

            //Posfix increment create a copy, increment and return, @Tip Posfix uses more memory then Prefix
            reverse_iterator &operator--(int)
            {
                static reverse_iterator temp  = *this;
                --*this;
                return (temp);
            }
            
            /*std::ptrdiff_t is used for pointer arithmetic and array indexing, if negative values are possible.
            Programs that use other types, such as int, may fail on may fail on,
            e.g. 64-bit systems when the index exceeds INT_MAX or if it relies on 32-bit modular arithmetic. */
            //https://en.cppreference.com/w/cpp/types/ptrdiff_t
            reverse_iterator  operator+(difference_type n)
            {return (_container_ptr - n);}

            reverse_iterator  operator-(difference_type n)
            {return (_container_ptr + n);}

            reverse_iterator operator-=(difference_type n)
            {return _container_ptr += n;}

            reverse_iterator operator+=(difference_type n)
            {return _container_ptr -= n;}

            bool operator<(reverse_iterator &obj2) const
            {return _container_ptr > obj2._container_ptr;}

            bool operator>(reverse_iterator &obj2) const
            {return _container_ptr < obj2._container_ptr;}

            bool operator<=(reverse_iterator &obj2) const
            {return _container_ptr >= obj2._container_ptr;}

            bool operator>=(reverse_iterator &obj2) const
            {return _container_ptr <= obj2._container_ptr;}

            reference operator[](difference_type n) const
            {return _container_ptr[-n];}

         ~reverse_iterator() {}
        private:
            pointer _container_ptr;

    };
}


#endif