#ifndef OVERRIDE_H
#define OVERRIDE_H


class Base
{	
public:
	Base()	{};
	~Base()	{};

public:

	virtual void myPureVirtualMethod() = 0;
	
	virtual void myVirtualMethod()
	{
		int myBaseImplementation = 0;
	}
	
	void myNotVirtualMethod()
	{
		int myBaseNotVirtual = 0;
	}

};

class Derived final : public Base
{
public:
	Derived() {};
	~Derived() {};


	void myPureVirtualMethod() override
	{
		bool myDerivedImplementation;
	};
	
	virtual void myVirtualMethod() override
	{
		int myDerivedImplementation = 0;
	} 

	// compile error uncommenting this. 
	// Can't override a non virtual functions
	//void myNotVirtualMethod() ovveride
	//{
	//	int myDerivedNotVirtual = 0;
	//}

};

// compile error deriving a "final" class
//class MoreThanFinal : public Derived
//{
//}



#endif // OVERRIDE_H
