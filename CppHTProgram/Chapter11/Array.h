#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

class Array
{
	friend std::ostream &operator<<(std::ostream &output, const Array &a);
	friend std::istream &operator>>(std::istream &input, Array &a);

public:
	explicit Array(int arraySize = 10);
	Array(const Array &arrayToCopy);
	~Array();

	int getSize() const;

	const Array &operator=(const Array &right);
	bool operator==(const Array &right) const;
	bool operator!=(const Array &right) const;
	int &operator[](int index);
	int operator[](int index) const;

private:
	int size;
	int *ptr;
};

#endif
