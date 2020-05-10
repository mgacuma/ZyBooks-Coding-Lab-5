#ifndef LISTADT_H
#define LISTADT_H

#include <string>
#include<iostream>

using namespace std;

class Node {
   public:
     Node(){
    	 value = 0;
    	 next = nullptr;
     }
    //implement this default constructor as an inline function using an initialization section. 0->value, nullptr->next
     Node(int val){
		value = val;
		next = nullptr;
     }
     //implement this constructor as an inline function using an initialization section. val->value, nullptr->next
     int value;
     Node* next;
};

class ListADT {
	friend ostream& operator<<(ostream& os, const ListADT& l);

  public:
    ListADT();
    ListADT(const ListADT& origClass);
    ~ListADT();
    void push_back(int val);
    void push_front(int val);
    void pop_back();
    void pop_front();


    ListADT& operator=(const ListADT& origClass);
    int& operator[](int i);


    int length() const;

  private:
    Node* head; //point to the first node on the linked list
    int size;  //number of nodes on the linked list

};




#endif
