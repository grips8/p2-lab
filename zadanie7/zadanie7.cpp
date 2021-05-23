#include <iostream>
#include <iomanip>

class Macierz2D {
private:
    float **data;
//    friend Macierz2D operator+(const Macierz2D &, const Macierz2D &);
public:
    Macierz2D();
    Macierz2D(float);
    Macierz2D(float [3][3]);
    Macierz2D(const Macierz2D &);
    ~Macierz2D();
    Macierz2D &operator=(const Macierz2D &);
    Macierz2D &operator+=(const Macierz2D &);
    Macierz2D &operator-=(const Macierz2D &);
    Macierz2D &operator*=(int);
    Macierz2D &operator*=(const Macierz2D &);
    Macierz2D &operator++();
    Macierz2D operator++(int);
    Macierz2D &operator--();
    Macierz2D operator--(int);
    void transpose();
    void turnIntoIdentity();
    void set11(float);
    void set12(float);
    void set13(float);
    void set21(float);
    void set22(float);
    void set23(float);
    void set31(float);
    void set32(float);
    void set33(float);
    float get11() const;
    float get12() const;
    float get13() const;
    float get21() const;
    float get22() const;
    float get23() const;
    float get31() const;
    float get32() const;
    float get33() const;
};

Macierz2D::Macierz2D() {
    data = new float *[3];
    for (int i = 0; i < 3; i++) {
        *(data + i) = new float[3];
        for (int j = 0; j < 3; j++) {
            *(*(data + i) + j) = 0;
        }
    }
}

Macierz2D::Macierz2D(float x) {
    data = new float *[3];
    for (int i = 0; i < 3; i++) {
        *(data + i) = new float[3];
        for (int j = 0; j < 3; j++) {
            *(*(data + i) + j) = x;
        }
    }
}

Macierz2D::Macierz2D(float a[3][3]) {
    data = new float *[3];
    for (int i = 0; i < 3; i++) {
        *(data + i) = new float[3];
        for (int j = 0; j < 3; j++) {
            *(*(data + i) + j) = a[i][j];
        }
    }
}

Macierz2D::Macierz2D(const Macierz2D &other) {
    // poniewaz copy constructor jest wywolywany przy niezainicjalizowanym obiekcie, musimy przydzielic pamiec
    data = new float *[3];
    for (int i = 0; i < 3; i++) {
        *(data + i) = new float[3];
        for (int j = 0; j < 3; j++) {
            *(*(data + i) + j) = *(*(other.data + i) + j);
        }
    }
}

Macierz2D &Macierz2D::operator=(const Macierz2D &other) {
    // poniewaz assignment operator moze byc uzyty tylko przy zainicjalizowanych obiektach, mozemy po prostu skopiowac wartosci
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            *(*(data + i) + j) = *(*(other.data + i) + j);
        }
    }
    return *this;
}

Macierz2D::~Macierz2D() {
    for (int i = 0; i < 3; i++) {
        delete[]*(data + i);
    }
    delete[]data;
}

void Macierz2D::set11(float x) { *(*(data + 0) + 0) = x; }
void Macierz2D::set12(float x) { *(*(data + 0) + 1) = x; }
void Macierz2D::set13(float x) { *(*(data + 0) + 2) = x; }
void Macierz2D::set21(float x) { *(*(data + 1) + 0) = x; }
void Macierz2D::set22(float x) { *(*(data + 1) + 1) = x; }
void Macierz2D::set23(float x) { *(*(data + 1) + 2) = x; }
void Macierz2D::set31(float x) { *(*(data + 2) + 0) = x; }
void Macierz2D::set32(float x) { *(*(data + 2) + 1) = x; }
void Macierz2D::set33(float x) { *(*(data + 2) + 2) = x; }
float Macierz2D::get11() const { return *(*(data + 0) + 0); }
float Macierz2D::get12() const { return *(*(data + 0) + 1); }
float Macierz2D::get13() const { return *(*(data + 0) + 2); }
float Macierz2D::get21() const { return *(*(data + 1) + 0); }
float Macierz2D::get22() const { return *(*(data + 1) + 1); }
float Macierz2D::get23() const { return *(*(data + 1) + 2); }
float Macierz2D::get31() const { return *(*(data + 2) + 0); }
float Macierz2D::get32() const { return *(*(data + 2) + 1); }
float Macierz2D::get33() const { return *(*(data + 2) + 2); }

Macierz2D operator+(const Macierz2D &first, const Macierz2D &second) {
    Macierz2D res;
    res.set11(first.get11() + second.get11());
    res.set12(first.get12() + second.get12());
    res.set13(first.get13() + second.get13());
    res.set21(first.get21() + second.get21());
    res.set22(first.get22() + second.get22());
    res.set23(first.get23() + second.get23());
    res.set31(first.get31() + second.get31());
    res.set32(first.get32() + second.get32());
    res.set33(first.get33() + second.get33());
    return res;
}

Macierz2D &Macierz2D::operator+=(const Macierz2D &other) {
    *this = *this + other;
    return *this;
}

