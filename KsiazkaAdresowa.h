#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer *adresatMenedzer;
    const string NAZWA_PLIKU_Z_ADRESATAMI;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {
        //uzytkownikMenedzer.wczytajUzytkownikowZPliku();
        adresatMenedzer = NULL;
        //uzytkownikMenedzer.ustawIdZalogowanegoUzytkownika(0);
    }; //stworzenie konstruktora z lista inicjalizacyjna
    ~KsiazkaAdresowa()
    {
        delete adresatMenedzer;
        adresatMenedzer = NULL;
    };
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();
    void wylogowanieUzytkownika();

    void dodajAdresata();
    void wypiszWszystkichAdresatow();
    void zmianaHaslaZalogowanegoUzytkownia();
    void usunAdresata();
    void edycjaAdresata();
    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();

    int pobierzIdZalogowanegoUzytkownika();
    bool czyUzytkownikJestZalogowany();
};

#endif // KSIAZKAADRESOWA_H
