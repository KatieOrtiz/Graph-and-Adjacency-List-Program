#include "GraphHeader.h"
#include "GraphImplementation.cpp"


int main(){		

	unweightedDigraphClass<string> uDC; 
	string inputFileFromUser;
	int startCity, destinationCity;
	char answer;

	cout << "Please enter the name of network file: "; //This asks the user to enter the file that they would like to use to create the unweighted graph represented by an adjacency list
	cin >> inputFileFromUser;

	ifstream inputFile(inputFileFromUser.data());

	if (!inputFile.is_open()){
		cerr << "ERROR: The file " << inputFileFromUser << " cannot be opened. The program will now exit.\n"; //This displays an error if the file that was read from the user input cannot be found or open
		exit(-1); //If the error was thrown, this will exit the program
	}

	uDC.fileInput(inputFile);

	cout << "The Digraph's "; //This is the start of the display of the adjacency list
	uDC.displayAdjList(cout);
	cout << "\n";


	do{ 
		int i = 0;

		//This asks the user to enter the start city and then the destination city
		cout << "Number of start city? ";
		cin >> startCity;
		cout << "Number of destination? ";
		cin >> destinationCity;
		cout << "\n";
	
		vector<int> path = uDC.findShortestPath(startCity, destinationCity);
		
		cout << "Shortest path from " << uDC.adjacencyListData(path[i]) << " to " << uDC.adjacencyListData(destinationCity) << " is: \n"; 
		
		for (int i = 0; i < path.size(); i++){ //Loops through the path and displays the shortest path from the specified start city to the destination city
			cout << setw(3) << path[i] << ' ' << uDC.adjacencyListData(path[i]) << "\n";
			cout << "    |\n" "    V\n"; //This is the formatting for the path that is displayed in the sample output
		}
		cout << setw(3) << destinationCity << ' ' << uDC.adjacencyListData(destinationCity) << "\n"; //Displays the destination city

		cout << "\n More (Y or N)? "; //Asks the user if they want to see another path from the start city to the destination city
		cin >> answer;
		cout << "\n";

	} while (answer == 'Y' || answer == 'y');
	
	cout << "Thank you and goodbye!! \n\n";
	system("pause");
	return 0;
}
