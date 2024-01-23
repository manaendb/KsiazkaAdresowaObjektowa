#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h> //od system("pause")
#include <fstream>
#include <sstream>

#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"

using namespace std;

class AdresatMenedzer
{
    int idZalogowanegoUzytkownika;
    vector <Adresat> adresaci;

    Adresat podajDaneNowegoAdresata();
    PlikZAdresatami plikZAdresatami;
    void wyswietlDaneAdresata(Adresat adresat);

public:
    AdresatMenedzer(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami) {};
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void wylogowanieUzytkownika();

    //void ustawIdOstatniegoAdresata();
    void ustawIdZalogowanegoUzytkownika(int idLogujacegoSieUzytkownika);
    int pobierzIdZalogowanegoUzytkownika();
    //pobierzIdOstatniegoAdresata();
};

#endif // ADRESATMENEDZER_H
