#ifndef TRAFFIC_H
#define TRAFFIC_H

class Traffic
{
public: //add prototypes below
	Traffic();
	void enter(int cars, int people);
	void exit(int cars, int people);
	void display();

private:
	int carsInPark;
	int peopleInPark;
};
#endif