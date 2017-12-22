/*
 * Document.cpp
 *
 *  Created on: Oct 16, 2017
 *      Author: Debra
 */


#include "Document.hpp"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

Document::Document(string f) {
	filename = f;
	wordlist = new LLSE();
	readFile();
	cout << "PRINTING BEFORE NORMALIZED " << endl;
	wordlist->printLL();
	wordlist->normalizeCounts();
	cout << endl << endl << "PRINTING AFTER NORMALIZED " << endl;
	wordlist->printLL();
	wordlist->eliminateLowWords();
	cout << endl << endl << "PRINTING AFTER ELIMINATION" << endl;
	wordlist->printLL();

}
string Document::strip(string w){
	int x = strlen(w.c_str());
	string neww="";
	//cout << w << ":" << x << endl;
	char punct[] = {'!', '.', ',',':', ';','\'','"','(',')'};
	for (int i = 0; i < x; i++) {
		bool flag = false;
		for (int j = 0; j < 9; j++) {
			if (w[i] == punct[j]) {
				flag = true;
				j = 9;
			}
		}
		if (!flag) {
			neww += tolower(w[i]);
		}
	}
	return neww;
}
bool Document::checkFunctionWords(string w) {
	int i = 0;
	while (i< fwlen && w != fw[i] ) {
		i++;
	}
	if (i != fwlen) {
		return true;
	}
	return false;
}

void Document::readFile() {
	cout << filename << endl;
	ifstream infile(filename.c_str(),ios::in);     // open file
	if (!infile.is_open()) {
		return;
	}
	string word;
	while (infile>>word) {          // loop getting single words
		word = strip(word);			// strips punctuation
		if (!checkFunctionWords(word)) {  // doesn't insert function words
			//cout << word << " is valid " << endl;
			wordlist->insertUnique(word);
//			wordlist->printLL(); //To test what you just inserted.
		}
//		else {
//			cout << word << " removed" << endl;
//		}
	}
	wordlist->printLL();

}


