#ifndef P2_LAB_AIRCRAFT_H
#define P2_LAB_AIRCRAFT_H
#include "Pilot.h"

class Aircraft {
protected:
    Pilot* pilot;
private:
    int id;
    static int current_id;
    std::string model;
    std::string manufacturer;
    int year_of_production;
    int fuel;
    void set_id();
    friend std::ostream& operator<<(std::ostream &, const Aircraft &);
public:
    Aircraft();
    Aircraft(std::string, std::string, int, std::string, std::string, std::string, int, int);
    virtual int calculate_range() const;
    int get_id() const;
    int get_fuel() const;
    void set_fuel(int);
    Pilot *get_pilot() const;
    static int static_get_current_id() ;
    Aircraft(const Aircraft &);
    ~Aircraft();
};


#endif //P2_LAB_AIRCRAFT_H
