#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::getline;
using std::istringstream;
using std::stoi;

// Calculates and returns the distance between two points
int distance(const int &x1, const int &y1, const int &x2, const int &y2)
{
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

int main(int argc, char *argv[])
{
	string input_file;

	// Check first argument if it exists for input file, otherwise ask user
	if (argc > 1)
	{
		input_file = argv[1];
	}
	else
	{
		cout << "Please enter the path to your input file: " << endl;
		cin >> input_file;
	}

	// Open input file and check if successfully opened
	ifstream ifs(input_file);
	if (!ifs)
	{
		cout << "Failed to open input file." << endl;
		return 1;
	}

	string line;
	while (getline(ifs, line))
	{
		// Parse line and load values into x1,y1,x2 and y2 respectively
		istringstream line(line);
		string temp;
		getline(line, temp, ',');
		temp.erase(0, 1);
		int x1 = stoi(temp);
		getline(line, temp, ')');
		temp.erase(0, 1);
		int y1 = stoi(temp);
		getline(line, temp, ',');
		temp.erase(0, 2);
		int x2 = stoi(temp);
		getline(line, temp, ')');
		temp.erase(0, 1);
		int y2 = stoi(temp);

		// Output distance
		cout << distance(x1,y1,x2,y2) << endl;
	}
	return 0;
}