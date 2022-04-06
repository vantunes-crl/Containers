#ifndef ENABLE_IF
#define ENABLE_IF

//https://www.cplusplus.com/reference/type_traits/enable_if/
/*The type T is enabled as member type enable_if::type if Cond is true */
namespace ft
{
    template <bool Cond, class T = void>
    struct enable_if {};

    template <class T>
    struct enable_if<true, T> {
    typedef T type;
};
}

#endif