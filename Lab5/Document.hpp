/*
 * Document.hpp
 *
 *  Created on: Oct 16, 2017
 *      Author: Debra
 */

#ifndef DOCUMENT_HPP_
#define DOCUMENT_HPP_

#include "Node.hpp"
#include "LLSE.hpp"
#include <string>

class Document {
	string filename;
	LLSE *wordlist;
	string fw[82]={	"a",
					"all",
					"almost",
					"along",
					"also",
					"although",
					"am",
					"among",
					"an",
					"and",
					"are",
					"away",
					"as",
					"at",
					"be",
					"been",
					"became",
					"because",
					"between",
					"but",
					"by",
					"came",
					"can",
					"do",
					"dont",
					"during",
					"either",
					"even",
					"for",
					"from",
					"got",
					"had",
					"has",
					"have",
					"havent",
					"he",
					"him",
					"himself",
					"his",
					"i",
					"in",
					"is",
					"isnt",
					"it",
					"last",
					"made",
					"many",
					"more",
					"much",
					"neither",
					"never",
					"no",
					"none",
					"nor",
					"not",
					"of",
					"on",
					"one",
					"or",
					"other",
					"so",
					"some",
					"that",
					"the",
					"there",
					"these",
					"they",
					"this",
					"though",
					"to",
					"until",
					"very",
					"was",
					"were",
					"when",
					"where",
					"which",
					"while",
					"why",
					"with",
					"without",
					"you"
	};
	int fwlen = 82;
public:
	Document(string f);
	string strip(string w);
	bool checkFunctionWords(string w);
	void readFile();
};



#endif /* DOCUMENT_HPP_ */
