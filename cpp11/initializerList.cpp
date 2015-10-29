#include "initializerList.h"
#include <string>
#include <map>
#include <vector>

initializerList::initializerList()
{
    //ctor
}

initializerList::initializerList(int i, bool b) : m_iVal(i), m_bVal(b)
{
    //ctor
}



initializerList::~initializerList()
{
    //dtor
}

StInitList initializerList::testInitList()
{
    // struct initializers
    StInitList s = {5, true, 3.14};
    StInitList vs[] = { {1, false, 1.1}, {2, true, 2.2}, {3, false, 3.3}};
    StInitList vs2[2] = {s, vs[1]};

    // standard container initializers
    std::vector<std::string> v = { "pippo", "pluto", "paperino" };
    std::map<int, std::string> m = { {1,"pippo"}, {vs2[0].a, "pluto"} };

    // no type defined here
    return { 1, true, 3.14 };
};