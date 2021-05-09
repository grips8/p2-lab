#include <iostream>
#ifndef P2_LAB_PILOT_H
#define P2_LAB_PILOT_H


class Pilot {
private:
    std::string name;
    std::string surname;
    int year_of_birth;
    std::string nationality;
    int age;
    friend std::ostream& operator<<(std::ostream &, const Pilot &);
public:
    Pilot(std::string, std::string, int, std::string);
    Pilot(std::string, std::string, int);
    std::string get_name() const;
    std::string get_surname() const;
    int get_year_of_birth() const;
    int get_age() const;
    std::string get_nationality() const;
    void set_name(std::string);
    void set_nationality(std::string);
};


#endif //P2_LAB_PILOT_H
