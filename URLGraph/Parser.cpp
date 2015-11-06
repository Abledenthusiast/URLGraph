
#include <iostream>
#include <string>

#include <vector>


#include "Parser.h"

/**
 * @author Aaron Pitman 
 * @version 2015.11.05
 */

using namespace std;

    /**
     * Create a parser to read from the terminal window.
     */
    Parser::Parser() 
    {}

    /*
    * take an input string and check if a target word is in the string
    * returns true if the target is found
    */
    bool Parser::searchTarget(string html,string target) 
    {
        string inputLine;                //reader.nextLine().trim().toLowerCase();
        inputLine = toLowerCase(html); // transform the words to all lowercase
        
        bool found = false;

        vector<string> words;
        int location = inputLine.find_first_of(" ><");
        while(location != string::npos)
        {
            string word = inputLine.substr(0,location);
            if(word == target)
            {
                found = true;
                return found;

            }
            inputLine = inputLine.substr(location+1);
            location = inputLine.find_first_of(" ><");
        }
        
        
        return found;
    }

   
    // take each word and make it lower case
     string Parser::toLowerCase(string inputString)
    {
        string result;
        result = "";
        for(int i = 0; i <inputString.length(); i++)
        {
            result = result + 
                char(tolower(inputString[i]));
        }
       
        return result;
    }


