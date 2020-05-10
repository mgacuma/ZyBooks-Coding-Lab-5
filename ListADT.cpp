#include<string>
#include<iostream>


using namespace std;

#include "ListADT.h"

ListADT::ListADT(){
	head = new Node();
	size = 1;
}

ListADT::ListADT(const ListADT& origClass){

	size = origClass.size;

	Node newHead = *origClass.head;

	head = &newHead;

	Node* currentNode = head->next;

	Node* nodeNext = origClass.head->next;

	for (int i = 1; i < size; i++){
		Node newNext = *nodeNext;
		currentNode = &newNext;

		nodeNext = nodeNext->next;
		currentNode = currentNode->next;
	}
}

ListADT::~ListADT(){

	Node* newHead = head->next;
	while(newHead != nullptr){
		delete head;
		head = newHead;

		newHead = newHead->next;
	}
}

void ListADT::push_back(int val){
	Node* peter = head;

	while(peter->next != nullptr){
		peter = peter -> next;
	}

	peter->next = new Node(val);
	size++;
}

void ListADT::push_front(int val){
	Node* newHead = new Node(val);
	newHead->next = head;
	head = newHead;
}

void ListADT::pop_back(){
	Node* peter = head;

	while(peter->next != nullptr){
		peter = peter->next;
	}

	delete peter;
}

void ListADT::pop_front(){
	Node* peter = head->next;
	delete head;
	head = peter;
}


ListADT& ListADT::operator=(const ListADT& origClass){
	if (this != &origClass) {
		size = origClass.size;

		Node newHead = *origClass.head;

		head = &newHead;

		Node* currentNode = head->next;

		Node* nodeNext = origClass.head->next;

		for (int i = 1; i < size; i++){
			Node newNext = *nodeNext;
			currentNode = &newNext;

			nodeNext = nodeNext->next;
			currentNode = currentNode->next;
		}
	}

	return *this;
}

int& ListADT::operator[](int i){
	int n;
	Node* peter = head;
	for (n = 0; n != i; n++){

		peter = peter->next;
	}
	return peter->next->value;
}

ostream& operator<<(ostream& os, const ListADT& v){
	Node* peter = v.head;

	Node* peterafter;

	if (peter->next != nullptr){
		peterafter = peter->next;
	}

	while(peterafter->next != nullptr){
		os << peter->value + ", ";
		peter = peter->next;
	}
	peter = peter->next;
	os << peter->value;

	return os;
}

int ListADT::length() const{
	return size;
}


