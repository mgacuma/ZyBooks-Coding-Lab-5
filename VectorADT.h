#ifndef VECTORADT_H
#define VECTORADT_H

#include <string>
#include<iostream>

using namespace std;

class VectorADT {

	friend ostream& operator<<(ostream& os, const VectorADT& v);

	public:

		VectorADT();
		VectorADT(const VectorADT& origClass);
		~VectorADT();
		void push_back(double val);
		void resize(int newSize);
		void pop_back();
		VectorADT& operator=(const VectorADT& origClass);
		double& operator[](int i);
		VectorADT operator+(const VectorADT& rhs);
		int length() const;
		int curr_capacity() const;

	private:

		double * array;
		int size;    //the number of doubles stored in array
		int capacity;  //the maximum number of doubles that can be stored in array
};
#endif
