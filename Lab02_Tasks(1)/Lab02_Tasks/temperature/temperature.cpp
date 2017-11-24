//This program converts degrees Celsius to Degrees Fahrenheit.
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double celsius, fahrenheit;

	cout << "Please enter the temperature you wish to convert to degrees Fahrenheit. ";
	cin >> celsius;

	//This portion performs the calculation.
	fahrenheit = (9.0 / 5.0) * celsius + 32;

	cout << "The temperature in degrees Fahrenheit is " << fahrenheit << ". " << endl;

	return 0;
}
