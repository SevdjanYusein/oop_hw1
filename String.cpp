// string.cpp : Defines the entry point for the console application.
//

#include "string.h"

void String::copy(const String& other)
{
	erase();
	start = new char[strlen(other.start) + 1];
	strcpy_s(start, strlen(other.start) + 1, other.start);
}
void String::erase()
{
	delete[] start;
}
String::String()
{
	start = new char[1];
	start[0] = 0;
}
String::String(const char* value)
{
	start = new char[strlen(value) + 1];
	strcpy_s(start, strlen(value) + 1, value);
}
String::String(const String& other)
{
	copy(other);
}
String& String::operator=(const String& other)
{
	if (start != other.start)
	{
		copy(other);
	}
	return *this;
}
void String::operator= (const char * value)
{
	erase();
	start = new char[strlen(value) + 1];
	strcpy_s(start, strlen(value) + 1, value);
}
void String::print() const
{
	std::cout << start << std::endl;
}
bool String::operator!=(const String & other)
{
	if (!strcmp(start, other.start)) return false;
	else return true;
}
bool String::operator==(const String & other)const
{
	if (strcmp(start, other.start)) return false;
	else return true;
}
int String::lenght(const String& other)
{
	return strlen(other.start);
}
String::~String()
{
	erase();
}

std::ostream& operator<< (std::ostream& out, const String& str)
{
	out << str.start;
	return out;
}

std::istream& operator>> (std::istream& in, String& str)
{
	char buffer[1024];
	in.getline(buffer, 1024);
	int size = strlen(buffer) + 1;
	delete[] str.start;
	str.start = new char[size];
	for (int i = 0; i < size; i++)
	{
		str.start[i] = buffer[i];
	}
	str.start[size - 1] = 0;
	return in;
}

