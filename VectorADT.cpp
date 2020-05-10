#include<string>
#include<iostream>

using namespace std;

#include "VectorADT.h"

  VectorADT::VectorADT(){
	size = 0;
    capacity = 10;
    array = new double[capacity];

    for(int i = 0; i < capacity; i++){
    	array[i] = 0.00;
    }
  }

  VectorADT::VectorADT(const VectorADT& origClass){
	  size = origClass.size;
	  capacity = origClass.capacity;
	  array = new double[origClass.capacity];

	  for(int i = 0; i < origClass.capacity; i++){
		  array[i] = origClass.array[i];
	  }
  }

  VectorADT::~VectorADT(){
	  delete[] array;
  }

  void VectorADT::push_back(double val){

	  if(size == capacity){
		  capacity++;
	  }

	  array[size] = val;
	  size++;
  }

  void VectorADT::resize(int newSize){
	  if(newSize <= size){
		  size = newSize;
	  }

	  else {
		  capacity = 2 * newSize;

		  int i;
		  for(i = size; i < capacity; i++){
			  array[i] = 0.00;
		  }

		  size = newSize;
	  }
  }

  void VectorADT::pop_back(){
	  size--;
  }

  VectorADT& VectorADT::operator=(const VectorADT& origClass) {

	  if (this == &origClass) { return *this; }

	  size = origClass.size;
	  capacity = origClass.capacity;


	  for(int i = 0; i < origClass.capacity; i++){
	  		  array[i] = origClass.array[i];
	  }

	  return *this;
  }

  double& VectorADT::operator[](int i){
	  return array[i];
  }

  VectorADT VectorADT::operator+(const VectorADT& rhs){
	  VectorADT asd;
	  asd.size = rhs.size;
	  asd.capacity = rhs.capacity;

	  if(size == rhs.size){
		  int i;
		  for(i = 0; i < size; i++){
			  asd.array[i] = array[i] + rhs.array[i];
		  }
	  }

	  return asd;
  }

  std::ostream& operator<<(std::ostream& os, const VectorADT& v){
	  int i;
	  for (i = 0; i < v.size-1; i++){
		  os << v.array[i] << ",";
	  }

	  os << v.array[v.size-1];

	  return os;
  }

  int VectorADT::length() const{
	  return size;
  }

  int VectorADT::curr_capacity() const{
	  return capacity;
  }
