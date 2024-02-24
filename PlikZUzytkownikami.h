#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H

#include <iostream>
#include <vector>
#include <windows.h> //od system("pause")
#include <fstream>

#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"
#include "PliikTekstowy.h"

using namespace std;

class PlikZUzytkownikami : public PlikTekstowy
{
    //const string NAZWA_PLIKU_Z_UZYTKOWNIKAMI; //dopisano const aby przez caly czas zycia programu byla to zmienna absolutnie niezmienna

    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonePionowymiKreskami(Uzytkownik uzytkownik);
    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:
    //PlikZUzytkownikami(string nazwaPlikuZUzytkownikami) : NAZWA_PLIKU_Z_UZYTKOWNIKAMI(nazwaPlikuZUzytkownikami) {}; //stworzenie konstruktora //dodano liste inicjalizacyjna, bez tego nie mozna tworzyc stalych const w konstruktorze - konieczne na koncu cialo konstruktora {}
    PlikZUzytkownikami(string nazwaPlikuZUzytkownikami) : PlikTekstowy(nazwaPlikuZUzytkownikami,"") {}; //stworzenie konstruktora //dodano liste inicjalizacyjna, bez tego nie mozna tworzyc stalych const w konstruktorze - konieczne na koncu cialo konstruktora {}
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    vector <Uzytkownik> wczytajUzytkownikowZPliku();
    void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> uzytkownicy);
};

#endif // PLIKZUZYTKOWNIKAMI_H
