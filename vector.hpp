#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>

namespace ft
{   
    /*write your class template to accept an Allocator parameter. This is how C++ standard containers are typically written.*/
    template <typename T, typename Allocator = std::allocator<T> >
    class vector
    {
        public:
            /*Member types of original vector https://www.cplusplus.com/reference/vector/vector/?kw=vector*/
            /*vector header*/
            typedef T value_type;
            typedef Allocator allocator_type;
            typedef value_type & reference;
            typedef value_type const & const_reference;
            typedef value_type * pointer;
            typedef value_type const * const_pointer;
            typedef size_t size_type;
            /**/
            //typedef random_access_iteretor<value_type> iteretor;
    
            /*-------------------------------------------------------------------Constructors--------------------------------------------------------------------*/

            /*A constructor that can be called with a single parameter can serve a secondary purpose, of implicitly "converting" the parameter.
            The keyword explicit ensures that constructors will not be used implicitly.
            Note that explicit only makes sense for constructors that can be called with a single parameter.*/

            /* Constructor with empty parameter */
            explicit vector(const allocator_type &allocate = allocator_type())
            :_alloc(allocate), _size(0), _vector(_alloc.allocate(0)), _capacity(0)
            {};

            /*A overload contructor with two parameters size of vector and value to be Fill*/
            explicit vector(size_type vector_size, const value_type &value, const allocator_type &allocate = allocator_type())
            :_vector(_alloc.allocate(vector_size)), _size(vector_size), _alloc(allocate), _capacity(vector_size)
            {
                for (size_type i = 0; i < vector_size; ++i)
                    _alloc.construct(&_vector[i], value);
            }
            
            /*--------------------------------------------------------------------Functions--------------------------------------------------------------------------*/
            /*increase by 1 de size of the vector and add the value to the end*/
            void push_back(const value_type &value)
            {
                increaseVector(++_size);
                _alloc.construct(&_vector[_size - 1], value);
            }
            
            /*Destroy the last element of vector and resize*/
            void pop_back()
            {
                if (_size)
                    _alloc.destroy(&_vector[_size-- - 1]);
            }

            /*@ret the number of elements in the vector*/
            size_type size() const
            {return _size;}

            /*@ret the the theoretical maximum number of items that could be put in your vector*/
            size_type max_size() const
            {return _alloc.max_size();}

            /* increase  the size of vector allocating more memory*/
            /* Call vector destructor to destroy the old pointer*/
            void increaseVector(size_type size)
            {
                pointer tmp = _alloc.allocate(size);
                for (size_type i = 0; i < _size; ++i)
                    _alloc.construct(&tmp[i], _vector[i]);
                this->~vector();
                _vector = tmp;
                _capacity = _size;
            }

            /*increase the capacity of vector*/
            void reserve(size_type reserve_value)
            {
                if (reserve_value < _capacity)
                    return;
                else if (reserve_value > max_size())
                    throw std::length_error("vector");
                increaseVector(reserve_value);
                _capacity = reserve_value;
            }

            /*Resize the vector*/
            void resize(size_type new_size, value_type val = value_type())
            {
                while (new_size > _size)
                    push_back(val);
                while (new_size < _size)
                    pop_back();
            }
            
            /*@ret capacity of vector*/
            size_type capacity() const
            {return _capacity;}

            /*@ret true if empty*/
            bool empty()
            {return !_size;}

            /* --------------------------------------------------------------------Destructor---------------------------------------------------------------------------*/
            /*Deallocate all data from vector*/
            ~vector() 
            {
                for (size_t i = 0; i < _size; ++i)
                    _alloc.destroy(&_vector[i]);
                _alloc.deallocate(_vector, _size);
            };

            /*-----------------------------------------------------------------Operators Overload-----------------------------------------------------------------------*/

            /*@ret referense to vector pos*/
            reference operator[] (size_type i)
            {return _vector[i];}

            /*@ret const referense to vector pos*/
            const_reference operator[] (size_type i) const
            {return _vector[i];}
    private:
            allocator_type _alloc;
            size_type _size;
            pointer _vector;
            size_type _capacity;
    };
}

#endif