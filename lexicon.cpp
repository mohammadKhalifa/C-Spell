#include "lexicon.h"
#include <iostream>
#include <fstream>
using namespace std;



Lexicon::Lexicon(const string &dictFileName) {
	ifstream inFile(dictFileName);
	if (!inFile) {
		cerr <<"Error opening file!"<<endl;
	}

	string cur;
	while (inFile >> cur)
	{
		addWord(cur);
	}
	inFile.close();
}

void Lexicon::addWord(const string& word) {
	words.insert(toLower(word));
}

bool Lexicon::contains(const string& word) {

	return words.find(toLower(word)) != words.end();
}

bool Lexicon::isEmpty() {
	return words.empty();
}

string Lexicon::toLower(string str)
{
	string ret = str;
	for(int i=0;i<ret.length();i++)
		ret[i] = tolower(ret[i]);

	return ret;
}