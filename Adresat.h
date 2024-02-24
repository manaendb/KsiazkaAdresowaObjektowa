#ifndef ADRESAT_H
#define ADRESAT_H

#include <iostream>

using namespace std;

class Adresat
{
    int id;
    int idUzytkownika;
    string imie;
    string nazwisko;
    string numerTelefonu;
    string email;
    string adres;

public:
    Adresat(int id = 0, int idUzytkownika = 0, string imie = "", string nazwisko = "", string numerTelefonu = "", string email = "",string adres = "") //gdyby nie bylo wskaznika this, to trzeba by bylo - Adresat(int idNowe=0, nie id = 0
    // Jesli ktos stworzy obiekt adresat bez parametrow, to wtedy program wykorzystuje wartosci podane przez nas powyzej
    {
        this->id = id;                                //wskaznik this -> wskazuje na skladowe danej klasy
        this->idUzytkownika = idUzytkownika;
        this->imie = imie;
        this->nazwisko = nazwisko;
        this->numerTelefonu = numerTelefonu;
        this->email = email;
        this->adres = adres;
    }
    void ustawId(int noweId);
    void ustawIdUzytkownika(int noweIdUzytkownika);
    void ustawImie(string noweImie);
    void ustawNazwisko(string noweNazwisko);
    void ustawNumerTelefonu(string nowyNumerTelefonu);
    void ustawEmail(string nowyEmail);
    void ustawAdres(string nowyAdres);

    int pobierzId();
    int pobierzIdUzytkownika();
    string pobierzImie();
    string pobierzNazwisko();
    string pobierzNumerTelefonu();
    string pobierzEmail();
    string pobierzAdres();
};

#endif // ADRESAT_H
