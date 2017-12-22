/*
 * Node.cpp
 *
 *  Created on: Oct 16, 2017
 *      Author: Debra
 */

#include "Node.hpp"
#include <iostream>
#include <string>
using namespace std;

Node::Node(string s) {
	count = 1;
	next = NULL;
	prev = NULL;
	word = s;
}
Node::~Node() {
	if (next != NULL) {
		cout << "Warning: Next not null: Memory leak?" << endl;
	}
	if (prev != NULL) {
		cout << "Prev not null: Memory leak?" << endl;
	}
}
