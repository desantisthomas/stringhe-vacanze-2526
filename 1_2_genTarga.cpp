#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

const string STRINGA_BASE = "Informatica2025";

// Prototipi
char chr(int num_generato);
bool isConsonante(char c);
char generaConsonanteCasuale();
char generaPrimoElemento();
char generaSecondoElemento();
string generaNumeri();
char generaLetteraCasuale();
string generaTarga();

string sostituisciNumeriConX(string targa);
string invertiTarga(string targa);
bool contieneNumero(string targa, int numero);

int main() {
    srand(time(NULL));
    int numDaCercare;
    string targa = generaTarga();
    cout << "Targa generata: " << generaTarga() << endl;

    cout << "Targa con X al posto dei numeri: " << sostituisciNumeriConX(targa) << endl;

    cout << "Targa invertita: " << invertiTarga(targa) << endl;

    cout<< "Cerca un numero nella targa: "<<endl;
    cin>>numDaCercare;
    if (contieneNumero(targa, numDaCercare))
        cout << "La targa contiene il numero " << numDaCercare << endl;
    else
        cout << "La targa NON contiene il numero " << numDaCercare << endl;

    return 0;
}

// Funzione chr richiesta dalla consegna
char chr(int num_generato) {
    return static_cast<char>(num_generato);
}

string generaTarga() {
    string targa = "";

    targa.append(1, generaPrimoElemento());
    targa.append(1, generaSecondoElemento());
    targa.append(generaNumeri());
    targa.append(1, generaLetteraCasuale());
    targa.append(1, generaLetteraCasuale());

    return targa;
}

// Elemento 1
char generaPrimoElemento() {
    char c = toupper(STRINGA_BASE[3]);

    /*
     Strategia:
     Se il carattere estratto non è una consonante,
     genero una consonante casuale.
     */
    if (!isConsonante(c)) {
        c = generaConsonanteCasuale();
    }

    return c;
}

// Elemento 2
char generaSecondoElemento() {
    char c;

    /*
     Strategia:
     Rigenero finché non ottengo
     una consonante maiuscola.
     */
    do {
        int ascii = rand() % 26 + 65;
        c = toupper(chr(ascii));
    } while (!isConsonante(c));

    return c;
}

// Elementi 3-4-5
string generaNumeri() {
    int n = rand() % 1000; // 0 - 999
    string temp = to_string(n);

    while (temp.length() < 3) {
        temp = "0" + temp;
    }

    return temp;
}

// Elementi 6-7
char generaLetteraCasuale() {
    int ascii = rand() % 26 + 65;
    return chr(ascii);
}

// Controllo consonante casuale maiuscola
char generaConsonanteCasuale() {
    char c;

    do {
        int ascii = rand() % 26 + 65;
        c = chr(ascii);
    } while (!isConsonante(c));

    return c;
}

bool isConsonante(char c) {
    c = toupper(c);

    if (c < 'A' || c > 'Z')
        return false;

    return !(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

string sostituisciNumeriConX(string targa) {
    string nuova = targa;
    for (int i = 0; i < nuova.length(); i++) {
        if (nuova[i] >= '0' && nuova[i] <= '9') {
            nuova[i] = 'X';
        }
    }
    return nuova;
}

string invertiTarga(string targa) {
    string invertita = targa;
    int inizio = 0;
    int fine = invertita.length() - 1;
    char appoggio;

    while (inizio < fine) {
        appoggio = invertita.at(inizio);
        invertita.at(inizio) = invertita.at(fine);
        invertita.at(fine) = appoggio;
        inizio++;
        fine--;
    }

    return invertita;
}

bool contieneNumero(string targa, int numero) {
    string num = to_string(numero);
    if (targa.find(num) != -1) {
        return true;
    }
    return false;
}
