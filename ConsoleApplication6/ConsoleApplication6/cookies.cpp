#include<iostream>
using namespace std;

int main()

{
	int cookies;
	int calories = 10;
	int totalCalories;

	cout << "How many cookies have you eaten today?";
	cin >> cookies;

	//calculate calories consumed
	totalCalories = cookies * calories;

	cout << "You have consumed " << totalCalories << " calories today.";

	return 0;
}