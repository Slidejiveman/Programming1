//====================================================================
// Ryder Dale Walton
//9-12-14
//Programming Assignment #1
//Description: Pizza Pi
//====================================================================

//This program takes the diameter of a pizza in inches and calculates the number of slices
//into which said pizza can be divided.
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	const double PI = 3.14159; //Since a pizza is a circle, pi must be used to calculate its area.
	double diameter; //When diameter is divided by two, it yields the radius.
	double radius; //The radius is raised to the second power in the formula.
	double area; //The final equation: A=PiR^2
	const double PIECE = 14.125; //Each slice will have a predetermined area in inches.
	double slices; //This is the final outcome, given when the area of the pizza is divide by the area of a slice.

	cout << "What is the diameter of the pizza in inches? " << endl;
	cin >> diameter;

	//calculate the radius
	radius = diameter / 2.0;

	//calculate the area of the pizza
	area = PI * pow(radius, 2.0);

	//calculate number of slices
	slices = area / PIECE;

	cout << "This pizza can be divided into " << slices << " slices." << endl;
	return 0;
}