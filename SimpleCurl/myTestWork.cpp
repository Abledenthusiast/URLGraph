#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <cctype>
#include <stdlib.h>

#include "SimpleCurl.h"
#include "grab_urls.h"
#include "URLGraph.h"

using namespace std;

int main(int argc, char *argv[])
{
	char *convert = argv[2];
	int levels = atoi (convert);

	//init the graph
	map<string, vector<string> > graph;
	vector<string> neighbors; 
	grab_urls grabURLs;

	SimpleCurl httpGrabber(argv[1]);
	string doc = httpGrabber.getRetrievedDocument();	

	if (httpGrabber.getURL(argv[1]) !=-1)
	{
        	httpGrabber.getRetrievedDocument();
        	neighbors = grabURLs.find_urls(doc);
        	
        }
	else
		cout << "Could not retrieve document" << endl;
		
	URLGraph search;
	string origin = argv[1];
	search.BFS(origin, levels);
	/*
	 for(vector<string>::iterator url = neighbors.begin();
            url != neighbors.end(); url++)
	 {
	 	cout << *url << endl;
	 }
	*/

}






	







