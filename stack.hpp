#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft
{
    template <class T, class Container = vector<T> >
    class stack
    {
    public:
        typedef Container container_type;
        typedef typename Container::value_type value_type;
        typedef typename Container::size_type size_type;
        typedef typename Container::reference reference;
        typedef typename Container::const_reference const_reference;

        explicit stack (const container_type &ctnr = container_type())
        {_container = ctnr;}

        bool empty()
        { return _container.empty();}

        size_type size()
        {return _container.size();}

        reference top()
        {return (_container.end());}

        const_reference top()
        {return (_container.end());}

        void push (const value_type &val);
        {_container.push_back(val);}

        void pop()
        {_container.pop_back();}

        ~stack() {}
    private:
        Container _container;
    };

}

template <class T, class Container>
  bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

template <class T, class Container>
  bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

template <class T, class Container>
  bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

template <class T, class Container>
  bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

template <class T, class Container>
  bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

template <class T, class Container>
  bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);


#endif