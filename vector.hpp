#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include "type_traits/type_traits.hpp"
#include "algorithm/algorithm.hpp"
#include "utility/utility.hpp"
#include "iterator/iterator.hpp"

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
            /* iterators */
            typedef random_access_iterator<value_type> iterator;
            typedef random_access_iterator<const value_type> const_iterator;
            typedef reverse_iterator<const_iterator> const_reverse_iterator;
            typedef reverse_iterator<iterator> reverse_iterator;
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

            template <class InputIterator>
            vector (typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const allocator_type &allocate = allocator_type())
            :_alloc(allocate), _capacity(0), _size(0)
            {
                InputIterator start = first;
                InputIterator end = last;

                int range = 0;
                while (start++ != end)
                    range++;
                _vector = _alloc.allocate(range);
                int i = 0;
                while (first != last)
                {
                    _alloc.construct(&_vector[i], *first);
                    first++;
                    i++;
                    _size++;
                    _capacity++;
                    
                }
            }

            /*--------------------------------------------------------------------cpy constructor----------------------------------------------------------------------*/
            vector &operator=(const vector &cpy)
            {
                this->~vector();
                _alloc = cpy._alloc;
                _vector = _alloc.allocate(cpy._capacity);
                _capacity = cpy._capacity;
                _size = cpy._size;
                for (size_type i = 0; i < _size; ++i)
                    _alloc.construct(&_vector[i], cpy._vector[i]);
                return *this;
            }

            vector(const vector &cpy)
            {*this = cpy;}
            
            /*--------------------------------------------------------------------Functions--------------------------------------------------------------------------*/
            /*increase by 1 de size of the vector and add the value to the end*/
            void push_back(const value_type &value)
            {
                ++_size;
                if (_size > _capacity)
                {
                    if (_capacity)
                        increaseVector(_capacity * 2);
                    else
                        increaseVector(1);
                }
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
                if (new_size > _capacity)
                {
                    int i = -1;
                    pointer tmp = _alloc.allocate(new_size);
                    while (++i < _size)
                        _alloc.construct(&tmp[i], _vector[i]);
                    while (i < new_size)
                        _alloc.construct(&tmp[i++], val);
                    _alloc.deallocate(_vector, _capacity);
                    _vector = tmp;
                    _capacity = new_size;
                    _size = new_size;
                }
                else
                {
                    while (_size != new_size)
                        _alloc.destroy(&_vector[_size--]);
                }
            }
            
            /*@ret capacity of vector*/
            size_type capacity() const
            {return _capacity;}

            /*@ret true if empty*/
            bool empty()
            {return !_size;}

            /* --------------------------------------------------------------------Destructor---------------------------------------------------------------------------*/
            /*Deallocate all data from vector*/
            virtual ~vector() 
            {
                for (size_t i = 0; i < _capacity; ++i)
                    _alloc.destroy(&_vector[i]);
                _alloc.deallocate(_vector, _capacity);
            };

            /*-----------------------------------------------------------------Operators Overload-----------------------------------------------------------------------*/

            /*@ret referense to vector pos*/
            reference operator[] (size_type i)
            {return _vector[i];}

            /*@ret const referense to vector pos*/
            const_reference operator[] (size_type i) const
            {return _vector[i];}

            /*---------------------------------------------------------------Iterators----------------------------------------------------------------------------------*/

            /* Normal iterator */
            iterator begin() {return _vector;}
            const_iterator begin()  const {return _vector;}

            const_iterator  end() const {return _vector + _size;}
            iterator end() {return _vector + _size;}

            /* reverse iterators */
            reverse_iterator rbegin() {return reverse_iterator(_vector + _size - 1);}
            const_reverse_iterator rbegin() const {return const_reverse_iterator(_vector + _size - 1);}

            const_reverse_iterator  rend() const {return const_reverse_iterator(_vector - 1);}
            reverse_iterator rend() {return reverse_iterator(_vector - 1);}

            /*---------------------------------------------------------------elementor access-------------------------------------------------------------------------------*/

            /*@ret pos*/
            reference at(size_type n)
            {return _vector[n];}

            /*@ret const pos*/
            const_reference at(size_type n) const
            {return _vector[n];}

            /* @ret the first element of vector */
            reference front()
            {return *_vector;}

            /* @ret the first const element of vector */
            const_reference front() const
            {return *_vector;}

            /* @ret the last element of vector */
            reference back()
            {return *(_vector + _size - 1);}

            /* @ret the last const element of vector */
            const_reference back() const
            {return *(_vector + _size - 1);}

            /*---------------------------------------------------------------modifier-------------------------------------------------------------------------------*/

            /*insert a element at the iterator position, @ret a iterator to the new pos*/
            iterator insert(iterator position, const value_type &val)
            {
                size_t pos = begin() - position;
                pointer temp;
                if (++_size > _capacity)
                    temp = _alloc.allocate(_capacity *= 2);
                else
                    temp = _alloc.allocate(_capacity);
                int i, j;
                i = j = 0;
                while (i < _size)
                {
                    if (i == pos)
                        temp[j++] = val;
                    _alloc.construct(&temp[j], _vector[i]);
                    ++i; ++j;
                }
                this->~vector();
                _vector = temp;
                return iterator(&_vector[pos]);
            }

            /* insert n elements in the vector pos @no ret */
            void insert (iterator position, size_type n, const value_type& val) //fix capacity
            {
                size_t pos = begin() - position;
                pointer temp;
                if  ((_size += n) > _capacity)
                {
                    while (_capacity < _size)
                        _capacity *= 2;
                    temp = _alloc.allocate(_capacity);
                }
                else
                    temp = _alloc.allocate(_capacity);

                int i, j;
                i = j = 0;
                while (i < _size - n)
                {
                    if (i == pos)
                    {
                        int it = n;
                        while (it--)
                            temp[j++] = val;
                    }
                    _alloc.construct(&temp[j], _vector[i]);
                    ++j; ++i;
                }
                _alloc.deallocate(_vector, _capacity);
                _vector = temp;
            }

            /* insert n elements in the vector from a range of elements from first to last */
            template <class InputIterator>
            void insert (iterator position, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
            {
                size_t pos = begin() - position;
                size_t range = last - first;
                pointer temp;
                if  ((_size += range) > _capacity)
                    temp = _alloc.allocate(_capacity *= 2);
                else
                    temp = _alloc.allocate(_capacity);

                size_t i, j;
                i = j = 0;
                while (i < _size - range)
                {
                    if (i == pos)
                    {
                        while (first != last)
                        {
                            _alloc.construct(&temp[j++], *first);
                            ++first;
                        }
                    }
                    _alloc.construct(&temp[j], _vector[i]);
                    ++j; ++i;
                }
                _alloc.deallocate(_vector, _capacity);
                _vector = temp;
            }

            /* erase a element in the vector and return the new pos */
            iterator erase (iterator position)
            {
                size_t pos = position - begin();
                pointer temp;
                temp = _alloc.allocate(_capacity);
                int i, j;
                i = j = 0;
                while (i < _size)
                {
                    if (i == pos)
                        ++i;
                    temp[j] = _vector[i];
                    ++j;
                    ++i;
                }
                this->~vector();
                _vector = temp;
                --_size;
                return iterator(&_vector[pos]);
            }

            /* erase a n of elements from the first iterator to the last */
            iterator erase (iterator first, iterator last)
            {
                size_t range = last - first;
                size_t pos = first - begin();
                int i, j;
                i = j = 0;
                pointer temp;
                temp = _alloc.allocate(_capacity);
                while (i < _size)
                {
                    if (i == pos)
                        i += range;
                    temp[j] = _vector[i];
                    ++i;
                    ++j;
                }
                this->~vector();
                _size -= range;
                _vector = temp;
                return iterator(&_vector[pos]);
            }

            /* clear all the elements in vector */
            void clear()
            {
                while (_size)
                    pop_back();
            }

            /* assign new values to the container*/
            template <class InputIterator>
            void assign (typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
            {
                this->~vector();
                _size = 0;
                size_t range = last - first;
                _vector = _alloc.allocate(_capacity);
                while (first != last)
                {
                    _vector[_size] = *first;
                    ++first;
                    ++_size;
                }
            }

            /* assign new values to the container*/
            void assign (size_type n, const value_type &val)
            {
                if (n > _capacity)
                {
                    this->~vector();
                    _vector = _alloc.allocate(n);
                    _capacity = n;
                }
                else
                    clear();
                int i = 0;
                while (i < n)
                {
                    _vector[i] = val;
                    ++i;     
                }
                _size = n;
            }

            void swap (vector &x)
            {
                vector<value_type> temp;
                temp = *this;
                *this = x;
                x = temp;
            }

            friend bool operator==(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs)
            {
                if (lhs.size() == rhs.size())
                {
                    return (equal(lhs.begin(), lhs.end(), rhs.begin()));
                }
                return (false);
            }

            friend bool operator!=(const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs)
            {return (!(lhs == rhs));}

            friend bool operator<(const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs)
            {return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));}


            friend bool operator<=(const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs)
            {return (!(rhs < lhs));}

            friend bool operator>(const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs)
            {return (rhs < lhs);}

            friend bool operator>=(const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs)
            {return (!(lhs < rhs));}

            friend void swap(vector<T, Allocator> &x, vector<T, Allocator> &y)
            {x.swap(y);}

    private:
            allocator_type _alloc;
            size_type _size;
            pointer _vector;
            size_type _capacity;

            /* basic swap function to swap values inside the class */
            template <class B>
            void swap(B &a, B &b)
            {
                B temp = a;
                a = b;
                b = temp;
            }

            /* increase  the size of vector allocating more memory*/
            /* Call vector destructor to destroy the old pointer*/
            void increaseVector(size_type size)
            {
                pointer tmp = _alloc.allocate(size);
                for (size_type i = 0; i < _size; ++i)
                    _alloc.construct(&tmp[i], _vector[i]);
                _alloc.deallocate(_vector, _capacity);
                _vector = tmp;
                if (_capacity == 1)
                    ++_capacity;
                else
                    _capacity = size;
            }
    };
}

#endif