Macierz2D operator*(const Macierz2D &first, const int x) {
    Macierz2D res;
    res.set11(first.get11() * x);
    res.set12(first.get12() * x);
    res.set13(first.get13() * x);
    res.set21(first.get21() * x);
    res.set22(first.get22() * x);
    res.set23(first.get23() * x);
    res.set31(first.get31() * x);
    res.set32(first.get32() * x);
    res.set33(first.get33() * x);
    return res;
}

Macierz2D operator-(const Macierz2D &first, const Macierz2D &second) {
    Macierz2D res;
    res = first + (second * (-1));
    return res;
}

Macierz2D &Macierz2D::operator-=(const Macierz2D &other) {
    *this = *this - other;
    return *this;
}

Macierz2D &Macierz2D::operator++() {        // pre
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            *(*(data + i) + j) += 1;
        }
    }
    return *this;
}

Macierz2D Macierz2D::operator++(int) {        // post
    Macierz2D dummy = *this;        // wywolanie konstruktora kopiujacego, zatem czy po zwroceniu dummy nie wystapi memory leak?
    operator++();
    return dummy;
}

Macierz2D &Macierz2D::operator--() {        // pre
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            *(*(data + i) + j) -= 1;
        }
    }
    return *this;
}

Macierz2D Macierz2D::operator--(int) {        // post
    Macierz2D dummy = *this;        // wywolanie konstruktora kopiujacego, zatem czy po zwroceniu dummy nie wystapi memory leak?
    operator--();
    return dummy;
}

Macierz2D &Macierz2D::operator*=(const int x) {
    *this = *this * x;
    return *this;
}

Macierz2D operator*(const Macierz2D &first, const Macierz2D &second) {
    Macierz2D res;
    res.set11((first.get11() * second.get11()) + (first.get12() * second.get21()) + (first.get13() * second.get31()));
    res.set12((first.get11() * second.get12()) + (first.get12() * second.get22()) + (first.get13() * second.get32()));
    res.set13((first.get11() * second.get13()) + (first.get12() * second.get23()) + (first.get13() * second.get33()));
    res.set21((first.get21() * second.get11()) + (first.get22() * second.get21()) + (first.get23() * second.get31()));
    res.set22((first.get21() * second.get12()) + (first.get22() * second.get22()) + (first.get23() * second.get32()));
    res.set23((first.get21() * second.get13()) + (first.get22() * second.get23()) + (first.get23() * second.get33()));
    res.set31((first.get31() * second.get11()) + (first.get32() * second.get21()) + (first.get33() * second.get31()));
    res.set32((first.get31() * second.get12()) + (first.get32() * second.get22()) + (first.get33() * second.get32()));
    res.set33((first.get31() * second.get13()) + (first.get32() * second.get23()) + (first.get33() * second.get33()));
    return res;
}

Macierz2D &Macierz2D::operator*=(const Macierz2D &other) {
    *this = *this * other;
    return *this;
}

std::ostream &operator<<(std::ostream &stream, const Macierz2D &matrix) {
    stream << "|" << std::setw(10) << std::setprecision(7) << matrix.get11()
            << std::setw(10) << std::setprecision(7) << matrix.get12()
            << std::setw(10) << std::setprecision(7) << matrix.get13() << " |\n"
            << "|" << std::setw(10) << std::setprecision(7) << matrix.get21()
            << std::setw(10) << std::setprecision(7) << matrix.get22()
            << std::setw(10) << std::setprecision(7) << matrix.get23() << " |\n"
            << "|" << std::setw(10) << std::setprecision(7) << matrix.get31()
            << std::setw(10) << std::setprecision(7) << matrix.get32()
            << std::setw(10) << std::setprecision(7) << matrix.get33() << " |\n\n";
    return stream;
}

std::istream &operator>>(std::istream &stream, Macierz2D &matrix) {
    float x;
    std::cout << "Podaj element 1,1: ";
    stream >> x;
    matrix.set11(x);
    std::cout << "Podaj element 1,2: ";
    stream >> x;
    matrix.set12(x);
    std::cout << "Podaj element 1,3: ";
    stream >> x;
    matrix.set13(x);
    std::cout << "Podaj element 2,1: ";
    stream >> x;
    matrix.set21(x);
    std::cout << "Podaj element 2,2: ";
    stream >> x;
    matrix.set22(x);
    std::cout << "Podaj element 2,3: ";
    stream >> x;
    matrix.set23(x);
    std::cout << "Podaj element 3,1: ";
    stream >> x;
    matrix.set31(x);
    std::cout << "Podaj element 3,2: ";
    stream >> x;
    matrix.set32(x);
    std::cout << "Podaj element 3,3: ";
    stream >> x;
    matrix.set33(x);
    return stream;
}

void Macierz2D::transpose() {
    float tmp;
    tmp = get12();
    set12(get21());
    set21(tmp);
    tmp = get13();
    set13(get31());
    set31(tmp);
    tmp = get32();
    set32(get23());
    set23(tmp);
}

void Macierz2D::turnIntoIdentity() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) {
                *(*(data + i) + j) = 1;
            }
            else {
                *(*(data + i) + j) = 0;
            }
        }
    }
}

int zadanie7_main() {
    Macierz2D *test = new Macierz2D(3.125678);
    std::cout << ((*test)*=5) << *test;
    return 0;
}