#pragma once

#include <cmath>

class Complex {
     double a, b;
        const double i=sqrt(-1);
        void Cin() {
            std::cin >> a >> b;
        }
        double z = a + b * i;
        Complex(const Complex&);
        Complex& operator=(const Complex&);
        Complex operator+(const Complex&) const;
        Complex operator+=(const Complex&) const;
        Complex operator-(const Complex&) const;
        Complex operator-=(const Complex&) const;
        double operator *(const Complex&) const;
        bool operator == (const Complex&) const;
        bool operator != (const Complex&) const;
        Complex operator*(double) const;
        friend Complex operator *=(double, const Complex&);
        Complex operator/ (double) const;
        friend Complex operator /=(double, const Complex&);
        Complex operator–() const;
        double Real = a;
        double Imag = b;
        double Abs = sqrt(a*a+b*b);
        void Cout() {
            std::cout << "z = "<<a <<' + ' << b << 'i ' << Real << ' ' << Imag << ' ' << Abs;
        }
};
