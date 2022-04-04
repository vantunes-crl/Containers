#ifndef RANDOM_ACESS_ITERATOR_HPP
#define RANDOM_ACESS_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
    template <typename T>
    class random_access_iterator
    {
        public:
            /* iterator Header */
            typedef T value_type;
            typedef value_type & reference;
            typedef value_type const & const_reference;
            typedef value_type * pointer;
            typedef value_type const * const_pointer;
            typedef std::ptrdiff_t difference_type;
            typedef size_t size_type;
            typedef random_access_iterator_tag	iterator_category;

            /* Default Contructors pointing to nullptr */
            random_access_iterator():_container_ptr(nullptr) {}

            /* Overload contructor pointing to container_ptr */
            random_access_iterator(pointer container_ptr): _container_ptr(container_ptr) {}

            /* Cpy constructor */
            random_access_iterator(const random_access_iterator &new_objct) {*this = new_objct;}

            /*Overload operators*/
            /*https://www.cplusplus.com/reference/iterator/RandomAccessIterator/*/
            random_access_iterator &operator=(const random_access_iterator &new_object)
            {
                _container_ptr = new_object._container_ptr;
                return (*this);
            }

            bool operator==(const random_access_iterator &obj2) const
            {return _container_ptr == obj2._container_ptr;}

            bool operator !=(const random_access_iterator &obj2) const
            {return !(*this == obj2);}

            pointer operator->() const
            {return _container_ptr;}
            
            reference operator*() const
            {return *_container_ptr;}

            //Prefix increment
            random_access_iterator &operator++()
            {++_container_ptr;return *this;}

            //Posfix increment create a copy, increment and return, @Tip Posfix uses more memory then Prefix
            random_access_iterator operator++(int)
            {
                random_access_iterator temp = *this;
                ++*this;
                return (temp);
            }

            //Prefix decrement
            random_access_iterator &operator--()
            {--_container_ptr; return *this;}

            //Posfix increment create a copy, increment and return, @Tip Posfix uses more memory then Prefix
            random_access_iterator operator--(int)
            {
                random_access_iterator<T> temp = *this;
                --*this;
                return (temp);
            }
            
            /*std::ptrdiff_t is used for pointer arithmetic and array indexing, if negative values are possible.
            Programs that use other types, such as int, may fail on may fail on,
            e.g. 64-bit systems when the index exceeds INT_MAX or if it relies on 32-bit modular arithmetic. */
            //https://en.cppreference.com/w/cpp/types/ptrdiff_t
            random_access_iterator  operator+(difference_type n)
            {return (_container_ptr + n);}

            random_access_iterator  operator-(difference_type n)
            {return (_container_ptr - n);}

            random_access_iterator operator-=(difference_type n)
            {return _container_ptr -= n;}

            random_access_iterator operator+=(difference_type n)
            {return _container_ptr += n;}

            bool operator<(random_access_iterator &obj2) const
            {return _container_ptr < obj2._container_ptr;}

            bool operator>(random_access_iterator &obj2) const
            {return _container_ptr > obj2._container_ptr;}

            bool operator<=(random_access_iterator &obj2) const
            {return _container_ptr <= obj2._container_ptr;}

            bool operator>=(random_access_iterator &obj2) const
            {return _container_ptr >= obj2._container_ptr;}

            reference operator[](difference_type n) const
            {return _container_ptr[n];}

        ~random_access_iterator() {}
        private:
            pointer _container_ptr;

            
    };
}


#endif