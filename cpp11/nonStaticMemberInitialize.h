#ifndef NONSTATICMEMBERINITIALIZE_H
#define NONSTATICMEMBERINITIALIZE_H

#define NSMI_TEST_IVAL_VALUE 10
#define NSMI_TEST_BVAL_VALUE false

class nonStaticMemberInitialize
{
public:
	nonStaticMemberInitialize();
	~nonStaticMemberInitialize();

protected:

	int miVal = NSMI_TEST_IVAL_VALUE;
	bool mbVal = NSMI_TEST_BVAL_VALUE;

public:

	int getival() {return miVal;};
	bool getbval() {return mbVal;};

};

#endif // NONSTATICMEMBERINITIALIZE_H
