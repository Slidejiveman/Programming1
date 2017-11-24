#include<iostream>
using namespace std;

int main()

{
	int game1, game2, game3;
	float average;

	cout << "Enter the score for three rounds of golf.";
	cin >> game1 >> game2 >> game3;

	//calculate the average
	average = static_cast<float>(game1 + game2 + game3) / 3;

	cout << "Your average is " << average << endl;

	return 0;
}