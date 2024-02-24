#ifndef PLIKTEKSTOWY_H
#define PLIKTEKSTOWY_H

#include <iostream>
#include <fstream>

using namespace std;

class PlikTekstowy {

    const string NAZWA_PLIKU;
    const string NAZWA_PLIKU_TYMCZASOWEGO;

public:

    PlikTekstowy(string nazwaPliku, string nazwaPlikuTymczasowego) : NAZWA_PLIKU(nazwaPliku), NAZWA_PLIKU_TYMCZASOWEGO(nazwaPlikuTymczasowego) {
    }

    string pobierzNazwePliku()
    {
        return NAZWA_PLIKU;
    }

    string pobierzNazwePlikuTymczasowego()
    {
        return NAZWA_PLIKU_TYMCZASOWEGO;
    }

    bool czyPlikJestPusty()
    {
        bool pusty = true;
        fstream plikTekstowy;
        plikTekstowy.open(pobierzNazwePliku().c_str(), ios::app);

        if (plikTekstowy.good() == true)
        {
            plikTekstowy.seekg(0, ios::end);
            if (plikTekstowy.tellg() != 0)
                pusty = false;
        }

        plikTekstowy.close();
        return pusty;
    }
};

#endif // PLIKTEKSTOWY_H
