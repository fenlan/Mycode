#ifndef _VECTOR_
#define _VECTOR_
#include <iostream>

class Vector {
    static const int VEC_SIZE = 4;
    float* items;
public:
    class RangeError {};

    Vector();
    Vector(const Vector& other);
    ~Vector();

    void check(int idx) const;
    float& operator[](const int idx);     // Vec[i] = 1.0f equal items[i] = 1.0f
    float operator[](const int idx) const;      // Vec[i] + 1.0f is float + float

    Vector& operator+=(const Vector& x);
    Vector& operator-=(const Vector& x);
    Vector& operator*=(const Vector& x);
    Vector& operator/=(const Vector& x);
    Vector operator+(const Vector& x) const;
    Vector operator-(const Vector& x) const;
    Vector operator*(const Vector& x) const;
    Vector operator/(const Vector& x) const;

    Vector& operator=(const Vector& x);
    Vector& operator+=(const float x);
    Vector& operator-=(const float x);
    Vector& operator*=(const float x);
    Vector& operator/=(const float x);
    Vector operator+(const float x) const;
    Vector operator-(const float x) const;
    Vector operator*(const float x) const;
    Vector operator/(const float x) const;
    friend Vector operator+(const float x, const Vector& y);
    friend Vector operator-(const float x, const Vector& y);
    friend Vector operator*(const float x, const Vector& y);
    friend Vector operator/(const float x, const Vector& y);

    friend std::ostream& operator<<(std::ostream& output, const Vector& x);
};

#endif
