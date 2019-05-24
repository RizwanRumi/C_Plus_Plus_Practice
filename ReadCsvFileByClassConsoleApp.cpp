// ReadCsvFileByClassConsoleApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <string>


using namespace std;

struct Vector3d
{
public:
	double x;
	double y;
	double z;



	Vector3d()
	{
		x = 0;
		y = 0;
		z = 0;

		
	}

	Vector3d(double init_X, double init_Y, double init_Z)
	{
		x = init_X;
		y = init_Y;
		z = init_Z;

		
	}

	double get_x()
	{
		return x;
	}
	double get_y()
	{
		return y;
	}
	double get_z()
	{
		return z;
	}	
	
};




class CSVWriter
{
	string fileName;
	string delimeter;
	int linesCount;

public:
	CSVWriter(string filename, string delm = ",") :
		fileName(filename), delimeter(delm), linesCount(0)
	{}


	template<typename T> 
	void addDatainRow(T first, T last);
};



template<typename T>
void CSVWriter::addDatainRow(T first, T last)
{
	fstream file;

	file.open(fileName, ios::out | (linesCount ? ios::app : ios::trunc));
		
	for (; first != last; )
	{
		file << *first;
		if (++first != last)
			file << delimeter;
	}
	file << endl;
	linesCount++;

	file.close();
}




int main()
{
	Vector3d v_1 = Vector3d(1,2,3);
	Vector3d v_2 = Vector3d(4,5,6);
	Vector3d v_3 = Vector3d(7,8,9);
	Vector3d v_4 = Vector3d(11,12,13);

	vector<Vector3d> point;
	point.push_back(v_1);
	point.push_back(v_2);
	point.push_back(v_3);
	point.push_back(v_4);
	
	vector<double> temp;

	CSVWriter writer("example.csv");

	for (vector<Vector3d>::iterator point_iterator1 = point.begin(); point_iterator1 != point.end(); point_iterator1++)
	{
		cout << point_iterator1[0].x << point_iterator1[0].y << point_iterator1[0].z << endl;
		temp.clear();

		temp.push_back(point_iterator1[0].x);
		temp.push_back(point_iterator1[0].y);
		temp.push_back(point_iterator1[0].z);


		writer.addDatainRow(temp.begin(), temp.end());
	}

	//vector<string> dataList_1 = { "20", "hi", "99" };
	//
	//writer.addDatainRow(dataList_1.begin(), dataList_1.end());

	//// Create a set of integers
	//set<int> dataList_2 = { 3, 4, 5 };

	//// Adding Set to CSV File
	//writer.addDatainRow(dataList_2.begin(), dataList_2.end());

	//string str = "abc";

	//// Adding characters in a string in csv file.
	//writer.addDatainRow(str.begin(), str.end());

	//// An array of int
	//int arr[] = { 3,4,1 };

	//// Wrote an elements in array to csv file.
	//writer.addDatainRow(arr, arr + sizeof(arr) / sizeof(int));

	return 0;

}

