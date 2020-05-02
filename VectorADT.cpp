#include<string>
using namespace std;

#include "VectorADT.h"
 
  VectorADT::VectorADT(){
    size = 0;
    capacity = 10;
    double arr[capacity] = [0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00];
    array = arr;
  }
  
  VectorADT::~VectorADT(){}aw
  
  void VectorADT::push_back(double val){
       
  }

  void resize(int newSize)
  void pop_back()
  operator[]()
  operator+()
  operator<<()
  int length() const
  int curr_capacity() const
