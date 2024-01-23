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
    adresatMenedzer.ustawIdZalogowanegoUzytkownika(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    //cout << adresatMenedzer.pobierzIdZalogowanegoUzytkownika() << endl;
    if (adresatMenedzer.pobierzIdZalogowanegoUzytkownika() > 0)
        adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
}

void KsiazkaAdresowa::wylogowanieUzytkownika()
{
    uzytkownikMenedzer.wylogowanieUzytkownika();
    adresatMenedzer.wylogowanieUzytkownika();
}

void KsiazkaAdresowa::dodajAdresata()
{
    adresatMenedzer.dodajAdresata();
}

void KsiazkaAdresowa::wypiszWszystkichAdresatow()
{
    adresatMenedzer.wyswietlWszystkichAdresatow();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownia()
{
    if (adresatMenedzer.pobierzIdZalogowanegoUzytkownika() == 0)
    {
        cout << "Najpierw zaloguj sie aby zmienic haslo!";
        system("pause");
    }
    else
        uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}
