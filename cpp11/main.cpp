#include "initializerList.h"
#include "nonStaticMemberInitialize.h"
#include <vector>
#include <iostream>
/*
    links:
        https://gcc.gnu.org/projects/cxx0x.html
*/



int main(int argc, char **argv)
{
    // Initializer lists examples
    initializerList il{1,true};
	// return value can be an initializer list
    StInitList s = il.testInitList();

	static_assert(sizeof (s.a) ==4, "int are changed!!!!");
	// uncomment this! --> static_assert(sizeof (s.a) ==3, "How big is an int?");

	initializerListConstructor ilc = {1,2,3,4,5};
	
		
	// auto make iterator cycles simpler!
	
	// legacy
    ;std::vector<int> v = {0,1,2,3,4,5,6,7,8,9};
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        std::cout << *it << ",";
    }

    std::cout << std::endl;

	// simpler 
    for (auto it = v.begin(); it != v.end(); it++)
    {
        std::cout << *it << ",";
    }

    std::cout << std::endl;

	// range based loop
    for (auto& i : v)
    {
        std::cout << i << ",";
    }

    std::cout << std::endl;

	//finding type
	auto a = 10;
	decltype(a)  b = 11;
	

	// Non static member initialize where declared.
	nonStaticMemberInitialize nSMI;
	
	if ( (nSMI.getival() == NSMI_TEST_IVAL_VALUE) &&
		 (nSMI.getbval() == NSMI_TEST_BVAL_VALUE) )
	{
		std::cout << "nonStaticMemberInitialize test passed!" << std::endl;
	}
	
	// Lambdas
	
	

	
	// I don't want warnings!
	s.a = a;
	s.b = b;
	b = a;
	a = b;
	
    return 0;
	
}
