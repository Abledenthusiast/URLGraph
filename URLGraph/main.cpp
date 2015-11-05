#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <cctype>
#include <stdlib.h>


#include "URLGraph.h"

/**
 * @author Aaron Pitman 
 * @version 2015.11.04
 * the main function to search for a target word using breadth first search 
 */

using namespace std;


int main()
{
	string target;
	string input;
	string convert;	
	int levels;

	cout << "What word would you like to search for? " << endl;

	while(target=="") // keep asking for input 
	{
		getline(cin, target);
		if(target=="")
		{
			cout << "You must input a target word." << endl;
			cout << "Type 0 to quit." << endl;

		}
	}
	// quit early. How boring.
	if(target=="0")
	{
		return -1;
	}
	//more prompts
	cout << "Enter the url: " << endl;
	getline(cin, input);
	cout << "How many levels?: " << endl;
	getline(cin, convert);
	//default search level
	levels = 2;
	//if user input a specific number of levels
	if(convert!="")
	{
		// set #levels to input
		levels = stoi(convert);
	}
	//Negative numbers don't work...
	if(levels<=0)
	{
		cout << "wow... \nSetting levels to default of 2" << endl;
		levels = 2;
	}

	URLGraph search;
	string origin = input; //argv[1];
	search.BFS(origin, levels, target);
	/*
		--- this is old test code --- 
	 for(vector<string>::iterator url = neighbors.begin();
            url != neighbors.end(); url++)
	 {
	 	cout << *url << endl;
	 }
	*/

}






	







