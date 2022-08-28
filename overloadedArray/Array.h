#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>

class Array
{
	friend std::istream& operator>>(std::istream&, Array&);
	friend std::ostream& operator<<(std::ostream&, const Array&);
public:
	Array(int = 10); //default constructor
	Array(const Array&); //copy constructor
	~Array();
	size_t getsize() const;
	const Array& operator =(const Array&);
	bool operator ==(const Array&) const;
	// inequality operator; returns opposite of == operator
	bool operator !=(const Array& right) const
	{
		return !(*this == right); // invokes Array::operator==
	}
	// subscript operator for non-const objects returns modifiable lvalue
	int& operator[](int);
	//subscript operator for const objects returns rvalue
	int operator[](int) const;
private:
	size_t size;
	int* ptr;
};


#endif
