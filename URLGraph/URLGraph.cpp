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
		
		// grab the page the vertex refers to
		while(httpGrabber.getURL(vertex) ==-1)
		{
			//while loop ignores bad links and moves onto the next node
			vertex = Q.front(); 
			Q.erase(Q.begin());
		}
		vertexPage = httpGrabber.getRetrievedDocument();

		//find all of the neighbors
		vector<string> neighbors = getNeighbors.find_urls(vertexPage);

		/* search for target word on page */	
		found = wordSearch.searchTarget(vertexPage, targetWord);
	
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
			}
		}

		color[vertex] = "black"; //u.color = black
	}

	// give some space
	cout << " " << endl;

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
			cout << "Target was found " << endl;
			cout <<"Path: " << path << endl;
			
		}
	}
	else
	{
		cout << "Not found. Number of examined pages: " << numOfExam << 
			" Number of levels: " << levels << endl;
	}
		
}

void URLGraph::DFS(string &source, int levels, string targetWord) {
	
}
