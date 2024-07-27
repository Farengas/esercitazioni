#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    // Inizializzo il generatore di numeri casuali
    srand(time(0));

    // Dichiaro l'array
    int array[10];

    // Genero i numeri casuali (0 o 1) e l'inserisco nell'array
    for (int i = 0; i < 10; i++) {
        array[i] = rand() % 2;
    }

    // Stampa dell'array iniziale
    cout << "Array iniziale: ";
    for (int i = 0; i < 10; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    // Separo 0 e 1
   /* int i = 0, j = 9; // oppure 10 (?) con == 0 (?) e riordino prima con 1
    while (i < j) {
        if (array[i] == 1) {
            swap(array[i], array[j]);
            j--;
        } else {
            i++;
        }
    }
    */

   // entrambi funzionali
    for (int i = 0; i < 10; i++) {
        if (arr[i] == 0) {
            swap(arr[i], arr[one]);
            one++;
        }
    }

    // Stampo così l'array riordinato con prima gli 0 e poi gli 1
    cout << "Array riordinato con 0 prima e poi 1: ";
    for (int i = 0; i < 10; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
