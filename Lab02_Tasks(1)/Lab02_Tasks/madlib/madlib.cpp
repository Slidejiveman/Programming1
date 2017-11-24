#include <iostream>
#include <string>
using namespace std;

int main()
{
	string name, age, city, college, profession, animal, petname;

	cout << "Would you mind telling me your name? ";
	getline(cin, name);

	cout << "How about your age? ";
	getline(cin, age);

	cout << "Name your favorite city. ";
	getline(cin, city);

	cout << "Where did you go to college? ";
	getline(cin, college);

	cout << "What do you want to do when you grow up? ";
	getline(cin, profession);

	cout << "What is your favorite kind of animal? ";
	getline(cin, animal);

	cout << "What would you name this animal if it were your pet? ";
	getline(cin, petname);

	cout << "There once was a person named " << name;
	cout << " who lived in " << city << ". " << endl;
	cout << "At the age of " << age << ", " << name << " went to college at " << college << ". ";
	cout << name << " graduated and went to work as a " << profession << ". ";
	cout << "Then, " << name << " adopted a(n) " << animal << " named " << petname << ". ";
	cout << "They both lived happily ever after! " << endl;

	return 0;
}