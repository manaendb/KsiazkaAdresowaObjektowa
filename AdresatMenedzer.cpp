#include "AdresatMenedzer.h"

/*void AdresatMenedzer::wczytajAdresatowZalogowanegoUzytkownikaZPliku()
{
    adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
}*/

/*void AdresatMenedzer::dodajAdresata()
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
}*/

void AdresatMenedzer::dodajAdresata() //funkcja Artura
{
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    if (plikZAdresatami.dopiszAdresataDoPliku(adresat))
        cout << "Nowy adresat zostal dodany" << endl;
    else
        cout << "Blad. Nie udalo sie dodac nowego adresata do pliku." << endl;
    system("pause");
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata()
{
    Adresat adresat;
    int idOstatniegoAdresata = plikZAdresatami.pobierzIdOstatniegoAdresata();

    adresat.ustawId(++idOstatniegoAdresata);
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

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

void AdresatMenedzer::usunAdresata()
{
    if (ID_ZALOGOWANEGO_UZYTKOWNIKA == 0)
    {
        system("cls");
        cout << "Najpierw sie zaloguj, aby usuwac adresatow!" << endl;
        system("pause");
    }
    else
    {
        int idUsuwanegoAdresata = 0;

        system("cls");
        cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
        idUsuwanegoAdresata = podajIdWybranegoAdresata();

        char znak;
        bool czyIstniejeAdresat = false;

        for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            if (itr -> pobierzId() == idUsuwanegoAdresata)
            {
                czyIstniejeAdresat = true;
                cout << endl << "Potwierdz naciskajac klawisz 't': ";
                znak = MetodyPomocniczne::wczytajZnak();
                if (znak == 't')
                {
                    //numerLiniiUsuwanegoAdresata = zwrocNumerLiniiSzukanegoAdresata(idUsuwanegoAdresata);
                    //usunWybranaLinieWPliku(numerLiniiUsuwanegoAdresata);
                    plikZAdresatami.usunAdresataZPliku(*itr);
                    //plikZAdresatami.usunAdresataZPliku(idUsuwanegoAdresata);
                    adresaci.erase(itr);
                    cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                    system("pause");

                    return;
                }
                else
                {
                    cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                    system("pause");
                    return;
                }
            }
        }
        if (czyIstniejeAdresat == false)
        {
            cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
            system("pause");
        }
    }
}

int AdresatMenedzer::podajIdWybranegoAdresata()
{
    int idWybranegoAdresata = 0;
    cout << "Podaj numer ID Adresata: ";
    idWybranegoAdresata  = MetodyPomocniczne::wczytajLiczbeCalkowita();
    return idWybranegoAdresata;
}

void AdresatMenedzer::edycjaAdresataPoPodaniuNrId()
{
    int nrIdAdresata;
    string wyjscieDoMenuGlownego = "";
    bool czyZnalezionoNrId = false;

    while (wyjscieDoMenuGlownego != "9")
    {
        system("cls");

        if (adresaci.empty())
        {
            cout << "Baza adresatow jest pusta. Dodaj najpierw adresata przed edycja!" << endl;
            cout << "9. Wyjscie do glownego menu" << endl;
            wyjscieDoMenuGlownego = MetodyPomocniczne::wczytajZnak();
        }

        else
        {
            cout << "<<< MENU EDYCJI >>>" << endl << endl;
            cout << "Podaj nr Id adresata do edycji: " ;
            nrIdAdresata = MetodyPomocniczne::wczytajLiczbeCalkowita();
            for (size_t i = 0; i < adresaci.size(); i++)
            {
                if (adresaci[i].pobierzId() == nrIdAdresata)
                {
                    czyZnalezionoNrId = true;
                    wyswietlenieMenuEdycjiAdresata(i);
                    system("cls");
                    cout << "<<< MENU EDYCJI >>>" << endl << endl;
                }
            }
            if (!czyZnalezionoNrId)
            {
                cout << endl << "Nie znaleziono nr Id o podanym nr" << endl << endl;
                getchar();
            }
            cout << "9. Wyjscie do glownego menu (kazdy inny klawisz - ponowne wpisanie nr Id do edycji): ";
            wyjscieDoMenuGlownego = MetodyPomocniczne::wczytajZnak();
        }
    }
}

void AdresatMenedzer::wyswietlenieMenuEdycjiAdresata(int pozycjaAdresataWVectorze)
{
    char wybor;
    bool czyWprowadzonoJakasZmiane = false;
    while(1)
    {
        system("cls");
        cout << "<<< MENU EDYCJI ADRESATA O ID " << adresaci[pozycjaAdresataWVectorze].pobierzId() << " >>>" << endl << endl;
        cout << "1. Zmiana imienia" << endl;
        cout << "2. Zmiana nazwiska" << endl;
        cout << "3. Zmiana nr telefonu" << endl;
        cout << "4. Zmiana email" << endl;
        cout << "5. Zmiana adresu" << endl;
        cout << "6. Powrot do menu edycji adresata po nr Id" << endl;
        cout << "Wybierz opcje: ";
        wybor = MetodyPomocniczne::wczytajZnak();

        switch (wybor)
        {
        case '1':
        {
            cout << "Aktualne imie: " << adresaci[pozycjaAdresataWVectorze].pobierzImie() << endl;
            cout << "Wprowadz nowe imie: ";
            adresaci[pozycjaAdresataWVectorze].ustawImie(MetodyPomocniczne::wczytajLinie());
            adresaci[pozycjaAdresataWVectorze].ustawImie(MetodyPomocniczne::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresaci[pozycjaAdresataWVectorze].pobierzImie()));
            czyWprowadzonoJakasZmiane = true;
            break;
        }
        case '2':
        {
            cout << "Aktualne nazwisko: " << adresaci[pozycjaAdresataWVectorze].pobierzNazwisko() << endl;
            cout << "Wprowadz nowe nazwisko: ";
            adresaci[pozycjaAdresataWVectorze].ustawNazwisko(MetodyPomocniczne::wczytajLinie());
            adresaci[pozycjaAdresataWVectorze].ustawNazwisko(MetodyPomocniczne::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresaci[pozycjaAdresataWVectorze].pobierzNazwisko()));
            czyWprowadzonoJakasZmiane = true;
            break;
        }
        case '3':
        {
            cout << "Aktualny nr telefonu: " << adresaci[pozycjaAdresataWVectorze].pobierzNumerTelefonu() << endl;
            cout << "Wprowadz nowy nr telefonu: ";
            adresaci[pozycjaAdresataWVectorze].ustawNumerTelefonu(MetodyPomocniczne::wczytajLinie());
            czyWprowadzonoJakasZmiane = true;
            break;
        }
        case '4':
        {
            cout << "Aktualny email: " << adresaci[pozycjaAdresataWVectorze].pobierzEmail() << endl;
            cout << "Wprowadz nowy email: ";
            adresaci[pozycjaAdresataWVectorze].ustawEmail(MetodyPomocniczne::wczytajLinie());
            czyWprowadzonoJakasZmiane = true;
            break;
        }
        case '5':
        {
            cout << "Aktualny adres: " << adresaci[pozycjaAdresataWVectorze].pobierzAdres() << endl;
            cout << "Wprowadz nowy adres: ";
            adresaci[pozycjaAdresataWVectorze].ustawAdres(MetodyPomocniczne::wczytajLinie());
            czyWprowadzonoJakasZmiane = true;
            break;
        }
        case '6':
        {
            if (czyWprowadzonoJakasZmiane)
                plikZAdresatami.przepisanieEdytowanegoAdresataDoPliku(adresaci[pozycjaAdresataWVectorze]);
            return;
        }
        default:
        {
            cout << endl << "Nie ma takiej opcji w menu" << endl;
            getch();
        }
        }
    }
}

