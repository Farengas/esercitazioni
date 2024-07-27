
#include <iostream>
#include <ctime>
using namespace std;
//dichiaro grandezza massima dell'array
constexpr int SIZE{ 10 };

int main()
{
	int array[SIZE];
	srand(time(NULL));//imposto il seed
	//Creo l'array con numeri 0 o 1 random
	for (int i{ 0 }; i < SIZE; i++)
		array[i] = rand() % 2;
	//stampo l'array
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
	//stampo l'array ordinato
	cout << "Array ordinato:\t { ";
	for (int i{ 0 }; i < SIZE; i++)
		cout << array[i] << ' ';
	cout << "}\n";
	return EXIT_SUCCESS;
}
