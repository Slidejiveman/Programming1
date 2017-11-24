#include<iostream>
#include<iomanip>
using namespace std;

int main()

{
	int test1, test2, test3, test4, test5;
	float average;

	cout << "Please enter 5 test scores separated by spaces.";
	cin >> test1 >> test2 >> test3 >> test4 >> test5;

	//calculate the average test score
	average = static_cast<float>(test1 + test2 + test3 + test4 + test5) / 5;

	cout << fixed << showpoint << setprecision(1);
	cout << "Your average score is " << average << ".\n";

	return 0;
}