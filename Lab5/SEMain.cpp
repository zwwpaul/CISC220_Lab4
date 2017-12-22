/*
 * SEMain.cpp
 *
 *  Created on: Oct 16, 2017
 *      Author: Debra
 */


#include "Document.hpp"
#include <iostream>
#include <stdlib.h>
#include<math.h>
using namespace std;

//void convertToASCII(string letter){
//	int court=0;
//    for (int i = 0; i < letter.length(); i++)
//    {
//        char x = letter[i];
//        court+= int(x);
//        cout << court << endl;
//    }
//}
bool isprime(int n) {
	bool res;
	for (int i = 2; i < sqrt(n) + 1; i++)
	{
		if (n%i == 0)
		{
			return false;
		}
	}
	return true;
}

int func(int num){
	int num2= num*2;
	while(isprime(num2)!=true){
		num2+=1;
	}
	num=num2;
	return num;
}



int main() {
//	Document doc("Monet.txt");

	cout<<int(pow(37,6))%17<<endl;
	return 0;
}
