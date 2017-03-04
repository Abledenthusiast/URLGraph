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
int startSearch() {
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
	while(input=="")
	{
		cout << "Enter the url: " << endl;
		getline(cin, input);
		if(input=="")
		{
			cout << "You must input a source url." << endl;
			cout << "Type 0 to quit." << endl;
		}
	}
	if(input=="0")
	{
		return -1;
	}

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
	if(convert=="")
	{
		cout << "setting base level of 2" << endl;
	}
	//Negative numbers don't work...
	if(levels<=0)
	{
		cout << "wow... \nSetting levels to default of 2" << endl;
		levels = 2;
	}

	URLGraph search;
	string origin = input;

	/* clock keeps track of time for process to execute and outputs the time in milliseconds */
	int start_s=clock();
	/* start BFS search */
	search.BFS(origin, levels, target);
	/* stop clock, the process finished */
	int stop_s=clock();
	cout << "process took: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << "ms" << endl;

	return 0;
}

int main()
{
	bool live = true;
	string input = "";
	int mainRet = 0;

	while(true) {
		/* main start to the program */
		mainRet = startSearch();

		/* if user wants to try again or not */
		cout << "Would you like to try again?: " << endl;
		cout << "Type: 'yes' to continue. Type 'no' to stop" << endl;
		getline(cin, input);

		if(input == "no") {
			cout << "thanks for stopping by!" << endl;
			break;
		}
	}
	return mainRet;
}






	







