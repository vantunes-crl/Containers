#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

namespace ft
{
    template <class T, T v>
    struct integral_constant
    {
        typedef T value_type;
        typedef integral_constant<T, v> type;
        static const T value = v;
        operator T()
        {return v;}
    };

    typedef integral_constant<bool, true> true_type;
    typedef integral_constant<bool, false> false_type;

    template <class T>
    struct is_integral : false_type
    {};

    template <>
    struct is_integral<bool> : true_type
    {};

    template <>
    struct is_integral<char> : true_type
    {};

    template <>
    struct is_integral<wchar_t> : true_type
    {};

    template <>
    struct is_integral<signed char> : true_type
    {};

    template <>
    struct is_integral<short int> : true_type
    {};

    template <>
    struct is_integral<int> : true_type
    {};

    template <>
    struct is_integral<long int> : true_type
    {};

    template <>
    struct is_integral<long long int> : true_type
    {};

    template <>
    struct is_integral<unsigned char> : true_type
    {};

    template <>
    struct is_integral<unsigned short int> : true_type
    {};

    template <>
    struct is_integral<unsigned int> : true_type
    {};

    template <>
    struct is_integral<unsigned long int> : true_type
    {};

    template <>
    struct is_integral<unsigned long long int> : true_type
    {};
}

#endif