#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft
{
    //https://www.cplusplus.com/reference/utility/pair/pair/
    template< class T1, class T2> 
    struct pair
    {
        T1 first;
        T2 second;

        pair() : first(T1()), second(T2()) {}

        pair(const T1 &a, const T2 &b) : first(a), second(b) {}

        template <class U, class V>
        pair(const pair<U, V> &pr) : first(pr.first), second(pr.second) {}

        pair &operator=(const pair &pr)
        {
            first = pr.first;
            second = pr.second;
            return (*this);
        }

    };

    template <class T1, class T2>
    bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return lhs.first == rhs.first && lhs.second == rhs.second;
    }

    template <class T1, class T2>
    bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return !(lhs == rhs);
    }

    template <class T1, class T2>
    bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
    }

    template <class T1, class T2>
    bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return !(rhs < lhs);
    }

    template <class T1, class T2>
    bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return rhs < lhs;
    }

    template <class T1, class T2>
    bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return !(lhs < rhs);
    }

    template< class T1, class T2 >
    pair<T1, T2> make_pair(T1 t,T2 u)
    {
        return (pair<T1, T2>(t, u));    
    };
}


#endif