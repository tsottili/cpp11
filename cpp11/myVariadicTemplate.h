#ifndef MYVARIADICTEMPLATE_H
#define MYVARIADICTEMPLATE_H

#include <tuple>

// sum a series of values with variadis.
template <typename T>
int sum(T t)
{
	return t;
}

template <typename T, typename ... A>
int sum(T t, A... a) 
{
	return t + sum(a...);
}


//more on variadics.
template <typename... variadics> 
class myVariadicTemplate
{
public:
	myVariadicTemplate(variadics... a ) : mMyTuple(a...)
	{
		//mMyTuple = a;
	
	};
	
	 
	
	~myVariadicTemplate()
	{
		
	};

protected:

	// Store arguments in a tuple
	std::tuple<variadics...> mMyTuple;

	// Operator sizeof... get size of template arguments.
	size_t mCount = sizeof...(variadics);

public:	
	
	size_t getCount()	
	{
		return mCount;
		// return sizeof...(variadics);
	};

	void check()
	{
		auto a = std::get<0>(mMyTuple);
		auto b = std::get<1>(mMyTuple);
	}
};

#endif // MYVARIADICTEMPLATE_H
