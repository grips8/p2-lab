#include <iostream>
#include "Pilot.h"
#include "Aircraft.h"
#include "MilitaryAircraft.h"

int zadanie6_maine () {
    // przeciazenie konstruktora
    {
        Pilot *pilot1 = new Pilot("Marek", "Nowak", 1977, "Poland");
        Pilot *pilot2 = new Pilot("John", "Doe", 1967);
        std::cout << "Pilot 1:\n" << *pilot1 << "Pilot 2:\n" << *pilot2;
        delete pilot1;
        delete pilot2;
        std::cout << "\n\n";
    }
    // zmienna mutable (zmieniana przy funkcji const)
    {
        MilitaryAircraft *ma = new MilitaryAircraft("Jet", "Multirole");
        std::cout << "Zmienna mutable przed wywolaniami: " << ma->get_number_of_get_role_calls() << "\n";
        ma->get_role();
        ma->get_role();
        ma->get_role();
        std::cout << "Zmienna mutable po wywolaniach: " << ma->get_number_of_get_role_calls() << "\n";
        delete ma;
        std::cout << "\n\n";
    }
    // Destruktor klasy Aircraft usuwa takze obiekt Pilota, na ktore wskazuje jego pole
    {
        Aircraft *air = new Aircraft("Jan", "Nowak", 1979, "Poland", "737MAX", "Boeing", 2001, 21000);
        Pilot *tmp;
        tmp = air->get_pilot();
        delete air;
//        std::cout << tmp->get_nationality();       // powinno wyrzucic blad
    }
    // konstruktor kopiujacy, tworzacy nowy obiekt pilota dla skopiowanego Aircraft + zmienna statyczna w klasie liczaca kolejne id
    {
        Aircraft *air = new Aircraft("Jan", "Nowak", 1979, "Poland", "737MAX", "Boeing", 2001, 21000);
        Aircraft *secondAir = new Aircraft(*air);
        secondAir->get_pilot()->set_name("Marek");
        std::cout << "Aircraft 1: \n" << *air << "\n\nAircraft 2: \n" << *secondAir << "\n\n";
        delete air;
        delete secondAir;
    }
    // dziedziczenie metody (get_fuel() nalezy do Aircraft)
    {
        MilitaryAircraft *ma = new MilitaryAircraft("Kamil", "Kowalski", 1985, "Denmark", "F-15C Eagle", "McDonnell Douglas", 1980, 15000, "Jet", "Air superiority");
        std::cout << "Fuel: " << ma->get_fuel() << "\n\n\n";
        delete ma;
    }
    // nadpisanie metody (metoda virtual w Aircraft)
    {
        int SAMEFUEL = 15000;
        Aircraft *air = new Aircraft("David", "Smiths", 1970, "USA", "737Max", "Boeing", 1999, SAMEFUEL);
        MilitaryAircraft *ma = new MilitaryAircraft("Kamil", "Kowalski", 1985, "Denmark", "F-15C Eagle", "McDonnell Douglas", 1980, SAMEFUEL, "Jet", "Air superiority");
        std::cout << "Range dla Aircraft i MilitaryAircraft o tych samych wartosciach fuel: \nAircraft: " << air->calculate_range() << "\nMilitaryAircraft: " << ma->calculate_range();
        std::cout << "\n\n";
        delete air;
        delete ma;
    }
    // pilot jako pole Protected (Military Aircraft ma do niego dostep)
    {
        MilitaryAircraft *ma = new MilitaryAircraft("Jet", "Air superiority");
        ma->set_nationality("Sweden");
        delete ma;
    }

    return 0;
}