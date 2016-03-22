#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstdlib>

class String
{
	friend std::ostream &operator<<(std::ostream &output, const String &str);
	friend std::istream &operator>>(std::istream &input, String &str);

public:
	String(const char *cstr = "");
	String(const String &str);
	~String();

	const String &operator=(const String &str);
	const String &operator+=(const String &str);

	bool operator!() const;
	bool operator==(const String &str) const;
	bool operator!=(const String &str) const;
	bool operator<(const String &str) const;
	bool operator<=(const String &str) const;
	bool operator>(const String &str) const;
	bool operator>=(const String &str) const;
	char &operator[](int index);
	char operator[](int index) const;
	String operator()(int index, int subLength) const;

	size_t getLength() const;

private:
	size_t length;
	size_t size;
	char *sPtr;

	void setString(const char *str);
};

#endif
