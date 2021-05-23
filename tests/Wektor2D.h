#ifndef P2_LAB_WEKTOR2D_H
#define P2_LAB_WEKTOR2D_H

#include <iostream>

class Wektor2D {
private:
    static const int m_rozmiar = 3;
    float m_dane[m_rozmiar];
    friend std::ostream &operator<<(std::ostream &, const Wektor2D &);
    friend std::istream &operator>>(std::istream &, Wektor2D &);
    friend bool operator==(const Wektor2D &, const Wektor2D &);
    friend bool operator!=(const Wektor2D &, const Wektor2D &);
    friend bool operator<(const Wektor2D &, const Wektor2D &);
    friend bool operator>(const Wektor2D &, const Wektor2D &);
    friend bool operator<=(const Wektor2D &, const Wektor2D &);
    friend bool operator>=(const Wektor2D &, const Wektor2D &);
public:
    Wektor2D(float x = 0, float y = 0, float z = 0);
    bool operator==(Wektor2D &);
    bool operator!=(Wektor2D &);
    bool operator<(Wektor2D &);
    bool operator>(Wektor2D &);
    bool operator<=(Wektor2D &);
    bool operator>=(Wektor2D &);
    static int get_rozmiar();
    float get_x() const;
    void set_x(float x);
    float get_y() const;
    void set_y(float y);
    float get_z() const;
    void set_z(float z);
};


#endif //P2_LAB_WEKTOR2D_H
