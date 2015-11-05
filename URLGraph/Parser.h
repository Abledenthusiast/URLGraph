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
       
        vector<string> reader;         // source of command input
    public:
    /**
     * Create a parser to read from the terminal window.
     */
    Parser(); 
    /**
     * @return The next command from the user.
     */


    /**
     * Print out a list of valid command words.
     */


    vector<string> getStrings(string html, string target);

    string toLowerCase(string inputString);

};
#endif
