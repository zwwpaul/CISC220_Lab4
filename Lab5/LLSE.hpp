/*
 * LLSE.hpp
 *
 *  Created on: Oct 16, 2017
 *      Author: Debra
 */

#ifndef LLSE_HPP_
#define LLSE_HPP_


#include "Node.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class LLSE {
	friend class Document;
	Node *first;
	Node *last;
	int size;
	int wordcount;

public:
	LLSE();
	~LLSE();
	void printLL();
	void addFirst(string x);
	void addAtFirst(string x);
	void push(string x);
	Node *findInsert(string x);
	void insertUnique(string x);
	void normalizeCounts();
	string remFirst();
	string pop();
	string remNext(Node *n);
	void eliminateLowWords();
};



#endif /* LLSE_HPP_ */
