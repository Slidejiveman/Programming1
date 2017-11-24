#include<iostream>

using namespace std;

//int main()
//{
//	int x = 5;
//	int *px = &x;
//	int **ppx = &px;
//
//	cout << x  << " " << *px << " " << **ppx << endl;
//
//	return 0;
//}

int main()
{
	int array[10] = { 3, 8, 5, 4, 6, 9, 1, 7, 0, 2 };
	cout << *(array) << endl;
	cout << *(array + 1) << endl;
	cout << *(array + 5) << endl << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << *(array + i) << endl;
	}
}