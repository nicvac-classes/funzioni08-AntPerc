#include <iostream>
using namespace std;

int main() {
    int capacMax, u, piante, c;
    string operazione;

    cout << "Benvenuto nel pannello di controllo del giardino." << endl;
    cout << "Inserisci la capienza massima di slot disponibili per piantare delle piante: " << endl;
    cin >> capacMax;
    cout << "Inserisci l'umidità dalla quale iniziare: " << endl;
    cin >> u;
    piante = resetGiardino(capacMax, u);
    operazione = leggiOperazione();
    while (operazione != "X") {
        if (operazione == "P") {
            cout << "Inserisci il numero di piante da piantare: " << endl;
            cin >> c;
            piante = pianta(c, piante);
            if (piante > capacMax) {
                cout << "Il numero di piante che hai scelto da piantare vanno oltre la capienza massima. Sono avanzate " << piante - capacMax << " piante." << endl;
                piante = capacMax;
            }
            cout << "Piante: " << piante << "/" << capacMax << ". Lv Umidità: " << u << endl;
        } else {
            if (operazione == "R") {
                cout << "Inserisci il numero di piante da raccogliere: " << endl;
                cin >> c;
                piante = raccogli(c, piante);
                if (piante < 0) {
                    cout << "Il numero di piante che hai scelto di raccogliere vanno oltre la quantità di piante che erano già presenti." << endl;
                    piante = 0;
                }
                cout << "Piante: " << piante << "/" << capacMax << ". Lv Umidità: " << u << endl;
            } else {
                if (operazione == "I") {
                    u = u + innaffia();
                    cout << "Hai innaffiato il giardino con successo. Livello umidità: " << u << endl;
                } else {
                    if (operazione == "S") {
                        u = u - sole();
                        cout << "Il sole ha fatto il suo lavoro. Livello umidità: " << u << endl;
                    } else {
                        if (operazione == "T") {
                            cout << "Hai deciso di resettare il giardino, inserisci la capienza massima di slot disponibili per piantare delle piante: " << endl;
                            cin >> capacMax;
                            cout << "Inserisci l'umidità dalla quale iniziare: " << endl;
                            cin >> u;
                            piante = resetGiardino(capacMax, u);
                        }
                    }
                }
            }
        }
        operazione = leggiOperazione();
    }
    cout << "Sei uscito dal programma con successo" << endl;
    return 0;
}

int innaffia() {
    int u;

    u = 10;
    
    return u;
}

string leggiOperazione() {
    string operazione;

    cout << "Inserire un operazione tra i seguenti valori: I P R I S T X " << endl;
    do {
        cin >> operazione;
        if (operazione != "I" && operazione != "P" && operazione != "R" && operazione != "S" && operazione != "T" && operazione != "X") {
            cout << "Devi inserire un operazione tra i seguenti valori: I P R I S T X " << endl;
        }
    } while (operazione != "I" && operazione != "P" && operazione != "R" && operazione != "S" && operazione != "T" && operazione != "X");
    
    return operazione;
}

int pianta(int c, int piante) {
    int resto;

    resto = c + piante;
    
    return resto;
}

int raccogli(int c, int piante) {
    int resto;

    resto = piante - c;
    
    return resto;
}

int resetGiardino(int capacMax, int u) {
    int piante;

    piante = 0;
    
    return piante;
}

int sole() {
    int u;

    u = 10;
    
    return u;
}

