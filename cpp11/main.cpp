#include "initializerList.h"
#include "nonStaticMemberInitialize.h"
#include "lambdas.h"
#include "myVariadicTemplate.h"
#include "override.h"
#include "constructorDelegates.h"
#include "testStrings.h"

#include <vector>
#include <iostream>

/*
    links:
        https://gcc.gnu.org/projects/cxx0x.html
		 
*/

int main(int argc, char **argv)
{
	// __func__ is the function name
	std::cout << __func__ << std::endl;
	
	// type alias, this is not a new type.
	using myInt = int;
	using myBool = bool;
		
	// type alias & template
	// TODO.

	
    // Initializer lists examples
    initializerList il{1,true};
	// return value can be an initializer list
    StInitList s = il.testInitList();

	static_assert(sizeof (s.a) ==4, "int are changed!!!!");
	// uncomment this! --> static_assert(sizeof (s.a) ==3, "How big is an int?");

	initializerListConstructor ilc = {1,2,3,4,5};

		
	// auto make iterator cycles simpler!
	
	// legacy
    ;std::vector<myInt> v = {0,1,2,3,4,5,6,7,8,9};
    for (std::vector<myInt>::iterator it = v.begin(); it != v.end(); it++)
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
		myInt a=1;
	}
	
	
	// Variadics
	myInt total = sum(1,2,3,4,5,6,7,8);
	myInt total2 = sum(1,2,3,4,5);
	total=total2;
	total2=total;
	
	myVariadicTemplate<myInt, myBool> m(1, true);
	
	m.check();
	
	size_t sz = m.getCount();
	

	// enum class 
	
	// the same value can be present in two differents enum class 	
	enum class Animals {horse, dog, cow, lion};
	enum class Pets {fish, cat, dog};
	
	
	// these doesn't compile
	// bool b = (animals::dog == pets::dog)
	
	// bool b2 = animals::dog == 1;
	
	Animals animal;
	
	// this is ok
	animal = Animals::dog;
	
	// this doesn't compile
	//animal = dog;
	
	testString();
	
	return 0;
	
}