void AdresatMenedzer::wyszukajAdresatowPoImieniu()
{
    string imiePoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        imiePoszukiwanegoAdresata = MetodyPomocniczne::wczytajLinie();
        imiePoszukiwanegoAdresata = MetodyPomocniczne::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imiePoszukiwanegoAdresata);

        for (vector <Adresat>::iterator  itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            if (itr -> pobierzImie() == imiePoszukiwanegoAdresata)
            {
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
        wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AdresatMenedzer::wyszukajAdresatowPoNazwisku()
{
    string nazwiskoPoszukiwanegoAdresata;
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o nazwisku: ";
        nazwiskoPoszukiwanegoAdresata = MetodyPomocniczne::wczytajLinie();
        nazwiskoPoszukiwanegoAdresata = MetodyPomocniczne::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwiskoPoszukiwanegoAdresata);

        for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            if (itr -> pobierzNazwisko() == nazwiskoPoszukiwanegoAdresata)
            {
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
         wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    cout << endl;
    system("pause");
}


void AdresatMenedzer::wyswietlIloscWyszukanychAdresatow(int iloscAdresatow)
{
    if (iloscAdresatow == 0)
        cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
    else
        cout << endl << "Ilosc adresatow w ksiazce adresowej wynosi: " << iloscAdresatow << endl << endl;
}



/*int zwrocNumerLiniiSzukanegoAdresata(int idAdresata)
{
    bool czyIstniejeAdresat = false;
    int numerLiniiWPlikuTekstowym = 1;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    fstream plikTekstowy;
    plikTekstowy.open(nazwaPlikuZAdresatami.c_str(), ios::in);

    if (plikTekstowy.good() == true && idAdresata != 0)
    {
        while(getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(idAdresata == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                czyIstniejeAdresat = true;
                plikTekstowy.close();
                return numerLiniiWPlikuTekstowym;
            }
            else
                numerLiniiWPlikuTekstowym++;
        }
        if (czyIstniejeAdresat = false)
        {
            plikTekstowy.close();
            return 0;
        }
    }
    return 0;
}


int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocniczne::konwersjaStringNaInt(MetodyPomocniczne::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
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
}*/

