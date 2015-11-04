#include <string>
#include <iostream>
#include <vector>
#include <cctype>
#include <map>

#include "URLGraph.h"
#include "SimpleCurl.h"
#include "grab_urls.h"
#include "Parser.h"

/**
 * @author Aaron Pitman 
 * @version 2015.11.04
 */

using namespace std;

	URLGraph::URLGraph(){}
	
void URLGraph::BFS(string &source, int levels, string targetWord)
{
	/*
	*	create objects to grab nodes and find words within them	
	*/
	SimpleCurl httpGrabber;
	string vertex;

	string vertexPage;
	Parser wordSearch;

	bool found = false;

	parent[source] = "";

	numOfExam = 0;

	string neighbor;

	grab_urls getNeighbors;
	vector<string> Q;

	Q.push_back(source);

	while(!(Q.empty()) && (distance[vertex]<levels) && !(found))
	{
		vertex = Q.front(); // vertex = Q.pop_front
		Q.erase(Q.begin());	// actually delete Q.front
		
		

		if (httpGrabber.getURL(vertex) !=-1)
		{
			vertexPage = httpGrabber.getRetrievedDocument();
		}

		vector<string> neighbors = getNeighbors.find_urls(vertexPage);

		// search for target word on page
		vector<string> possibleTargets = wordSearch.getStrings(vertexPage);

		//test to see if code is stopping after finding the target word on a page.
		//cout << vertex << endl;
		std::vector<string>::iterator it;
		it = find(possibleTargets.begin(), possibleTargets.end(), targetWord);
			if(it != possibleTargets.end())
			{
				//stop the while loop
				found = true;
			}

		//----------
		for(vector<string>::iterator v = neighbors.begin();
	           v != neighbors.end(); v++)
		{			
			string node;
			node = *v;

			if(color.find(node)==color.end()) // if(u.color == white)
			{
				numOfExam = numOfExam + 1;
				color[node] = "gray";
				parent[node] = vertex;
				distance[node] = distance[vertex] + 1;

				Q.push_back(node);
				// test code
				//cout << node << endl;
				//cout << color[node] << endl;
				//cout << distance[node] << endl;				
			}
		}

		color[vertex] = "black"; // don't visit me anymore! u.color = black
	}
	/*
	*	This part prints out the path, if the word was found
	*/
	if(found)
	{

		string next;
		string path;
		next = parent[vertex];
		path = vertex;
		//no parent means target was found on source page
		if(next=="")
		{
			cout << "Target was found on source page. " << endl;
		}
		else
		{
			
			while(next!="")
			{
				path = next + " -> " + path;
				next = parent[next];
			}
			cout <<"Path: " << path << endl;
			cout <<"TEST TEST TEST "<< endl;
		}
	}
	else
	{
		cout << "Not found. " << numOfExam << levels << endl;
	}
		
}