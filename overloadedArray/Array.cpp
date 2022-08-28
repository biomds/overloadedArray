#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Array.h"
using namespace std;

Array::Array(int arrSize)
	:size(arrSize > 0 ? arrSize:
		throw invalid_argument("Array size must be great than 0")),
	ptr(new int[size])
{
	for (size_t i = 0; i < size; ++i)
	{
		ptr[i] = 0;
	}
}

size_t Array::getsize() const
{
	return size;
}

 Array::Array(const Array& arrTocopy)
	 :size(arrTocopy.size),
	 ptr(new int[size])
{
	 for (size_t i = 0; i < size; ++i)
	 {
		 ptr[i] = arrTocopy.ptr[i];
	 }
}

 Array::~Array()
 {
	 delete[] ptr;
 }

 const Array& Array::operator=(const Array& right)
 {
	 if (&right != this)
	 {
		 if (size != right.size)
		 {
			 delete[] ptr;
			 size = right.size;
			 ptr = new int[size];
		 }
		 for (size_t i = 0; i < size; ++i)
		 {
			 ptr[i] = right.ptr[i];
		 }
	 }
	 return *this; // enables x = y = z, for example
 }

 bool Array::operator ==(const Array& right) const
 {
	 if (size != right.size)
	 {
		 return false;// arrays of different number of elements
	 }
	 else
	 {
		 for (size_t i = 0; i < size; ++i)
		 {
			 if (ptr[i] != right.ptr[i])
			 {
				 return false;// Array contents are not equal
			 }
		 }
	 }
	 return true;// Arrays are equal
 }

 // overloaded subscript operator for non-const Arrays;
 // reference return creates a modifiable lvalue
 int& Array::operator[](int subscript)
 {
	 if (subscript < 0 || subscript >= size)
	 {
		 throw out_of_range("Subscript out of range");
	 }
	 return ptr[subscript];// reference return
 }

 // overloaded subscript operator for const Arrays
 // const reference return creates an rvalue
 int Array::operator[](int subscript) const
 {
	 if (subscript < 0 || subscript >= size)
	 {
		 throw out_of_range("Subscript out of range");
	 }
	 return ptr[subscript];// returns copy of this element
 }

 istream& operator>>(istream& input, Array& a)
 {
	 for (size_t i = 0; i < a.size; ++i)
	 {
		 input >> a.ptr[i];
	 }
	 return input; //enables cin >> x >> y;
 }

 ostream& operator<<(ostream& output, const Array& a)
 {
	 for (size_t i = 0; i < a.size; ++i)
	 {
		 output << setw(12) << a.ptr[i];
		 if ((i + 1) % 4 == 0)
		 {
			 output << endl;
		 }
	 }
	 if (a.size % 4 != 0)
	 {
		 output << endl;
	 }
	 return output; //enables cout << x << y;
 }


