#include <string>
#include <iostream>
#include <vector>
#include <cctype>
#include <map>

#include "SimpleCurl.h"
#include "grab_urls.h"

using namespace std;

#ifndef URLGRAPH_H
#define URLGRAPH_H

class URLGraph
{
private:
	map<string, string> color;
	map<string, int> distance;
	map<string, string> parent;
	
public:
	URLGraph(){
		
	}


	
void BFS(string &source, int levels)
{
	SimpleCurl httpGrabber;
	string vertex;
	distance[vertex] = 0;
	string neighbor;
	//vertex = source;

	grab_urls getNeighbors;
	vector<string> Q;

	Q.push_back(source);

	while(!(Q.empty()) && (distance[vertex]<levels))
	{
		vertex = Q.front(); // vertex = Q.pop_front
		Q.erase(Q.begin());	// actually Q.front

		if (httpGrabber.getURL(vertex) !=-1)
		{
			vertexPage = httpGrabber.getRetrievedDocument();
		}
	
		vector<string> neighbors = getNeighbors.find_urls(vertexPage);

		for(vector<string>::iterator v = neighbors.begin();
	           v != neighbors.end(); v++)
		{			
			string node;
			node = *v;

			if(color[node] != "black")
			{
					color[node] = "gray";
					parent[node] = vertex;
					distance[node] = distance[vertex] + 1;
					Q.push_back(node);
				cout << *v << endl;
				cout << color[node] << endl;
				cout << distance[node] << endl;				
			}
		}		
		color[vertex] = "black"; // don't visit me anymore! 
	}
}
	
};
#endif