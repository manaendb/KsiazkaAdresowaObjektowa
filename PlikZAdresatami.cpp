#include "PlikZadresatami.h"

bool PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat) //Artur zastosowal tutaj funkcje bool, ktora zwraca false jesli jest problem z otwarciem pliku.
{
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(PlikTekstowy::pobierzNazwePliku().c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true)
    {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

        if (PlikTekstowy::czyPlikJestPusty() == true)
        {
            plikTekstowy << liniaZDanymiAdresata;
        }
        else
        {
            plikTekstowy << endl << liniaZDanymiAdresata ;
        }
        idOstatniegoAdresata++;
        plikTekstowy.close();
        return true;
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
        return false;
    }

    system("pause");
    return false;
}

vector <Adresat> PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika)
{
    Adresat adresat;
    vector <Adresat> adresaci;
    //idOstatniegoAdresata = 0;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(PlikTekstowy::pobierzNazwePliku().c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
        plikTekstowy.close();
    }

    if (daneOstaniegoAdresataWPliku != "")
    {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
    }
    return adresaci;
}

Adresat PlikZAdresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami)
{
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (size_t pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejAdresata)
            {
            case 1:
                adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}

int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocniczne::konwersjaStringNaInt(MetodyPomocniczne::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}

int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocniczne::konwersjaStringNaInt(MetodyPomocniczne::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}

string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat)
{
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocniczne::konwersjaIntNaString(adresat.pobierzId()) + '|';
    liniaZDanymiAdresata += MetodyPomocniczne::konwersjaIntNaString(adresat.pobierzIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}

int PlikZAdresatami::pobierzIdOstatniegoAdresata()
{
    return idOstatniegoAdresata;
}

void PlikZAdresatami::usunAdresataZPliku(Adresat usuwanyAdresat)
{
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia = "";
    int numerWczytanejLinii = 1;
    bool czyLiniaZostalaUsunieta = false;
    int idAdresataZAktualniePobranejLinii = 0;

    odczytywanyPlikTekstowy.open(PlikTekstowy::pobierzNazwePliku().c_str(), ios::in);
    tymczasowyPlikTekstowy.open(PlikTekstowy::pobierzNazwePlikuTymczasowego().c_str(), ios::out | ios::app);

    string usuwanyAdresatPrzeksztalconyNaLinieOdzielonePionowymiKreskami = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(usuwanyAdresat);

    if (odczytywanyPlikTekstowy.good() == true)
    {
        while (getline(odczytywanyPlikTekstowy, wczytanaLinia))
        {
            if (wczytanaLinia == usuwanyAdresatPrzeksztalconyNaLinieOdzielonePionowymiKreskami)
            {
                czyLiniaZostalaUsunieta = true;
            }
            else if (wczytanaLinia != usuwanyAdresatPrzeksztalconyNaLinieOdzielonePionowymiKreskami && numerWczytanejLinii == 1)
            {
                tymczasowyPlikTekstowy << wczytanaLinia;
                idAdresataZAktualniePobranejLinii = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia);
            }
            else if (wczytanaLinia != usuwanyAdresatPrzeksztalconyNaLinieOdzielonePionowymiKreskami && numerWczytanejLinii > 1)
            {
                if (numerWczytanejLinii == 2 && czyLiniaZostalaUsunieta)
                {
                    tymczasowyPlikTekstowy << wczytanaLinia;
                    idAdresataZAktualniePobranejLinii = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia);
                }
                else
                {
                    tymczasowyPlikTekstowy << endl << wczytanaLinia;
                    idAdresataZAktualniePobranejLinii = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia);
                }
            }
            numerWczytanejLinii++;
        }

        int idUsunietegoAdresata = usuwanyAdresat.pobierzId();

        if (idUsunietegoAdresata == idOstatniegoAdresata)
            idOstatniegoAdresata = idAdresataZAktualniePobranejLinii;

        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunPlik(PlikTekstowy::pobierzNazwePliku());
        zmienNazwePliku(PlikTekstowy::pobierzNazwePlikuTymczasowego(), PlikTekstowy::pobierzNazwePliku());
    }
}

void PlikZAdresatami::przepisanieEdytowanegoAdresataDoPliku(Adresat edytowanyAdresat)
{
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia = "";
    int numerWczytanejLinii = 1;

    odczytywanyPlikTekstowy.open(PlikTekstowy::pobierzNazwePliku().c_str(), ios::in);
    tymczasowyPlikTekstowy.open(PlikTekstowy::pobierzNazwePlikuTymczasowego().c_str(), ios::out | ios::app);

    string edytowanyAdresatPrzeksztalconyNaLinieOdzielonePionowymiKreskami = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(edytowanyAdresat);
    int idEdytowanegoAdresata = edytowanyAdresat.pobierzId();

    if (odczytywanyPlikTekstowy.good() == true)
    {
        while (getline(odczytywanyPlikTekstowy, wczytanaLinia))
        {
            if (idEdytowanegoAdresata == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia))
            {
                if (numerWczytanejLinii == 1)
                    tymczasowyPlikTekstowy << edytowanyAdresatPrzeksztalconyNaLinieOdzielonePionowymiKreskami;
                else if (numerWczytanejLinii > 1)
                    tymczasowyPlikTekstowy << endl << edytowanyAdresatPrzeksztalconyNaLinieOdzielonePionowymiKreskami;
            }
            else
            {
                if (numerWczytanejLinii == 1)
                    tymczasowyPlikTekstowy << wczytanaLinia;
                else if (numerWczytanejLinii > 1)
                    tymczasowyPlikTekstowy << endl << wczytanaLinia;
            }
            numerWczytanejLinii++;
        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunPlik(PlikTekstowy::pobierzNazwePliku());
        zmienNazwePliku(PlikTekstowy::pobierzNazwePlikuTymczasowego(), PlikTekstowy::pobierzNazwePliku());
    }
}

void PlikZAdresatami::usunPlik(string nazwaPlikuZRozszerzeniem)
{
    if (remove(nazwaPlikuZRozszerzeniem.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << nazwaPlikuZRozszerzeniem << endl;
}

void PlikZAdresatami::zmienNazwePliku(string staraNazwa, string nowaNazwa)
{
    if (rename(staraNazwa.c_str(), nowaNazwa.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << staraNazwa << endl;
}



