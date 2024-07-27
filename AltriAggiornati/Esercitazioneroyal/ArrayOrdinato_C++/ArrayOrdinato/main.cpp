
#include <iostream>
#include <ctime>
using namespace std;

constexpr int SIZE{ 10 };

int main()
{
	int array[SIZE];
	srand(time(NULL));

	for (int i{ 0 }; i < SIZE; i++)
		array[i] = rand() % 2;

	cout << "Array: { ";
	for (int i{ 0 }; i < SIZE; i++)
		cout << array[i] << ' ';
	cout << "}\n";
	//ordino l'array
	int temp{ 0 };
	for (int i{ 0 }; i < SIZE; i++)
	{
		if (array[i] == 0){
			swap(array[temp], array[i]);
			temp++;
		}
	}

	cout << "Array ordinato:\t { ";
	for (int i{ 0 }; i < SIZE; i++)
		cout << array[i] << ' ';
	cout << "}\n";
	return EXIT_SUCCESS;
}
