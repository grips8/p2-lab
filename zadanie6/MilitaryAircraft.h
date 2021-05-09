#ifndef P2_LAB_MILITARYAIRCRAFT_H
#define P2_LAB_MILITARYAIRCRAFT_H


#include <iostream>
#include "Aircraft.h"

class MilitaryAircraft: public Aircraft {
private:
    mutable int number_of_get_role_calls = 0;
    std::string class_of_aircraft;
    std::string role;

public:
    MilitaryAircraft(std::string, std::string);
    MilitaryAircraft(std::string, std::string, int, std::string, std::string, std::string, int, int, std::string, std::string);
    std::string get_role() const;
    int get_number_of_get_role_calls() const;
    int calculate_range() const;
    void set_nationality(std::string);
};


#endif //P2_LAB_MILITARYAIRCRAFT_H
