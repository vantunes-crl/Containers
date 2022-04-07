#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

//https://en.cppreference.com/w/cpp/types/is_integral
/* checks whether T is an integral type. Provides the member constant value which is equal to true, if T is the type bool, char, char8_t (since C++20),
char16_t, char32_t, wchar_t, short, int, long, long long, or any implementation-defined extended integer types, including any signed,
unsigned, and cv-qualified variants. Otherwise, value is equal to false. */
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