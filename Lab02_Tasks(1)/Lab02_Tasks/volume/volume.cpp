
// Enter and modify the book's code as needed to make the
// program work

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	const double PI = 3.14159;
	double volume, radius, height;

	cout << "This program will tell you the volume of \n";
	cout << "a cylinder-shaped fuel tank. \n";
	cout << "How tall is the tank? ";
	cin >> height;
	cout << "What is the radius of the tank? ";
	cin >> radius;

	//Calculate the volume
	volume = PI * pow(radius, 2.0) * height;

	cout << "The Volume of this tank is: " << volume << endl;
	
	return 0;
}