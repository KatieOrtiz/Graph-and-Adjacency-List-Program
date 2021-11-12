//Katie Ortiz - Homework #4 - CS 236 - 4/11/2021
#ifndef _GraphHeader_H_
#define _GraphHeader_H_

#include <list>
#include <vector>
#include <queue>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

//unweightedDigraph Class
template <typename DataType>
class unweightedDigraphClass{
private:
	//Member variables
	class vertexofAdjList { //vertexofAdjList Class
	public:
		DataType adjListData;
		list<int> adjacencyList;
	};
	vector<vertexofAdjList> vectorofAdjList;

public:
	//Constructor
	unweightedDigraphClass(){};

	//Member function declarations
	DataType adjacencyListData(int data) const;
	vector<int> findShortestPath(int startCity, int destinationCity);
	void fileInput(ifstream& inputFile);
	void displayAdjList(ostream& displayOutput);
	void DFS(int startLocation, vector<bool> & unvisitedNodes);

};

#endif _GraphHeader_H_