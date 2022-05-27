#include "map_tester.hpp"

int main()
{
    map_tester<int, char> tester;

    tester.ConstructorRangeAssignOperator();
    tester.Insert();
    tester.InserRange();
    tester.Erase();
    tester.EraseIterator();
    tester.EraseRange();
    tester.Clear();


}