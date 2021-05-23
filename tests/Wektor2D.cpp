#include "Wektor2D.h"

// Konstruktor implementacja.
Wektor2D::Wektor2D(float x, float y, float z) : m_dane{x, y, z} {}

int Wektor2D::get_rozmiar() { return m_rozmiar; }

float Wektor2D::get_x() const { return m_dane[0]; }

void Wektor2D::set_x(float x) { m_dane[0] = x; }

float Wektor2D::get_y() const { return m_dane[1]; }

void Wektor2D::set_y(float y) { m_dane[1] = y; }

float Wektor2D::get_z() const { return m_dane[2]; }

void Wektor2D::set_z(float z) { m_dane[2] = z; }

std::istream &operator>>(std::istream &stream, Wektor2D &wektor) {
    float x, y, z;
    std::cout << "x:";
    stream >> x;
    wektor.m_dane[0] = x;
    std::cout << "y:";
    stream >> y;
    wektor.m_dane[1] = y;
    std::cout << "z:";
    stream >> z;
    wektor.m_dane[2] = z;


    return stream;
}

Wektor2D operator*(const Wektor2D &wektor1, const Wektor2D &wektor2) {
    Wektor2D wektor_wynik;

    std::cout << "wektor1 x: " << wektor1.get_x() << std::endl;
    std::cout << "wektor2 x: " << wektor2.get_x() << std::endl;
    std::cout << "wektor1 y: " << wektor1.get_y() << std::endl;
    std::cout << "wektor2 y: " << wektor2.get_y() << std::endl;
    std::cout << "wektor1 z: " << wektor1.get_z() << std::endl;
    std::cout << "wektor2 z: " << wektor2.get_z() << std::endl;
    std::cout << "Po przeliczeniu podaj otrzymany wektor: ";
    std::cin >> wektor_wynik;

    return wektor_wynik;
}

Wektor2D operator+(const Wektor2D &wektor1, const Wektor2D &wektor2) {
    Wektor2D wektor_wynik;

    wektor_wynik.set_x(wektor1.get_x() + wektor2.get_x());
    wektor_wynik.set_y(wektor1.get_y() + wektor2.get_y());
    wektor_wynik.set_z(wektor1.get_z() + wektor2.get_z());

    return wektor_wynik;
}

std::ostream &operator<<(std::ostream &stream, const Wektor2D &wektor) {
    stream << "[x=" << wektor.m_dane[0] << ", y=" << wektor.m_dane[1] << ", z=" << wektor.m_dane[2] << "]\n";
    return stream;
}

bool operator==(const Wektor2D &wektor1, const Wektor2D &wektor2) {
    return (wektor1.get_x() == wektor2.get_x() && wektor1.get_y() == wektor2.get_y() &&
            wektor1.get_z() == wektor2.get_z());
}

bool Wektor2D::operator==(Wektor2D &wektor2) {
    return (this->m_dane[0] == wektor2.get_x() && this->m_dane[1] == wektor2.get_y() &&
            this->m_dane[2] == wektor2.get_z());

}

bool operator!=(const Wektor2D &wektor1, const Wektor2D &wektor2) {
    return !(wektor1.get_x() == wektor2.get_x() && wektor1.get_y() == wektor2.get_y() &&
             wektor1.get_z() == wektor2.get_z());
//    return !(wektor1==wektor2);
}

bool Wektor2D::operator!=(Wektor2D &wektor2) {
    return !(this->m_dane[0] == wektor2.get_x() && this->m_dane[1] == wektor2.get_y() &&
             this->m_dane[2] == wektor2.get_z());
//    return !this->operator==(wektor2);
}

bool operator<(const Wektor2D &wektor1, const Wektor2D &wektor2) {
    return (wektor1.get_x() < wektor2.get_x() && wektor1.get_y() < wektor2.get_y() &&
            wektor1.get_z() < wektor2.get_z());
}

bool Wektor2D::operator<(Wektor2D &wektor2) {
    return (this->m_dane[0] < wektor2.get_x() && this->m_dane[1] < wektor2.get_y() &&
            this->m_dane[2] < wektor2.get_z());
}

bool operator>(const Wektor2D &wektor1, const Wektor2D &wektor2) {
    return (wektor1.get_x() > wektor2.get_x() && wektor1.get_y() > wektor2.get_y() &&
            wektor1.get_z() > wektor2.get_z());
}

bool Wektor2D::operator>(Wektor2D &wektor2) {
    return (this->m_dane[0] > wektor2.get_x() && this->m_dane[1] > wektor2.get_y() &&
            this->m_dane[2] > wektor2.get_z());
}

bool operator>=(const Wektor2D &wektor1, const Wektor2D &wektor2) {
    return !(wektor1 < wektor2);
}

bool Wektor2D::operator>=(Wektor2D &wektor2) {
    return !(this->operator<(wektor2));
}

bool operator<=(const Wektor2D &wektor1, const Wektor2D &wektor2) {
    return !(wektor1 > wektor2);
}

bool Wektor2D::operator<=(Wektor2D &wektor2) {
    return !(this->operator>(wektor2));
}


