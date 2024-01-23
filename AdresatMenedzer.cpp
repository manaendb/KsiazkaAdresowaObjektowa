#include "AdresatMenedzer.h"

void AdresatMenedzer::wczytajAdresatowZalogowanegoUzytkownikaZPliku()
{
    adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
}

void AdresatMenedzer::dodajAdresata()
{
    if (idZalogowanegoUzytkownika == 0)
    {
        cout << "Najpierw zaloguj sie, aby dodawac adresata!" << endl;
        system("pause");
    }
    else
    {
        Adresat adresat;

        system("cls");
        cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
        adresat = podajDaneNowegoAdresata();

        adresaci.push_back(adresat);
        plikZAdresatami.dopiszAdresataDoPliku(adresat);
    }

}

Adresat AdresatMenedzer::podajDaneNowegoAdresata()
{
    Adresat adresat;
    int idOstatniegoAdresata = plikZAdresatami.pobierzIdOstatniegoAdresata();

    adresat.ustawId(++idOstatniegoAdresata);
    adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);

    cout << "Podaj imie: ";
    adresat.ustawImie(MetodyPomocniczne::wczytajLinie());
    adresat.ustawImie(MetodyPomocniczne::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzImie()));

    cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(MetodyPomocniczne::wczytajLinie());
    adresat.ustawNazwisko(MetodyPomocniczne::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzNazwisko()));

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(MetodyPomocniczne::wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(MetodyPomocniczne::wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(MetodyPomocniczne::wczytajLinie());

    return adresat;
}

void AdresatMenedzer::wyswietlWszystkichAdresatow()
{
    system("cls");
    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat)
{
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

void AdresatMenedzer::wylogowanieUzytkownika()
{
    idZalogowanegoUzytkownika = 0;
    adresaci.clear();
}


void AdresatMenedzer::ustawIdZalogowanegoUzytkownika(int idLogujacegoSieUzytkownika)
{
    idZalogowanegoUzytkownika = idLogujacegoSieUzytkownika;
}

int AdresatMenedzer::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}

