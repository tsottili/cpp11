#include "initializerList.h"
#include "nonStaticMemberInitialize.h"
#include "lambdas.h"
#include "myVariadicTemplate.h"
#include <vector>
#include <iostream>
/*
    links:
        https://gcc.gnu.org/projects/cxx0x.html
		 * -g;-O0;-std=c++11;-Wall;-Wno-unused-variable
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
	lambdas l;
	l.test([] () {return 1;});
	
	// uncommenting this result in error, f1 is defined inside "test" method lambdas.h 
	// auto f1 = [] () {return 1;};
			
	// Hello nullptr 
	void * p1 = nullptr;
	void * p2 = 0;
	if (p1 == p2)
	{
		int a=1;
	}
	
	
	// Variadics
	int total = sum(1,2,3,4,5,6,7,8);
	int total2 = sum(1,2,3,4,5);
	total=total2;
	total2=total;
	
	myVariadicTemplate<int, bool> m(1, true);
	
	m.check();
	
	size_t sz = m.getCount();
	

	
    return 0;
	
}
