#include "vector_tester.hpp"
#include "../vector.hpp"

int main(int argc, char **argv)
{
    vector_test<int> test;

    test.Contructors();
    test.Contructor_Range();
    test.Push_back();
    test.Resize();
    test.Reserve();
    test.Pop_back();
    test.At();
    test.Back();
    test.Front();
    test.Clear();
    test.Assign();
    test.Assign_range();
    test.Erase();
    test.EraseRange();
    test.Insert();
    test.InsertPosRgn();
    test.InsertRange();
    

}