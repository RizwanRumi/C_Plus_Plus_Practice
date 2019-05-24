// ReadCSVFileApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


int main(int argc, char** argv)
{

	string filename = "exampleout.csv";

	int i, A, B, C;

	//ofstream outputFile;
	ofstream fs;
		
	fs.open(filename, ios::out | ios::app);
	fs << "Column A" << "Column B" << "Column C" << endl;

	i = 1;

	// write data to the file
	for (int counter = 0; counter < 10; counter++)
	{
		// make some data
		A = i + 5;
		B = i + 10;
		C = i + 20;

		// write the data to the output file
		fs << A << "," << B << "," << C << endl;

		// increase i
		i = i * 5;
	}

	// close the output file
	fs.close();
	return 0;

    cout << "Hello World!\n"; 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
