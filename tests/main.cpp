#include "vector_tester.hpp"
#include "../vector.hpp"

#define VECTOR &std::vector<int>
#define FT_VECTOR &ft::vector<int>

int main(int argc, char **argv)
{
    vector_test<int> test;

    test.Push_back();
    test.Assign();

}