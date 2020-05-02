#ifndef VECTORADT_H
#define VECTORADT_H

#include <string>
#include <vector>
using namespace std;

class VectorADT {
  public:
    VectorADT();
    ~VectorADT();
    void push_back(double val);
    void resize(int newSize);
    void pop_back();
    operator[]();
    operator+();
    operator<<();
    int length() const;
    int curr_capacity() const;
  private:
    double * array;
    int size;    //the number of doubles stored in array
    int capacity;  //the maximum number of doubles that can be stored in array
};
#endif
