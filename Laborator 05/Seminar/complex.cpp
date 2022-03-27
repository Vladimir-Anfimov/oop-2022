#include "complex.h"

Complex::Complex() : Complex(0, 0) {}

Complex::Complex(double real, double imag) {
    real_data = real;
    imag_data = imag;
}

bool Complex::is_real() const {
    return imag() == 0;
}

double Complex::real() const {
    return real_data;
}

double Complex::imag() const {
    return imag_data;
}

double Complex::abs() const {
    return sqrt(real() * real() + imag() * imag());
}

Complex Complex::conjugate() const {
    return { real(), -imag() };
}

Complex& Complex::operator()(double real, double imag) {
    this->real_data = real;
    this->imag_data = imag;

    return *this;
}



Complex operator+(const Complex& l, const Complex& r) {
    return { 
        l.real() + r.real(), 
        l.imag() + r.imag()
    };
}

Complex operator+(const Complex& l, double r) {
    return l + Complex{ r, 0 };
}

Complex operator+(double l, const Complex& r) {
    return Complex{l, 0} + r;
}




Complex operator-(const Complex& obj) {
    return Complex{ -obj.real(), -obj.imag() };
}

Complex operator-(const Complex& l, const Complex& r) {
    return l + (-r);
}

Complex operator-(const Complex& l, double r) {
    return l - Complex{ r, 0 };
}

Complex operator-(double l, const Complex& r) {
    return Complex{ l, 0 } - r;
}



Complex operator*(const Complex& l, const Complex& r) {
    return { 
        l.real() * r.real() - l.imag() * r.imag(),
        l.real() * r.imag() + r.real() * l.imag()
    };
}

Complex operator*(const Complex& l, double r) {
    return l * Complex{ r, 0 };
}

Complex operator*(double l, const Complex& r) {
    return Complex{ l, 0 } * r;
}



// PREFIXAT
Complex& Complex::operator++() {
    this->real_data++;
    return *this;
}

//POSTFIXAT
Complex Complex::operator++(int) {
    Complex copy = { this->real_data, this->imag_data };
    ++(*this);
    return copy;
}



// PREFIXAT
Complex& Complex::operator--() {
    this->real_data--;
    return *this;
}

// POSTFIXAT
Complex Complex::operator--(int) {
    Complex copy = { this->real_data, this->imag_data };
    --(*this);
    return copy;
}



bool operator==(const Complex& l, const Complex& r) {
    return l.real() == r.real() && l.imag() == r.imag();
}

bool operator!=(const Complex& l, const Complex& r) {
    return !(l == r);
}




std::ostream& operator<<(std::ostream& out, const Complex& complex) {
    out << complex.real() << " " << complex.imag() << "\n";
    return out;
}
