#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <cctype>
#include <stdlib.h>

#include "URLGraph.h"

using namespace std;

int main()//int argc, char *argv[])
{
	string target;
	string input;
	string convert;	
	int levels;

	cout << "What word would you like to search for? " << endl;
	while(target=="")
	{
		getline(cin, target);
		if(target=="")
		{
			cout << "You must input a target word." << endl;
			cout << "Type 0 to quit." << endl;

		}
	}

	if(target=="0")
	{
		return -1;
	}
	//cout << "> " << end;
	cout << "Enter the url: " << endl;
	getline(cin, input);
	cout << "How many levels?: " << endl;
	getline(cin, convert);
	//default search level
	levels = 2;
	if(convert!="")
	{
		// set #levels to input
		levels = stoi(convert);
	}
	if(levels<=0)
	{
		cout << "wow... \nSetting levels to default of 2" << endl;
		levels = 2;
	}

	URLGraph search;
	string origin = input; //argv[1];
	search.BFS(origin, levels, target);
	/*
	 for(vector<string>::iterator url = neighbors.begin();
            url != neighbors.end(); url++)
	 {
	 	cout << *url << endl;
	 }
	*/

}






	







