#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

using namespace std;

int main() {
    // Inizializza il seme del generatore di numeri casuali
    srand(time(0));

    // Dichiarazione dell'array
    int array[20];

    // Generazione di numeri casuali compresi tra 1 e 100 e inserimento nell'array
    for (int i = 0; i < 20; i++) {
        array[i] = rand() % 100 + 1;
    }

    // Stampa dell'array iniziale
    cout << "Array iniziale: ";
    for (int i = 0; i < 20; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    // Chiedi all'utente di inserire un numero compreso tra 10 e 90
    int numeroSelezionato;

    while (true) {
      cout << "Inserisci un numero compreso tra 10 e 90: ";
      cin >> numeroSelezionato;

      if (numeroSelezionato < 10 || numeroSelezionato > 90) {
          cerr <<("Il numero deve essere compreso tra 10 e 90") << endl;;
          continue;
      }


      // Trova tutte le coppie di elementi la cui somma è uguale al numero specificato
      bool esiste = false;
      for (int i = 0; i < 20; i++) {
          for (int j = i + 1; j < 20; j++) {  // i + 1 per evitare la ripezione di coppie di elementi
              if (array[i] + array[j] == numeroSelezionato) {
                  cout << "Coppia di elementi la cui somma e' uguale a " << numeroSelezionato <<
                   ": " << array[i] << " e " << array[j] << endl;
                   esiste = true;
              }
          }
      }

      if (!esiste) {
         cout << "Nell' array non c'e' nessuna coppia di elementi che porta alla somma del numero selezionato" << endl;
      } else {
          break;
        }
    }
    return 0;
}
