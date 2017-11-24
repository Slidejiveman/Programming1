#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int year;
	float seaLevel = 1.5;

	cout << "Years  Sea Level Increase\n";
	for (year = 1, seaLevel = 1.5; year <= 25; year++, seaLevel += 1.5)
	{
		cout << setw(6) << left << year;
		cout << setw(6) << right << seaLevel << endl;
	}
	return 0;
}