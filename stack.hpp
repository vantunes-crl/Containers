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
          {return _container.empty();}

          size_type size()
          {return _container.size();}

          value_type &top()
          {return (_container.back());}

          const value_type &top() const
          {return (_container.back());}

          void push (const value_type &val)
          {_container.push_back(val);}

          void pop()
          {_container.pop_back();}

          friend bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
          {return (lhs._container == rhs._container);}

          friend bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
          {return (lhs._container != rhs._container);}

          friend bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
          {return (lhs._container < rhs._container);}

          friend bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
          {return (lhs._container <= rhs._container);}

          friend bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
          {return (lhs._container > rhs._container);}

          friend bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
          { return (lhs._container >= rhs._container);}

          ~stack() {}
      private:
          Container _container;
    };
}


#endif