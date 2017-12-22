/*
 * Node.hpp
 *
 *  Created on: Oct 16, 2017
 *      Author: Debra
 */

#ifndef NODE_HPP_
#define NODE_HPP_

#include <iostream>
#include <string>
using namespace std;

class Node {
	friend class Document;
	friend class LLSE;
	Node *next;
	Node *prev;
	float count;
	string word;
public:
	Node(string w);
	~Node();
};



#endif /* NODE_HPP_ */
