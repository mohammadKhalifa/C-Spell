
#ifndef _LEXICON_H
#define _LEXICON_H

#include <string>
#include <iostream>
#include <fstream>
#include <set>
using namespace std;
class Lexicon {
public:
	Lexicon (const string &dictFileName);
	bool contains(const string& word);
	bool isEmpty();
	void addWord(const string& word);

private:
	set<string> words;
	string toLower(string str);

};






#endif
