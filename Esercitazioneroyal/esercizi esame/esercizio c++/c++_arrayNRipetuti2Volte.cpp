#include <iostream>
#include <ctime>
using namespace std;

constexpr int SIZE{ 20 };//dimensione dell'array generato

int main()
{
	int array[SIZE];
	int count[SIZE+1]{ 0 };//inizializzo a 0
	srand(time(NULL));//imposto il seed
	//genero array numeri da 1 a 20
	for (int i{ 0 }; i < SIZE; i++) {
		array[i] = 1 + rand() % 20;
		count[array[i]]++;//Aggiorno il count
	}
	//stampo array generato
	cout << "Array: { ";
	for (int i{ 0 }; i < SIZE; i++)
		cout << array[i] << ' ';
	cout << "}\n";
	//ciclo che controlla se ho dentro count valori = 2
	bool controllo{ false };//controlla se non ci sono valori duplicati
	cout << "\nValori duplicati esattamente 2 volte:\n";
	for (int i{ 1 }; i <= SIZE; i++) {
		if (count[i] == 2) {
			controllo = true;
			cout << "Numero: " << i << "\n";
		}
	}
	if (!controllo)
		cout << "Non ci sono numeri duplicati esattamente 2 volte.\n";
	return EXIT_SUCCESS;
}

