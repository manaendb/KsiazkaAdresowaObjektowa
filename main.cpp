#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;


int main()
{
    char wybor = '0';
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt"); //dopisanie nazwy pliku przy tworzeniu ksiazki adresowej

    //ksiazkaAdresowa.czyUzytkownikJestZalogowany(); //zamiast sprawdzania czy IdZalogowanegoUzytkownika = 0

    while (true)
    {
        if (ksiazkaAdresowa.czyUzytkownikJestZalogowany() == false)
        {
            wybor = MetodyPomocniczne::wybierzOpcjeZMenuGlownego();

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                ksiazkaAdresowa.logowanieUzytkownika();
                break;
            case '3':
                ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            wybor = MetodyPomocniczne::wybierzOpcjeZMenuUzytkownika();

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.dodajAdresata();;
                break;
            case '2':
                ksiazkaAdresowa.wyszukajAdresatowPoImieniu();
                break;
            case '3':
                ksiazkaAdresowa.wyszukajAdresatowPoNazwisku();
                break;
            case '4':
                ksiazkaAdresowa.wypiszWszystkichAdresatow();
                break;
            case '5':
                ksiazkaAdresowa.usunAdresata();
                break;
            case '6':
                ksiazkaAdresowa.edycjaAdresata();
                break;
            case '7':
                ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownia();
                break;
            case '8':
                ksiazkaAdresowa.wylogowanieUzytkownika();
                break;
            }
        }
    }

    /*ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownia();
    ksiazkaAdresowa.wypiszWszystkichAdresatow();
    //ksiazkaAdresowa.dodajAdresata();
    ksiazkaAdresowa.wylogowanieUzytkownika();
    ksiazkaAdresowa.wypiszWszystkichAdresatow();
    //ksiazkaAdresowa.rejestracjaUzytkownika();
    //ksiazkaAdresowa.rejestracjaUzytkownika();
    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();*/

    return 0;
}


/*
//TESTY AdresatMenedzer <<<<<<TESTOWANIE POSZCZEGOLNYCH OBIEKTOW BEZ WYWOLYWANIA WCZESNIEJSZYCH>>>>>>>>
#include "AdresatMenedzer.h"
int testAdresatMen_main() //trzeba tylko zamienic literki na main() i zmienic we wlasciwyn main() literki na np. _main()
{
    AdresatMenedzer adresatMenedzer("Adresaci.txt",2);
    adresatMenedzer.wyswietlWszystkichAdresatow();
    adresatMenedzer.dodajAdresata();
    adresatMenedzer.wyswietlWszystkichAdresatow();
}

//TESTY PlikZAdresatami
#include "Adresat.h"
#include "PlikZadresatami.h"

int testPlikA_main()
{
    PlikZAdresatami plikZAdresatami("Adresaci-test.txt");
    Adresat adresat(1,9,"Janek","Twardowski","999 888 333","janek@o2.pl","ul. Jankowa 3a"); //tutaj Artur stworzyl konstruktor dla tej klasy zeby na sztywno ustawic wszystkie elementy klasy

    plikZAdresatami.dopiszAdresataDoPliku(adresat);

    cout << plikZAdresatami.pobierzIdOstatniegoAdresata();
}

//W razie problemow z metoda prywatna - mozna na czas testow uczynic ja publiczna zeby na sucho sprawdzic ja.*/
