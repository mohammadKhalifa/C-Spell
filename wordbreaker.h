/* File : wordbreaker.h
 * Interface for wordbreaker class 
 * a class to cut a text into words 
 */

#ifndef wordbreaker_h
#define wordbreaker_h

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class WordBreaker{

public:
	WordBreaker();
	WordBreaker(const string& str );
	WordBreaker(ifstream &infile);

	void setinput(const string& str);
	void setinput(ifstream &infile);
	int getPosition();
	bool hasMoreWords();
	string nextWord();


private:
	string buffer;
	int cp;



};







#endif