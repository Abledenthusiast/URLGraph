#include <string>
#include <iostream>
#include <vector>
#include <cctype>
#include <map>


using namespace std;

#ifndef URLGRAPH_H
#define URLGRAPH_H

class URLGraph
{
private:
	map<string, string> color;
	map<string, int> distance;
	map<string, string> parent;
	int numOfExam;
	
public:
	URLGraph();

	void BFS(string &source, int levels, string targetWord);

};
#endif