#include "Aircraft.h"
int Aircraft::current_id = 0;

int Aircraft::static_get_current_id() {
    return Aircraft::current_id;
}

void Aircraft::set_id() {
    this->id = Aircraft::current_id++;
}

Aircraft::Aircraft() : pilot(new Pilot("John", "Doe", 1976)), model("977"), manufacturer("Boeing"), year_of_production(1970), fuel(4720) {
    this->set_id();
}

Aircraft::Aircraft(std::string p_name, std::string p_surname, int p_year, std::string p_nationality, std::string model, std::string manufacturer, int year, int fuel)
: pilot(new Pilot(p_name, p_surname, p_year, p_nationality)), model(model), manufacturer(manufacturer), year_of_production(year), fuel(fuel) {
    this->set_id();
}

int Aircraft::calculate_range() const {
    return 17 * this->fuel;
}

int Aircraft::get_id() const {
    return this->id;
}

int Aircraft::get_fuel() const {
    return this->fuel;
}

void Aircraft::set_fuel(int fuel) {
    this->fuel = fuel;
}

Pilot *Aircraft::get_pilot() const {
    return this->pilot;
}

Aircraft::Aircraft(const Aircraft &other) : model(other.model), manufacturer(other.manufacturer), year_of_production(other.year_of_production), fuel(other.fuel) {
    this->pilot = new Pilot(other.pilot->get_name(), other.pilot->get_surname(), other.pilot->get_year_of_birth(), other.pilot->get_nationality());
    this->set_id();
}

std::ostream &operator<<(std::ostream &stream, const Aircraft &aircraft) {
    stream << "Id: " << aircraft.id << "\nModel: " << aircraft.model << "\nManufacturer: " << aircraft.manufacturer
            << "\nYear of Production: " << aircraft.year_of_production << "\nFuel: " << aircraft.fuel  << "\nAircraft pilot: \n" << *(aircraft.pilot);
    return stream;
}

Aircraft::~Aircraft() {
    delete this->pilot;
}














