#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <stdio.h>

using namespace std;


#ifndef Parser_H
#define Parser_H

 /*
Written by Aaron Pitman
Date: 10.5.2015
*/
class Parser 
{
    private:
       
        vector<string> reader;      
    public:

    Parser(); 
    /*
    * take an input string and check if a target word is in the string
    * returns true if the target is found
    */
    bool searchTarget(string html, string target);
     // take each word and make it lower case
    string toLowerCase(string inputString);

};
#endif
