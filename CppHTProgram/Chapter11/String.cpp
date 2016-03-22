#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include "String.h"

using namespace std;

ostream &operator<<(ostream &output, const String &str)
{
	output << str.sPtr;

	return output;
}

istream &operator>>(istream &input, String &str)
{

}

String::String(const char *cstr)
	: length(0), size(0), sPtr(NULL)
{
	setString(cstr);
}

String::String(const String &str)
	: length(0), size(0), sPtr(NULL)
{
	setString(str.sPtr);
}

String::~String()
{
	delete [] sPtr;
}

const String &String::operator=(const String &str)
{
	if (&str != this)
	{
		setString(str.sPtr);
	}

	return *this;
}

const String &String::operator+=(const String &str)
{
	const size_t newSize = str.length + length + 1;

	if (newSize > size)
	{
		char *newsPtr = new char[newSize];
		if (NULL == newsPtr)
		{
			cerr << "ERROR: Alloc failed!" << endl;
			exit(1);
		}

		strcpy(newsPtr, sPtr);
		delete [] sPtr;
		sPtr = newsPtr;
	}

	strcpy(sPtr + length, str.sPtr);
	size = newSize;
	length = size - 1;

	return *this;
}

bool String::operator!() const
{
	return (0 == length);
}

bool String::operator==(const String &str) const
{
	if (str.length != length)
		return false;
	
	return 0 == strcmp(sPtr, str.sPtr);
}

bool String::operator!=(const String &str) const
{
	return !(*this == str);
}

bool String::operator<(const String &str) const
{
	return 0 > strcmp(sPtr, str.sPtr);
}

bool String::operator<=(const String &str) const
{
	return !(str < *this);
}

bool String::operator>(const String &str) const
{
	return str < *this;
}

bool String::operator>=(const String &str) const
{
	return !(*this < str);
}

char &String::operator[](int index)
{
	if (index < 0 || length > index)
	{
		cerr << "Index out of range" << index << endl;
	}

	return *(sPtr + index);
}

char String::operator[](int index) const
{
	if (index < 0 || length > index)
	{
		cerr << "Index out of range" << index << endl;
	}

	return *(sPtr + index);
}

String String::operator()(const int index, const int subLength) const
{
	char *newPtr = NULL;
	char *cpyPtr = sPtr + index;
	size_t newLen = 0;

	if ((index < 0 && index + subLength <= 0)
		|| (index >= length && index + subLength >= static_cast<int>(length))
		|| subLength == 0)
	{
		return "";
	}

	newLen = (index + subLength) < 0      ? (cpyPtr = sPtr, index + 1)
		   : subLength < 0                ? (cpyPtr = sPtr + index + subLength + 1, -subLength)
		   : (index + subLength) > length ? length - index
		   :                                subLength;

	cout << "newLen = " << newLen << endl;

	newPtr = new char[newLen + 1];
	if (NULL == newPtr)
	{
		cerr << "ERROR: Alloc failed!" << endl;
		exit(1);
	}

	strncpy(newPtr, cpyPtr, newLen);
	newPtr[newLen] = '\0';

	String tempString(newPtr);
	delete [] newPtr;

	return tempString;
}

size_t String::getLength() const
{
	return length;
}

void String::setString(const char *cstr)
{
	if (NULL == cstr)
	{
		length = 0;
		*sPtr = '\0';
	}
	else
	{
		length = strlen(cstr);

		if (length >= size)
		{
			delete [] sPtr;
			
			size = length + 1;
			sPtr = new char[size];
			if (NULL == sPtr)
			{
				cerr << "ERROR: Alloc failed!" << endl;
				exit(1);
			}
		}

		strcpy(sPtr, cstr);
	}
}
