#include<iostream>
using namespace std;

int main()

{
	int x1, x2, y1, y2, m;

	cout << "Please give two points in the Cartesian coordinate system.\n";
	cout << "Do not use parentheses or commas. Separate them only with spaces.";
	cin >> x1 >> y1 >> x2 >> y2;

	//caluclate the slope of the two points
	m = (x2 - x1) / (y2 - y1);

	cout << m << endl;

	return 0;
}