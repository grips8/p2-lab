// zadanie 1

void NazwiskaString ()
{
    const int n = 5;                      // Liczba nazwisk


    std::string myTab[n];       // Tworzenie tablicy o wielkosci n

    // ---------- Wprowadzanie nazwisk do stringow ------------
    for (int i = 0; i < n; i++) {
        std::cout << "Podaj nazwisko nr " << (i + 1) << std::endl;
        std::cin >> myTab[i];
    }

    // -------- Sprawdzanie dlugosci stringow -----------
    for (int j = 0; j < n; j++) {
        std::cout << "Dlugosc nazwiska nr " << (j + 1) << std::endl;
        std::cout << myTab[j].length() << std::endl;
    }
}

void NazwiskaChar ()
{
    const int n = 5;              // Liczba nazwisk

    char *surTab[n];    // Tworzenie tablicy wskaznikow do tablic charow o wielkosci n
    for (int i = 0; i < n; i++) {
        char *tmpSur = new char[128];       // tymczasowa pomocnicza tablica znakow
        std::cout << "Podaj nazwisko nr " << (i + 1) << std::endl;
        std::cin >> tmpSur;

        // ----------- Wyznaczanie dlugosci wprowadzonego nazwiska --------------
        int x = 0;
        while (tmpSur[x] != '\0') {
            x++;
        }

        surTab[i] = new char[x + 1];        // Tworzenie dynamicznej tablicy o wielkosci x + 1 (nazwisko + '\0')

        // ------------ Przenoszenie wartosci z tymczasowej tablicy do wlasciwej ----------------
        for (int m = 0; m < x; m++) {
            surTab[i][m] = tmpSur[m];
        }
        surTab[i][x] = '\0';                // Koniec tablicy

        delete [] tmpSur;                   // Zwalnianie pamieci z tymczasowej tablicy
    }

    // ----------- Sprawdzanie dlugosci tablic char -----------
    for (int j = 0; j < n; j++) {
        int k = 0;
        while (*(surTab[j] + k) != '\0') {
            k++;
        }
        k++;                // dodanie 1 miejsca na '\0'
        std::cout << "Nazwisko: " << surTab[j] << std::endl;
        std::cout << "dlugosc nazwiska: " << k << std::endl << std::endl;
    }

    // -------------- Zwalnianie pamieci -------------
    for (int y = 0; y < n; y++) {
        delete [] surTab [y];
        surTab[y] = nullptr;
    }

}