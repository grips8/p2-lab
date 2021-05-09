#include "MilitaryAircraft.h"

MilitaryAircraft::MilitaryAircraft(std::string classo, std::string role) : Aircraft(), class_of_aircraft(classo), role(role) {

}


MilitaryAircraft::MilitaryAircraft(std::string p_name, std::string p_surname, int p_year, std::string p_nationality, std::string model,
                                   std::string manufacturer, int year, int fuel, std::string classo, std::string role)
        : Aircraft(p_name, p_surname, p_year, p_nationality, model, manufacturer, year, fuel), class_of_aircraft(classo), role(role) {

}

std::string MilitaryAircraft::get_role() const {
    this->number_of_get_role_calls++;
    return this->role;
}

int MilitaryAircraft::calculate_range() const {
    return 34 * this->get_fuel();
}



int MilitaryAircraft::get_number_of_get_role_calls() const {
    return this->number_of_get_role_calls;
}

void MilitaryAircraft::set_nationality(std::string nat) {
    this->pilot->set_nationality(nat);
}

