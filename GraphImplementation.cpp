//Katie Ortiz - Homework #4 - CS 236 - 4/11/2021
#include "GraphHeader.h"


//Implementation of fileInput function
template <typename DataType>
void unweightedDigraphClass<DataType>::fileInput(ifstream& inputFile){

	vertexofAdjList adjListVertex;  
	int in, vertex;      

	vectorofAdjList.push_back(adjListVertex); //This will allow the indices to start at 1

	for (;;){
		inputFile >> adjListVertex.adjListData; //Reads from the inputFile and puts it into adjListVertex.adjListData
		if (inputFile.eof()){ //If the end of file is reached, break from this function
			break;
		}

		inputFile >> in; //Reads from the inputFile and puts it into in

		list<int> adjList;  //This will construct an empty list for the adjacency list

		for (int i = 1; i <= in; i++){
			inputFile >> vertex; //Reads from the inputFile and puts it into vertex
			adjList.push_back(vertex);
		}

		adjListVertex.adjacencyList = adjList;
		vectorofAdjList.push_back(adjListVertex);
	}
}



//Implementation of DFS function
template <typename DataType>
void unweightedDigraphClass<DataType>::DFS(int startLocation, vector<bool>& unvisitedNode){
	
	cout << vectorofAdjList[startLocation].adjListData << "\n";
	unvisitedNode[startLocation] = false;

	//This will go through the adjacency list and will perform a depth-first search from each unvisited node that is within the adjacency list
	for (list<int>::iterator repeater = vectorofAdjList[startLocation].adjacencyList.begin(); repeater != vectorofAdjList[startLocation].adjacencyList.end(); repeater++)
		//This checks if the current node has been visited
		if (unvisitedNode[*repeater]){
			//If the current node has been visited, then go back through
			DFS(*repeater, unvisitedNode);
		}
}

//Implementation of adjacencyListData function
template <typename DataType>
inline DataType unweightedDigraphClass<DataType>::adjacencyListData(int data) const {
	return vectorofAdjList[data].adjListData; //Returns the data of the adjacency list
}


//Implementation of findShortestPath function
template<typename DataType>
vector<int> unweightedDigraphClass<DataType>::findShortestPath(int startCity, int destinationCity){
	int sizeofAdjList = vectorofAdjList.size();               
	vector<int> sizeofDistance(sizeofAdjList, -1), startofSizeofDistance(sizeofAdjList);

	sizeofDistance[startCity] = 0; //Puts the startCity at 0 initially
	int distance = 0, vertex;
	queue<int> vertexQueue; //Creates the vertexQueue
	vertexQueue.push(startCity); //Pushes the startCity on the vertexQueue

	//This will perform the queue operations 
	while (sizeofDistance[destinationCity] < 0 && !vertexQueue.empty()){
		vertex = vertexQueue.front();
		vertexQueue.pop();

		if (sizeofDistance[vertex] > distance) { //If sizeofDistance is greater than the distance value, increment distance
			distance++;
		}

		for (list<int>::iterator repeater = vectorofAdjList[vertex].adjacencyList.begin(); repeater != vectorofAdjList[vertex].adjacencyList.end(); repeater++) {
			if (sizeofDistance[*repeater] < 0){ //If sizeofDistance is less than 0 then set to distance value and add 1

				sizeofDistance[*repeater] = distance + 1;
				startofSizeofDistance[*repeater] = vertex; 
				vertexQueue.push(*repeater); //Push the pointer to repeater on the vertexQueue
			}
		}
	}
	distance++;

	//Check if the destination is reachable
	vector<int> path(distance + 1); 
	if (sizeofDistance[destinationCity] < 0){ //If the destinationCity is less than 0, then let the user know that the destination is not reachable from the start city 
		cout << "The destination city not reachable from start city.\n";
	}

	else{ //If the destination city is reachable after the error check was completed, then set the path[distance] to the destinationCity
		path[distance] = destinationCity; 

		for (int i = distance - 1; i >= 0; i--){
			path[i] = startofSizeofDistance[path[i + 1]];
		}
	}
	
	return path; //Returns the shortest path that was found
}

//Implementation of displayAdjList function
template <typename DataType>
void unweightedDigraphClass<DataType>::displayAdjList(ostream& displayOutput){
	displayOutput << "Adjacency-List Representation: \n";
	for (int i = 1; i < vectorofAdjList.size(); i++) {
		
			displayOutput << i << ":" << vectorofAdjList[i].adjListData << "--"; //This is the formatting for the Digraph's Adjacency-List Representation 
		

		for (list<int>::iterator repeater = vectorofAdjList[i].adjacencyList.begin(); repeater != vectorofAdjList[i].adjacencyList.end(); repeater++) { //This goes through adjacency list
			displayOutput << *repeater << " ";
		}
		displayOutput << "\n";
	}
}
