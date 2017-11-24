//====================================================================
// Ryder Dale Walton
//9-12-14
//Programming Assignment #1
//Description: Pizza Pi
//====================================================================

/*This program takes the diameter of a pizza in inches 
and calculates the number of slices
into which said pizza can be divided.*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	//since pizzas are circular, pi is needed to calculate area
	const double PI = 3.14159; 

	//the area of a single slice of pizza
	const double PIECE = 14.125; 

	//the input from the user, pizzas are measured by diameter
	double diameter; 

	//the radius of the pizza
	double radius; 

	//the value of the calculation, the area of the entire pizza
	double area; 

	//final outcome: the number of slices
	double slices; 

	cout << "What is the diameter of the pizza in inches? ";
	cin >> diameter;

	//calculate the radius
	radius = diameter / 2.0;

	//calculate the area of the pizza with the formula A=PiR^2
	area = PI * pow(radius, 2.0);

	//calculate number of slices
	slices = area / PIECE;

	cout << fixed << showpoint << setprecision(1);
	cout << "This pizza can be divided into " << slices << " slices." << endl;
	return 0;
}