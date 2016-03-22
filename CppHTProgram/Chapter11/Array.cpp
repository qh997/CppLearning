#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Array.h"

using namespace std;


Array::Array(int arraySize)
{
	size = (arraySize > 0 ? arraySize : 10);
	ptr = new int[size];

	for (int i = 0; i < size; i++)
		ptr[i] = 0;
}

Array::Array(const Array &arrayToCopy) // 拷贝构造函数
	: size(arrayToCopy.size)
{
	ptr = new int[size];

	for (int i = 0; i < size; i++)
		ptr[i] = arrayToCopy.ptr[i];
}

Array::~Array()
{
	delete[] ptr;
}

int Array::getSize() const
{
	return size;
}

const Array &Array::operator=(const Array &right)
{
	if (&right != this)
	{
		if (size != right.size)
		{
			delete[] ptr;
			size = right.size;
			ptr = new int[size];
		}

		for (int i = 0; i < size; i++)
			ptr[i] = right.ptr[i];
	}

	return *this;
}

bool Array::operator==(const Array &right) const
{
	if (right.size != size)
		return false;

	for (int i = 0; i < size; i++)
		if (right.ptr[i] != ptr[i])
			return false;

	return true;
}

bool Array::operator!=(const Array &right) const
{
	return !(*this == right);
}

int &Array::operator[](int index)
{
	if (0 > index || index >= size)
	{
		cerr << "\nError: Index " << index << " out of range" << endl;
		exit(1);
	}

	return ptr[index];
}

int Array::operator[](int index) const
{
	if (0 > index || index >= size)
	{
		cerr << "\nError: Index " << index << " out of range" << endl;
		exit(1);
	}

	return ptr[index];
}

std::ostream &operator<<(std::ostream &output, const Array &a)
{
	int i = 0;

	for (i = 0; i < a.size; i++)
	{
		output << setw(12) << a.ptr[i];

		if (0 == (i + 1) % 4)
			output << endl;
	}

	if (0 != i % 4)
		output << endl;

	return output;
}

std::istream &operator>>(std::istream &input, Array &a)
{
	for (int i = 0; i < a.size; i++)
		input >> a.ptr[i];

	return input;
}
