#pragma once
#include <iostream>
using namespace std;
template <typename T>
class node {
public:
	T info;
	node<T>* next;
	node() {
		info = NULL;
		next = nullptr;
	}
	node(T val) {
		info = val;
		next = nullptr;
	}
};

template <typename T>
class LinkedList {
	node<T>* head;
	node<T>* tail;
public:
	LinkedList();
	LinkedList(const LinkedList& obj);
	void insertAtHead(T value);
	void insertAtTail(T value);
	bool deleteAtHead(); 
	bool deleteAtTail();

	//This function returns pointer to nth node in the list.Returns last node if n is greater than the number of nodes present in the list.
	node<T>* getNode(int n);

	//Inserts a node after some node whose info equals input parameter keyand returns true if node is successfully inserted, false otherwise.
	bool insertAfter(T value, T key);

	//Inserts a node before some node whose info equals input parameter key and returns true if node is successfully inserted, false otherwise.
	bool insertBefore(T value, T key);

	//Deletes a node that is before some node whose info equals input parameter keyand returns true if node is successfully inserted, false otherwise.
	bool deleteBefore(T key);

	//Deletes a node that is after some node whose info equals input parameter keyand returns true if node is successfully inserted, false otherwise.
	bool deleteAfter(T key);

	//returns the total number of nodes in the list.
	int getLength(); 

	//	Search a node with value “x” from list and return its link.If multiple nodes of same value exist, then return pointer to first node having the value “x”.
	node<T>* search(T x); 

	void printList(); 

	~LinkedList();
};