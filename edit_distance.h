
/* File:edit_distance.h
 * this file is the interfce for the EditDistance class
 * A class that implements the edit distance algorithm */


#ifndef edit_distance_h
#define edit_distance_h

#include <string>
#include <iostream>
using namespace std;

class EditDistance {

public:
    int getEditDistance (const string &,const string &);
};





#endif
