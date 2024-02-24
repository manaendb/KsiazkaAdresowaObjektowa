#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h> //od system("pause")
#include <fstream>
#include <sstream>

#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"
#include "MetodyPomocnicze.h"
#include "AdresatMenedzer.h"

using namespace std;

class UzytkownikMenedzer
{
    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    PlikZUzytkownikami plikZUzytkownikami;

public:
    UzytkownikMenedzer(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami) {
        uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
        //ustawIdZalogowanegoUzytkownika(0);
        idZalogowanegoUzytkownika = 0;
    };
    //void wczytajUzytkownikowZPliku();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void zmianaHaslaZalogowanegoUzytkownika();
    void logowanieUzytkownika();
    void wylogowanieUzytkownika();
    bool czyUzytkownikJestZalogowany();

    int pobierzIdZalogowanegoUzytkownika();
    void ustawIdZalogowanegoUzytkownika(int liczba);
};

#endif // UZYTKOWNIKMENEDZER_H
