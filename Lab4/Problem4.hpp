/*
 * Problem4.hpp
 *
 * Created on: Oct 10, 2017
 *      Author: ZWW
 *
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

#ifndef PROBLEM4_HPP_
#define PROBLEM4_HPP_
#include<iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <list>
#include <time.h>
#include<stack>
#include<locale>

using namespace std;

//In this .hpp file, We created two classes.
//The first class named "hex1" is for question 2 to 4.
//The second class named "matx" is for question 5 to 7.
//By the way, the function of question 1 is in the corresponding.cpp file.

class hex1 {
	int hex_int;

	string hex_str;

	int loop;

public:

	int hex_to_int(string x); //This constructor is for Question 2

	string int_to_hex(int x); //This constructor is for Question 3

	~hex1(); //Destructor, to release the memory

	//Here are my getters and setters

	int getHexInt() const {
		return hex_int;
	}

	void setHexInt(int hexInt) {
		hex_int = hexInt;
	}

	const string& getHexStr() const {
		return hex_str;
	}

	void setHexStr(const string& hexStr) {
		hex_str = hexStr;
	}

	int getLoop() const {
		return loop;
	}

	void setLoop(int loop) {
		this->loop = loop;
	}
};


class matx{

	int length;

	int width;

	int **mat;

	string **matrx; //This parameter is for Question 5.2c

public:

	int **create_mat();

	void print_mat(); //This constructor is for Question 5.2b

	void fivex();	//This constructor is for Question 5.2c

	void print_matrx(); //This constructor is for Question 5.2d

	~matx();  //Destructor, to release the memory

	//Here are my getters and setters

	int getLength() const {
		return length;
	}

	void setLength(int length) {
		this->length = length;
	}

	int** getMat() const {
		return mat;
	}

	void setMat(int** mat) {
		this->mat = mat;
	}

	int getWidth() const {
		return width;
	}

	void setWidth(int width) {
		this->width = width;
	}

};



#endif /* PROBLEM4_HPP_ */
