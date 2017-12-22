/*
 * corresponding.cpp
 *
 *  Created on: Oct 10, 2017
 *      Author: ZWW
 * Wei Zhang, Zhuohao Liu
 *
 * zwwpaul@udel.edu
 * liuzh@udel.edu
 *
 * TA: Ajith Kumar
 * TA's office hour: 3:00-5:00 on Friday
 *
 * 10/10/17
 */
#include "Problem4.hpp"
#include<iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <list>
#include <time.h>
#include<stack>
#include<locale>

using namespace std;

//Since the question 1 is not in class, I put this function here.

string problem1(string &str1, int &length);

int main() {
	srand(time(NULL)); //Only do it once.
	cout << "************This part contains Question 1,2,3,4 ***********************" << endl;
	cout << "************Problem1***********************" << endl;
	//
	string str1 = "Cat";
	string str2 = "Cover";
	string str3 = "Balsamic";
	int len1 = 3;
	int len2 = 5;
	int len3 = 8;
	cout << problem1(str1, len1) << endl;  //Expects to get "cithagat, 8"
	cout << problem1(str2, len2) << endl; //Expects to get "cithagovithager, 15"
	cout << problem1(str3, len3) << endl << endl; //Expects to get "bithagalsithagamithagic, 23"

	cout << "************Problem2***********************" << endl;

	//There are 3 test cases in 3 different objects
	hex1* h1 = new hex1();
	h1->setLoop(0);
	h1->setHexInt(123123);
	cout << h1->int_to_hex(h1->getHexInt()) << endl; //Expects to get 1E0F3

	hex1* h2 = new hex1();
	h2->setLoop(0);
	h2->setHexInt(590);
	cout << h2->int_to_hex(h2->getHexInt()) << endl; //Expects to get 24E

	hex1* h3 = new hex1();
	h3->setLoop(0);
	h3->setHexInt(796982364);
	cout << h3->int_to_hex(h3->getHexInt()) << endl << endl; //Expects to get 2F80FC5C

	cout << "************Problem3***********************" << endl;

	//There are 3 test cases in 3 different objects
	hex1* h4 = new hex1();
	h4->setLoop(0);
	h4->setHexStr("6A4C");
	cout << h4->hex_to_int(h4->getHexStr()) << endl; //Expects to get 27212

	hex1* h5 = new hex1();
	h5->setLoop(0);
	h5->setHexStr("A871CB");
	cout << h5->hex_to_int(h5->getHexStr()) << endl; //Expects to get 11039179

	hex1* h6 = new hex1();
	h6->setLoop(0);
	h6->setHexStr("6EFFA8");
	cout << h6->hex_to_int(h6->getHexStr()) << endl << endl; //Expects to get 7274408

	cout << "************This part includes all questions 5, 6, 7***********************"<< endl;

	//There are 3 test cases in 3 different objects
	matx* m1 = new matx();
	cout << m1->create_mat() << endl;  //Expects to create a matrix in int type,which is filled with 0.
									  //And return the address of this matrix.
	m1->print_mat(); //Expects to print out each element in the matrix in int type.
	cout << endl;
	m1->fivex();  //Expects to randomly assign 5 "x"s in the string matrix
	m1->print_matrx();  //Expects to print out a matrix in string type and there are 5 "x" randomly assigned.
	cout << endl;

	matx* m2 = new matx();
	cout << m2->create_mat() << endl; //Expects to create a matrix in int type,which is filled with 0.
									 //And return the address of this matrix.
	m2->print_mat();  //Expects to print out each element in the matrix in int type.
	cout << endl;
	m2->fivex();  //Expects to randomly assign 5 "x"s in the string matrix
	m2->print_matrx();  //Expects to print out a matrix in string type and there are 5 "x" randomly assigned.
	cout << endl;

	matx* m3 = new matx();
	cout << m3->create_mat() << endl;  //Expects to create a matrix in int type,which is filled with 0.
									  //And return the address of this matrix.
	m3->print_mat();   //Expects to print out each element in the matrix in int type.
	cout << endl;
	m3->fivex();   //Expects to randomly assign 5 "x"s in the string matrix
	m3->print_matrx();   //Expects to print out a matrix in string type and there are 5 "x" randomly assigned.

	cout << endl;

	return (0);
}

string problem1(string &str1, int &length) {
	string copy;
	string fix_str = "ithag";
	int len = 0;
	// Search for the all uppercase letter, and convert all of them to lowercase.
	for (int j = 0; j < length; j++) {
		if (isupper(str1[j])) {
			str1[j] = str1[j] + 32;
		}
	}
	for (int i = 0; i < length; i++) {
		string str2 = string(1, str1[i]);
		if ((str2.compare("a") == 0) || (str2.compare("e") == 0)
				|| (str2.compare("i") == 0) || (str2.compare("o") == 0)
				|| (str2.compare("u") == 0) || (str2.compare("y") == 0)) {
			copy = copy + fix_str + str2;
			len += 6;

		} else {
			copy += str2;
			len += 1;
		}
	}
	length = len;
	return copy + ", " + to_string(len);
}

