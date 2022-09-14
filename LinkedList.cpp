#include "LinkedList.h"
#include <iostream>
using namespace std;
template <typename T>
LinkedList<T>::LinkedList() {
	head = nullptr;
	tail = nullptr;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList& obj) {
	head = obj.head;
	tail = obj.tail;
}

template <typename T>
void LinkedList<T>::insertAtHead(T value) {
	node<T>* newNode;
	newNode = new node<T>(value);
	if (head == nullptr) {
		head = tail = newNode;
		// free memory of tmeporary pointer
		newNode = nullptr;
		delete newNode;
	}
	else {
		newNode->next = head;
		head = newNode;
		// free memory of tmeporary pointer
		newNode = nullptr;
		delete newNode;
	}
}

template <typename T>
void LinkedList<T>::insertAtTail(T value) {
	node<T>* newNode;
	newNode = new node<T>(value);
	if (head == nullptr) {
		head = tail = newNode;
		// free memory of tmeporary pointer
		newNode = nullptr;
		delete newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
		// free memory of tmeporary pointer
		newNode = nullptr;
		delete newNode;
	}
}

template <typename T>
bool LinkedList<T>::deleteAtHead() {
	if (head != nullptr) {
		if (head->next == tail) {
			head = nullptr;
			delete head;
			head = tail;
			return true;
		}
		else if (head == tail) {
			head = tail = nullptr;
			return true;
		}
		else {
			node<T>* temp = head->next;
			delete head;
			head = temp;
			// free memory of tmeporary pointer
			temp = nullptr;
			delete temp;
			return true;
		}
	}
	return false;
}

template <typename T>
bool LinkedList<T>::deleteAtTail() {
	if (head != nullptr) {
		node<T>* temp = head;
		while (temp != nullptr) {
			if (temp->next == tail) {
				tail = nullptr;
				delete tail;
				temp->next = nullptr;
				tail = temp;
				// free memory of tmeporary pointers
				temp = nullptr;
				delete temp;
				return true;
			}
			temp = temp->next;
		}
	}
	else {
		head = tail = nullptr;
		return true;
	}
	return false;
}

//This function returns pointer to nth node in the list.Returns last node if n is greater than the number of nodes present in the list.
template <typename T>
node<T>* LinkedList<T>::getNode(int n) {
	if (n >= 0) {
		node<T>* temp = head;
		int count = 0;
		while (temp->next != nullptr) {
			if (count == n) {
				return temp;
			}
			count++;
			temp = temp->next;
		}
		return tail;
	}
	else
		return nullptr;
}

//Inserts a node after some node whose info equals input parameter keyand returns true if node is successfully inserted, false otherwise.
template <typename T>
bool LinkedList<T>::insertAfter(T value, T key) {
	if (key == tail->info) {
		insertAtTail(value);
		return true;
	}
	else {
		node<T>* newNode = new node<int>(value);
		node<T>* temp = head;
		while (temp != nullptr) {
			if (temp->info == key) {
				newNode->next = temp->next;
				temp->next = newNode;
				// free memory of tmeporary pointers
				newNode = temp = nullptr;
				delete temp, newNode;
				return true;
			}
			temp = temp->next;
		}
		// free memory of tmeporary pointers for not going to if condition structure
		newNode = temp = nullptr;
		delete temp, newNode;
		return false;
	}
}

//Inserts a node before some node whose info equals input parameter key and returns true if node is successfully inserted, false otherwise.
template <typename T>
bool LinkedList<T>::insertBefore(T value, T key) {
	if (key == head->info) {
		insertAtHead(value);
		return true;
	}
	else {
		node<T>* newNode = new node<int>(value);
		node<T>* temp = head;
		while (temp != nullptr) {
			if (temp->next->info == key) {
				newNode->next = temp->next;
				temp->next = newNode;
				// free memory of tmeporary pointers
				newNode = temp = nullptr;
				delete temp, newNode;
				return true;
			}
			temp = temp->next;
		}
		// free memory of tmeporary pointers for not going into if condition structure
		newNode = temp = nullptr;
		delete temp, newNode;
		return false;
	}
}

//Deletes a node that is before some node whose info equals input parameter keyand returns true if node is successfully inserted, false otherwise.
template <typename T>
bool LinkedList<T>::deleteBefore(T key) {
	if (head->next->info == key) {
		deleteAtHead();
		return true;
	}
	else {
		node<T>* temp = head;
		while (temp->next->next != nullptr) {
			if (temp->next->next->info == key) {
				node<T>* nod = temp->next->next;
				temp->next = nullptr;
				delete temp->next;
				temp->next = nod;
				// free memory of tmeporary nod poniter for refrencing to next pointer
				nod = nullptr;
				delete nod;
				// free memory of tmeporary pointer
				temp = nullptr;
				delete temp;
				return true;
			}
			temp = temp->next;
		}
	}
	return false;
}

//Deletes a node that is after some node whose info equals input parameter keyand returns true if node is successfully inserted, false otherwise.
template <typename T>
bool LinkedList<T>::deleteAfter(T key) {
	node<T>* temp = head;
	while (temp != nullptr) {
		if (temp->info == key) {
			if (temp->next == tail) {
				deleteAtTail();
				// free memory of tmeporary pointer
				temp = nullptr;
				delete temp;
				return true;
			}
			else {
				node<T>* nod = temp->next->next;
				temp->next = nullptr;
				delete temp->next;
				temp->next = nod;
				temp = nullptr;
				delete temp;
				return true;
			}
		}
		temp = temp->next;
	}
	// free memory of tmeporary pointer
	temp = nullptr;
	delete temp;
	return false;
}

//returns the total number of nodes in the list.
template <typename T>
int LinkedList<T>::getLength() {
	int count = 0;
	if (head != nullptr) {
		node<T>* temp = head;
		while (temp != nullptr) {
			count++;
			temp = temp->next;
		}
		// free memory of tmeporary pointer
		temp = nullptr;
		delete temp;
		return count;
	}
	else
		return 0;
}

//	Search a node with value “x” from list and return its link.If multiple nodes of same value exist, then return pointer to first node having the value “x”.
template <typename T>
node<T>* LinkedList<T>::search(T x) {
	if (x == head->info) {
		return head;
	}
	else if (x == tail->info) {
		return tail;
	}
	else {
		node<T>* temp = head->next;
		while (temp != tail) {
			if (x == temp->info) {
				return temp;
			}
			temp = temp->next;
		}
		// free memory of tmeporary pointer
		temp = nullptr;
		delete temp;
		return nullptr;
	}
}

template <typename T>
void LinkedList<T>::printList() {
	if (head != nullptr) {
		node<T>* temp = head;
		while (temp != nullptr) {
			cout << temp->info << " ";
			temp = temp->next;
		}
		cout << endl;
		// free memory of tmeporary pointer
		temp = nullptr;
		delete temp;
	}
	else
		cout << "List is empty" << endl;
}

template <typename T>
LinkedList<T>::~LinkedList() {
	head = tail = nullptr;
	delete head, tail;
}