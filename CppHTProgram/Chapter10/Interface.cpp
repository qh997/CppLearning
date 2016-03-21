#include "Interface.h"
#include "Implemetation.h"

Interface::Interface(int v)
	: ptr(new Implemetation(v))
{}

void Interface::setValue(int v)
{
	ptr->setValue(v);
}

int Interface::getValue() const
{
	return ptr->getValue();
}

Interface::~Interface()
{
	delete ptr;
}
