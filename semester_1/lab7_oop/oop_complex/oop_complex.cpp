#include "oop_complex.h"

#include <cmath>
#include <iostream>

    class Complex {
        double a;
        double b;

    public:
        
        Complex() : a(0.0), b(0.0) {}                 
        explicit Complex(double x) : a(x), b(0.0) {}  
        Complex(double x, double y) : a(x), b(y) {}  
        Complex(const Complex& other) : a(other.a), b(other.b) {} 

        
        Complex& operator=(const Complex& other) {
            if (this != &other) {
                a = other.a;
                b = other.b;
            }
            return *this;
        }

        
        bool operator==(const Complex& other) const {
            return a == other.a && b == other.b;
        }
        bool operator!=(const Complex& other) const {
            return !(*this == other);
        }

        
        Complex operator+() const { return *this; }
        Complex operator-() const { return Complex(-a, -b); }

       
        Complex operator+(const Complex& r) const { return Complex(a + r.a, b + r.b); }
        Complex operator-(const Complex& r) const { return Complex(a - r.a, b - r.b); }
        Complex operator*(const Complex& r) const {
            return Complex(a * r.a - b * r.b, a * r.b + b * r.a);
        }
        Complex operator/(const Complex& r) const {
            double d = r.a * r.a + r.b * r.b;
            return Complex((a * r.a + b * r.b) / d,
                (b * r.a - a * r.b) / d);
        }

        
        Complex operator+(double x) const { return Complex(a + x, b); }
        Complex operator-(double x) const { return Complex(a - x, b); }
        Complex operator*(double x) const { return Complex(a * x, b * x); }
        Complex operator/(double x) const { return Complex(a / x, b / x); }

        
        Complex& operator+=(const Complex& r) { a += r.a; b += r.b; return *this; }
        Complex& operator-=(const Complex& r) { a -= r.a; b -= r.b; return *this; }
        Complex& operator*=(const Complex& r) { *this = *this * r; return *this; }
        Complex& operator/=(const Complex& r) { *this = *this / r; return *this; }

        
        Complex& operator+=(double x) { a += x; return *this; }
        Complex& operator-=(double x) { a -= x; return *this; }
        Complex& operator*=(double x) { a *= x; b *= x; return *this; }
        Complex& operator/=(double x) { a /= x; b /= x; return *this; }

        
        friend Complex operator+(double x, const Complex& z) { return z + x; }
        friend Complex operator-(double x, const Complex& z) { return Complex(x - z.a, -z.b); }
        friend Complex operator*(double x, const Complex& z) { return z * x; }
        friend Complex operator/(double x, const Complex& z) { return Complex(x / z.a, -x * z.b / (z.a * z.a + z.b * z.b)); }

       
        double Real() const { return a; }
        double Imag() const { return b; }
        double Abs()  const { return std::sqrt(a * a + b * b); }

       
        friend std::istream& operator>>(std::istream& in, Complex& z) {
            return in >> z.a >> z.b;
        }
        friend std::ostream& operator<<(std::ostream& out, const Complex& z) {
            out << z.a;
            if (z.b >= 0) out << " + " << z.b << "i";
            else          out << " - " << -z.b << "i";
            return out;
        }
    };
    int main() {
        setlocale(LC_ALL, "Rus");
        Complex z1;
        std::cin >> z1;
        std::cout << "Real = " << z1.Real() << ", Imag = " << z1.Imag()
            << ", Abs = " << z1.Abs() << "\n";

        
        std::cout << "z1 = " << z1<<"\n";

        return 0;
    }
