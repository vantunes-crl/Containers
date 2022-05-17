#include "vector_tester.hpp"
#include "../vector.hpp"

int main(int argc, char **argv)
{
    vector_test<int> test;

    test.Push_back();
    test.Resize();
    test.Assign();
    test.Assign_range();
    test.Pop_back();
    test.At();

}