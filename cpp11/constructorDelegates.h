
class CD
{

public:
	
	CD(int i, bool b) : miVal(i), mbVal(b)
	{
	}
	
	// Constructor delegation
	CD () : CD(-1,true)
	{
	}
	
	// Delegate copy constructor
	CD (CD & cd) : CD(cd.miVal, cd.mbVal)
	{
	}
	
protected:

	int miVal;
	bool mbVal;
	
};