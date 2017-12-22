/*
 * LLSE.cpp
 *
 *	Wei Zhang, Zhuohao Liu
 *
 *	zwwpaul@udel.edu
 *	liuzh@udel.edu
 *
 *	TA:Ajith Kumar
 *	TA's office hour: 3:00-5:00 pm on Friday
 *
 *  Created on: Nov 1, 201sssss7
 *      Author: zzwww
 */

#include "Node.hpp"
#include "LLSE.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

// For this lab, we used double linked list

//Initialize variables
LLSE::LLSE() {
	size = 0;
	wordcount = 0;
	first = NULL;
	last = NULL;
}

//Destructor
LLSE::~LLSE() {
	cout << "Removed " << endl;
}

//Print the Double Linked List
void LLSE::printLL() {
	Node *temp = first;
	while (temp != NULL) {
		cout << temp->word << ":" << temp->count << ", ";
		temp = temp->next;
	}
	cout << endl;
	cout << "size is now " << size << endl;
	cout << "wordcount is now " << wordcount << endl;
}

//To create the first node in the empty linked list
void LLSE::addFirst(string x) {
	Node *temp = new Node(x);
	temp->word = x;
	first = temp;
	last = temp;
	size += 1;
	wordcount++;
}

//To add a node at the very first place.
void LLSE::addAtFirst(string x) {
	Node *temp = new Node(x);
	temp->word = x;
	first->prev = temp;
	temp->next = first;
	first = temp;
	size += 1;
	wordcount++;
}

//To add a node at the end of the linked list.
void LLSE::push(string x) {
	Node *temp2 = new Node(x);
	last->next = temp2;
	temp2->prev = last;
	last = temp2;
	last->next = NULL;
	wordcount++;
	size += 1;
}

//To find the place where we can insert a new node in.
Node* LLSE::findInsert(string x) {
	Node *temp3 = first;
	while (temp3 != NULL) {
		if (temp3->word != x) {
			if (temp3->word < x) {
				temp3 = temp3->next;
			} else if (temp3->word > x) {
				return temp3;
			}
		} else {
			temp3->count += 1;
			wordcount++;
			return NULL;
		}
	}
	return last;
}

void LLSE::insertUnique(string x) {
	Node *test;
	test = LLSE::findInsert(x);
	if (size == 0) {
		LLSE::addFirst(x);
	} else if (first->word > x) {
		LLSE::addAtFirst(x);
	} else {
		if (test != NULL) {
			if ((test == last) && (x > last->word)) {
				LLSE::push(x);
			} else {
				Node *newnode = new Node(x);
				test->prev->next = newnode;
				newnode->prev = test->prev;
				test->prev = newnode;
				newnode->next = test;
				wordcount += 1;
				size += 1;
			}
		}
	}
}

//To normalize the counts by dividing total wordcount.
void LLSE::normalizeCounts() {
	Node *temp4 = first;
	while (temp4 != NULL) {
		temp4->count = temp4->count / wordcount;
		temp4 = temp4->next;
	}
}

//To remove the very first node in the linked list.
string LLSE::remFirst() {
	Node *temp5 = first;
	temp5 = temp5->next;
	wordcount -= first->count;
	delete first;
	size -= 1;
	first = temp5;
	temp5->prev=NULL;
	return temp5->word;
}

//To remove the last node in the linked list
string LLSE::pop() {
	Node *temp6 = last;
	temp6 = temp6->prev;
	wordcount -= last->count;
	delete last;
	size -= 1;
	last = temp6;
	last->next = NULL;
	return last->word;
}

//To remove the node after Node n.
string LLSE::remNext(Node *n) {
	Node* temp7 = n->next;
	n->next = temp7->next;
	temp7->next->prev = n;
	wordcount -= temp7->count;
	delete temp7;
	size -= 1;
	return temp7->word;
}

//To eliminate un-frequent node with word in linked list.
void LLSE::eliminateLowWords() {
	Node *temp8 = first;
	while (temp8 != NULL) {
		if (temp8->count < 0.004) {
			if (temp8 == first) {
				temp8 = temp8->next;
				LLSE::remFirst();
			} else if (temp8->next == NULL) {
				LLSE::pop();
			} else {
				temp8 = temp8->next;
				LLSE::remNext(temp8->prev->prev);
			}
		} else {
			temp8 = temp8->next;
		}
	}
}

