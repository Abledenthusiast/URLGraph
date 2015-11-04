#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef Parser_H
#define Parser_H

/**
 * @author  Michael Kölling and David J. Barnes
 * @version 2011.08.08
 */
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


    vector<string> getStrings(string html);

    string toLowerCase(string inputString);

};
#endif
