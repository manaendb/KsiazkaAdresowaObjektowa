#include "KsiazkaAdresowa.h"

/*KsiazkaAdresowa::KsiazkaAdresowa(string NAZWAPLIKU) : nazwaPlikuZUzytkownikami(NAZWAPLIKU)
{
    uzytkownikMenedzer.wczytajUzytkownikowZPliku();
}*/

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika()
{
    //cout << uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika() << endl;
    uzytkownikMenedzer.logowanieUzytkownika();
    //cout << uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika() << endl;
    //adresatMenedzer.ustawIdZalogowanegoUzytkownika(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    //cout << adresatMenedzer.pobierzIdZalogowanegoUzytkownika() << endl;
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany())
        adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    //if (adresatMenedzer.pobierzIdZalogowanegoUzytkownika() > 0)
        //adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
}

void KsiazkaAdresowa::wylogowanieUzytkownika()
{
    uzytkownikMenedzer.wylogowanieUzytkownika();
    //adresatMenedzer.wylogowanieUzytkownika();
    delete adresatMenedzer;
    adresatMenedzer = NULL;
}

void KsiazkaAdresowa::dodajAdresata()
{
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    {
        adresatMenedzer->dodajAdresata();
    }
    else
    {
        cout << "Najpierw zaloguj sie aby dodac adresata!";
        system("pause");
    }
}

void KsiazkaAdresowa::wypiszWszystkichAdresatow()
{
    adresatMenedzer->wyswietlWszystkichAdresatow();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownia()
{
    if (uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika() == 0)
    {
        cout << "Najpierw zaloguj sie aby zmienic haslo!";
        system("pause");
    }
    else
        uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::usunAdresata()
{
    adresatMenedzer->usunAdresata();
}

void KsiazkaAdresowa::edycjaAdresata()
{
    adresatMenedzer->edycjaAdresataPoPodaniuNrId();
}

void KsiazkaAdresowa::wyszukajAdresatowPoImieniu()
{
    adresatMenedzer->wyszukajAdresatowPoImieniu();
}

void KsiazkaAdresowa::wyszukajAdresatowPoNazwisku()
{
    adresatMenedzer->wyszukajAdresatowPoNazwisku();
}

int KsiazkaAdresowa::pobierzIdZalogowanegoUzytkownika()
{
    return uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika();
}

bool KsiazkaAdresowa::czyUzytkownikJestZalogowany()
{
    if (uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika() > 0)
        return true;
    else
        return false;
}
