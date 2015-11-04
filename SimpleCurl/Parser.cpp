
#include <iostream>
#include <string>
#include <vector>



#include "Parser.h"

/**
 * @author  Michael Kölling and David J. Barnes
 * @author Aaron Pitman 
 * @version 2011.08.08
 * @version 2015.10.03
 */

using namespace std;
    /**
     * Create a parser to read from the terminal window.
     */
    Parser::Parser() 
    {
       // commands = CommandWords();
       // reader = getInput();
    }

    /**
     * @return The next command from the user.
     */

    //Get the input and return each individual word inside of a vector
    vector<string> Parser::getStrings(string html) 
    {
        string inputLine;                //reader.nextLine().trim().toLowerCase();
        inputLine = html;
        inputLine = toLowerCase(inputLine); // transform the words to all lowercase
        

        vector<string> words;
        int location = inputLine.find_first_of(" ");
            //take each word input and put them into a vector (basically split)
        while(location != string::npos)
        {
            string word = inputLine.substr(0,location);
            if(word != "")
            {
                words.push_back(word);
            }
            inputLine = inputLine.substr(location+1);
            location = inputLine.find_first_of(" ");
        }
        words.push_back(inputLine);
        
        return words;
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


