#include<string>
#include<iostream>

using namespace std;

#include "VectorADT.h"

VectorADT::VectorADT() {
	size = 0;
	capacity = 10;
	array = new double[capacity];

	for (int i = 0; i < capacity; i++) {
		array[i] = 0.00;
	}
}

VectorADT::VectorADT(const VectorADT& origClass) {
	size = origClass.size;
	capacity = origClass.capacity;
	array = new double[origClass.capacity];

	for (int i = 0; i < origClass.capacity; i++) {
		array[i] = origClass.array[i];
	}
}

VectorADT::~VectorADT() {
	if (array != nullptr) {
		delete[] array;
		array = nullptr;
	}
}

void VectorADT::push_back(double val) {

	if (size == capacity) {
		capacity++;
	}

	array[size] = val;
	size++;
}

void VectorADT::resize(int newSize) {
	double* newArr;

	if (newSize == size) {
		size = newSize;
	}

	if (newSize > capacity) {
		capacity = newSize * 2;
	}

	newArr = new double[capacity];
	

	if (newSize < size) {
		size = newSize;

		for (int i = 0; i < size; i++) {
			newArr[i] = array[i];
		}

		for (int i = size; i < capacity; i++) {
			newArr[i] = 0.00;
		}
	}

	else {
		for (int i = 0; i < size; i++) {
			newArr[i] = array[i];
		}
		for (int i = size; i < newSize; i++) {
			newArr[i] = 0.00;
		}
	}

	delete[] array;
	array = newArr;
}

void VectorADT::pop_back() {
	size--;
}

VectorADT& VectorADT::operator=(const VectorADT& origClass) {
	VectorADT newVec;

	if (this == &origClass) { return *this; }

	newVec.size = origClass.size;
	newVec.capacity = origClass.capacity;


	for (int i = 0; i < origClass.capacity; i++) {
		newVec.array[i] = origClass.array[i];
	}

	return newVec;
}

double VectorADT::operator[](int i) {
	if (i < size) {
		return array[i];
	}
	else { return -1.0; }
}

VectorADT VectorADT::operator+(const VectorADT& rhs) {
	VectorADT newVec;
	
	newVec.size = rhs.size;
	newVec.capacity = rhs.capacity;

	if (size == rhs.size) {
		int i;
		for (i = 0; i < size; i++) {
			newVec.array[i] = array[i] + rhs.array[i];
		}
	}

	return newVec;
}

std::ostream& operator<<(std::ostream& os, const VectorADT& v) {
	int i;
	if (v.size > 0) {
		for (i = 0; i < v.size - 1; i++) {
			os << v.array[i] << ",";
		}

		os << v.array[v.size - 1] << endl;

		return os;
	}

	else {
		string out = "List is empty.";
		os << out << endl;
		return os;
	}
}

int VectorADT::length() const {
	return size;
}

int VectorADT::curr_capacity() const {
	return capacity;
}
