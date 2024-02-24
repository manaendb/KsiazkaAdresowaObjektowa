#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <windows.h> //od system("pause")
#include <fstream>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PliikTekstowy.h"

using namespace std;

class PlikZAdresatami : public PlikTekstowy
{
    //const string NAZWA_PLIKU_Z_ADRESATAMI;
    //const string NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI;
    int idOstatniegoAdresata;

    Adresat pobierzDaneAdresata(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    void usunPlik(string nazwaPlikuZRozszerzeniem);
    void zmienNazwePliku(string staraNazwa, string nowaNazwa);

public:
    //PlikZAdresatami(string nazwaPlikuZAdresatami) : NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami),NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI("Adresaci_tymczasowo.txt") {
    PlikZAdresatami(string nazwaPlikuZAdresatami) : PlikTekstowy(nazwaPlikuZAdresatami,"Adresaci_tymczasowo.txt") {
        idOstatniegoAdresata = 0;
    }; //stworzenie konstruktora //dodano liste inicjalizacyjna, bez tego nie mozna tworzyc stalych const w konstruktorze - konieczne na koncu cialo konstruktora {}
    bool dopiszAdresataDoPliku(Adresat adresat);
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    void usunAdresataZPliku(Adresat usuwanyAdresat);
    void przepisanieEdytowanegoAdresataDoPliku(Adresat edytowanyAdresat);

    int pobierzIdOstatniegoAdresata();
};

#endif // PLIKZADRESATAMI_H
