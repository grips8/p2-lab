#include "Pilot.h"

Pilot::Pilot(std::string name, std::string surname, int year, std::string nationality) : name(name), surname(surname), year_of_birth(year), nationality(nationality) {
    this->age = 2021 - year;
}

Pilot::Pilot(std::string name, std::string surname, int year) : name(name), surname(surname), year_of_birth(year) {
    this->nationality = "USA";
    this->age = 2021 - year;
}

std::string Pilot::get_name() const {
    return this->name;
}

std::string Pilot::get_surname() const {
    return this->surname;
}

int Pilot::get_year_of_birth() const {
    return this->year_of_birth;
}

int Pilot::get_age() const {
    return this->age;
}

std::string Pilot::get_nationality() const {
    return this->nationality;
}

std::ostream &operator<<(std::ostream &stream, const Pilot &pilot) {
    stream << "Name: " << pilot.name << "\nSurname: " << pilot.surname << "\nAge: " << pilot.age << "\nNationality: " << pilot.nationality;
    return stream;
}

void Pilot::set_name(std::string name) {
    this->name = name;
}

void Pilot::set_nationality(std::string nat) {
    this->nationality = nat;
}

