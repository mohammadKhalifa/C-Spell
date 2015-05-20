
#ifndef _LEXICON_H
#define _LEXICON_H

#include <string>
#include <iostream>
#include <fstream>
#include <set>
using namespace std;
class Lexicon {
public:
    /* Initialize Lexicon with a dicionary file */
	Lexicon (const string &dictFileName);

    /* returns true if word exists in dictionary */
	bool contains(const string& word);

    /* returns true if dicionary is empty */
	bool isEmpty();

    /* adds the string word to dicionary */
	void addWord(const string& word);

    /* returns a set<string> of all
     * words in dictionary */
	const set<string> & getWords();
private:
	set<string> words;
	string toLower(string str);

};






#endif
