#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h> //od system("pause")
#include <fstream>
#include <sstream>
#include <conio.h>

#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"

using namespace std;

class AdresatMenedzer
{
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA; //idZalogowanegoUzytkownika;
    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;

    Adresat podajDaneNowegoAdresata();
    void wyswietlDaneAdresata(Adresat adresat);
    void wyswietlenieMenuEdycjiAdresata(int pozycjaAdresataWVectorze);
    void wyswietlIloscWyszukanychAdresatow(int iloscAdresatow);

    int podajIdWybranegoAdresata();

public:
    AdresatMenedzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika) : plikZAdresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika) {
        adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };
    //void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void usunAdresata();
    void edycjaAdresataPoPodaniuNrId();
    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();

    //void wylogowanieUzytkownika();

    //void ustawIdOstatniegoAdresata();
    //void ustawIdZalogowanegoUzytkownika(int idLogujacegoSieUzytkownika);
    //int pobierzIdZalogowanegoUzytkownika();
    //pobierzIdOstatniegoAdresata();
};

#endif // ADRESATMENEDZER_H
