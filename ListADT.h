#ifndef LISTADT_H
#define LISTADT_H

#include<string>
using namespace std;

class Node {
   public: 
     Node(){   };  
    //implement this default constructor as an inline function using an initialization section. 0->value, nullptr->next 
     Node(int val) {  } ; 
     //implement this constructor as an inline function using an initialization section. val->value, nullptr->next   
     int value;
     Node *next
};


class ListADT {
  public:
      void push_back(int val);
      void push_frant(int val);
      void pop_back();
      void pop_front();
      operator[]();
      operator<<();
      int length() const;
      
  private:
      Node *head; //point to the first node on the linked list
      int size;  //number of nodes on the linked list
};
#endif
