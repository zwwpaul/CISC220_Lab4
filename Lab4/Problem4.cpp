/*
 * Problem4.cpp
 *
 *  Created on: Oct 10, 2017
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

#include<iostream>
#include "Problem4.hpp"
#include <stdlib.h>
#include <math.h>
#include <string>
#include <list>
#include <time.h>
#include<stack>
#include<locale>

using namespace std;
int problem2_helper(char *arr, int n, char key) {
	//This helper function is to find the positions of particular elements in hex_index.
	//Because it is just a helper function, I didn't put them in the class.
	int index = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == key) {
			index = i;
			break;
		}
	}
	return index;
}

int hex1::hex_to_int(string x){
	hex_str=x;
	int length = hex_str.length();
	if (loop < length) {
			int power = pow(16, length - loop - 1);
			char hex_index[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
			hex_int = hex_int + problem2_helper(hex_index, 16, hex_str[loop]) * power;
			loop+=1;
			return hex_to_int(hex_str);
		} else {
			return hex_int;
		}
	}

string hex1::int_to_hex(int num){
	hex_int=num;
	if(hex_int>0){
		string hex_index[16] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F" };
		int index = hex_int %16;
		hex_str += hex_index[index];
		hex_int = hex_int / 16;
		return int_to_hex(hex_int);
	}else{
		reverse(hex_str.begin(),hex_str.end()); //Reverse the all string.
		return hex_str;
	}
}



//This function is to create a matrix with int type
int ** matx::create_mat() {
	length=3+rand()%7;
	width=3+rand()%7;
	int **tmp;
	tmp = new int *[length];
	for (int i = 0; i < length; i++) {
		tmp[i] = new int[width];
		for (int j=0;j<width;j++){
			tmp[i][j]=0;
		}
	}
	mat=tmp;
	return mat;
}

void matx::print_mat(){
	for(int i=0;i<length;i++){
		for(int j=0;j<width;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}

//It is a helper function to create a new matrix with string type
//Because it is just a helper function, I didn't put them in the class.
string ** create_matrx(int length, int width) {
	string **tmp;
	tmp = new string *[length];
	for (int i = 0; i < length; i++) {
		tmp[i] = new string [width];
		for (int j=0;j<width;j++){
			tmp[i][j]="0";
		}
	}
	return tmp;
}


void matx::fivex() {
	//We used the helper function above to create a new matrix with string type
	matrx=create_matrx(length, width);
	int count = 0;
	//Change the elements in original matrix with int type to strings.
	//And replace them into the new string matrix.
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			matrx[i][j] = to_string(mat[i][j]);
		}
	}
	while (count < 5) {
		int position1 = random() % length;
		int position2 = random() % width;
		if (matrx[position1][position2] == "x") {
			continue;
		} else {
			matrx[position1][position2] = "x";
			count += 1;
		}
	}
}
//This function is to print out the matrix which contains 5 "x"s.
void matx::print_matrx(){
	for(int i=0;i<length;i++){
		for(int j=0;j<width;j++){
			cout<<matrx[i][j]<<" ";
		}
		cout<<endl;
	}
}

