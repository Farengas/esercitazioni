#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Inizializza il seme del generatore di numeri casuali
    srand(time(0));

    // Dichiarazione dell'array
    int array[20];

    // Generazione di numeri casuali compresi tra 1 e 20 e inserimento nell'array
    for (int i = 0; i < 20; i++) {
        array[i] = rand() % 20 + 1;
    }

    // Stampa dell'array iniziale
    cout << "Array iniziale: ";
    for (int i = 0; i < 20; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    int count[20] = {0}; // array per conteggiare le occorrenze di ogni elemento
    for (int i = 0; i < 20; i++) {
        count[arr[i] - 1]++; // incrementa il conteggio dell'elemento corrente
    }

    cout << "Elementi ripetuti solo due volte:" << endl;
    for (int i = 0; i < 20; i++) {
        if (count[i] == 2) {
            cout << i + 1 << " " << endl;
        }
    }

    return 0;
}







    /*

    // int stampa = -1;

    // Trovo cosi gli elementi ripetuti esattamente due volte
    for (int i = 0; i < 20; i++) {
        int count = 0;
        for (int j = 0; j < 20; j++) {
            if (array[i] == array[j]) {
                count++;

            }
        }             // && array[i] != stampa
        if (count == 2) {
            cout << "Elemento ripetuto esattamente due volte: " << array[i] << endl;
           // stampa = array[i];
        }
    }

    return 0;
    */

    int count[20] = {0}; // array per conteggiare le occorrenze di ogni elemento
    for (int i = 0; i < 20; i++) {
        count[arr[i] - 1]++; // incrementa il conteggio dell'elemento corrente
    }

    cout << "Elementi ripetuti esattamente due volte:" << endl;
    for (int i = 0; i < 20; i++) {
        if (count[i] == 2) {
            cout << i + 1 << " " << endl;
        }
    }

    return 0;
}

/*
   // Dichiaro l'inizializzazione per i numeri causali
     srand(time(0));

     // inizializzo l'array
     int array[20];

     // Genero i numeri casuali col rand e l'inserisco nell array
     for (int i = 0; i < 20; i++) {
        array[i] = rand() % 20 + 1;
    }

    // Stampo l'array
    cout << "Questo e l'array iniziale generato: ";
    for ( int i = 0; i < 20; i++) {
        cout << array[i] << " ";
    }

    for (int i = 0; i < 20; i++) {
        count = 0;
        for (int j = 0; j < 20; j++) {
        if (array[i] == array[j])
            count++;
        }
        if (count == 2)
         cout << "Eleemtni ripetut" << array[i] << "\n";
    }
*/
