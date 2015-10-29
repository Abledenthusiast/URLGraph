#include <string>
#include <iostream>
#include <vector>
#include <cctype>
#include <map>



using namespace std;

class Node
{
private: 
	string data;
	bool visited;
	vector<Node> neighbors;
	
public:
	Node(string contents){
		data = contents;
	}
	void addNeighbors(Node node)
	{
		neighbors.push_back(node);
	}


	
};