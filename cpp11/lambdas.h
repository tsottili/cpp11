#ifndef LAMBDAS_H
#define LAMBDAS_H

#include <functional>

typedef std::function<bool (int iParam)> CB_FUNC_TYPE;

typedef bool (* CB_FUNC_PTR) (int iParam);


class lambdas
{
public:
	lambdas();
	~lambdas();


protected:
         CB_FUNC_TYPE m_cbfunc;
		
public:
	template <typename Func> void test(Func f)
	{
		// lambdas can be parameter in template functionss
		if (f) f();
		
		// using auto with lambdas
		auto f1 = [] () {return 0;};
		int l2 = f1();
		//short l3 = [] () {return 1;} ;
		
		// setting a callback functions using lambdas
		set_event_callback([] (int iParam) { return (iParam != 0);});
		test_callback();
		
		// lambdas and functional
		CB_FUNC_TYPE f2 = [] (int iParam) {return (iParam == 0);};
		set_event_callback(f2);
		test_callback();
		
		// lambdas and function pointer
		CB_FUNC_PTR f3 = [] (int iParam) {return (iParam == 2);};
		set_event_callback_pointer(f3);
		test_callback(); 
		
		
		// Clojures:
		//[] 	nothing. 
		//[&] 	all referenced variables are for reference
		//[=] 	all referenced variables are copied
		//[=, &var] all referenced variables are copied but var is by reference
		//examples: [var], [&var]
		
		int p1 = 100;
		auto f4 = [&p1] () {p1 = p1*2; return p1;};
		

		int l3 = f4();
		
		if (p1 != l3) 
		{
		   l3=l2;	
		}
		else
		{
			l2 = l3;
	
		}
	}
	
	
	void set_event_callback(CB_FUNC_TYPE cb_func)
	{
			m_cbfunc = cb_func;
	}
	
	void set_event_callback_pointer(CB_FUNC_PTR cb_func)
	{
			m_cbfunc = cb_func;
	}
	
	void test_callback()
	{
			if (m_cbfunc)
			{
				bool b1 = m_cbfunc(0);
				bool b2 = m_cbfunc(1);
				bool b3 = m_cbfunc(2);
				
				b1 = b2;
				b2 = b3;
				b3 = b1;
			}
	}				
	
};

#endif // LAMBDAS_H
