#ifndef INITIALIZER_LIST_H
#define INITIALIZER_LIST_H 

#include <initializer_list>
#include <iostream>

struct StInitList
{
    int a;
    bool b;
    double c;
};

class initializerList
{
public:
	initializerList();
	initializerList(int i, bool b);

	virtual ~initializerList();

protected:

	int m_iVal;
	bool m_bVal;

public:

	StInitList testInitList();
};



// This object can be build only using initializer list
class initializerListConstructor
{
	public:
	initializerListConstructor(std::initializer_list<int> list)
	{
		for (auto& i : list)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}	
};

#endif // INITIALIZER_LIST_H
