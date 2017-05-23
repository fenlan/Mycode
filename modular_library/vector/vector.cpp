#include "vector.hpp"

Vector::Vector()
{
    items = new float[VEC_SIZE];
    for (int i=0; i<VEC_SIZE; i++)
        items[i] = 0.0;
}

Vector::Vector(const Vector& other)
{
    items = new float[VEC_SIZE];
    for (int i=0; i<VEC_SIZE; i++)
        items[i] = other.items[i];
}

Vector::~Vector()
{
    delete[] items;
}

void Vector::check(int idx) const
{
    if (idx < 0 || idx >= VEC_SIZE)
        throw RangeError();
}

float& Vector::operator[](const int idx)
{
    check(idx);
    return items[idx];
}

float Vector::operator[](const int idx) const
{
    check(idx);
    return items[idx];
}

Vector& Vector::operator+=(const Vector& x)
{
    for(int i = 0; i < Vector::VEC_SIZE; i++)
        items[i] += x.items[i];
    return *this;
}

Vector& Vector::operator-=(const Vector& x)
{
    for(int i = 0; i < Vector::VEC_SIZE; i++)
        items[i] -= x.items[i];
    return *this;
}

Vector& Vector::operator*=(const Vector& x)
{
    for(int i = 0; i < Vector::VEC_SIZE; i++)
        items[i] *= x.items[i];
    return *this;
}

Vector& Vector::operator/=(const Vector& x)
{
    for(int i = 0; i < Vector::VEC_SIZE; i++)
        items[i] /= x.items[i];
    return *this;
}

Vector Vector::operator+(const Vector& x) const
{
    Vector result = *this;
    result += x;
    return result;
}

Vector Vector::operator-(const Vector& x) const
{
    Vector result = *this;
    result -= x;
    return result;
}

Vector Vector::operator*(const Vector& x) const
{
    Vector result = *this;
    result *= x;
    return result;
}

Vector Vector::operator/(const Vector& x) const
{
    Vector result = *this;
    result /= x;
    return result;
}

Vector& Vector::operator=(const Vector& x)
{
    for(int i = 0; i < Vector::VEC_SIZE; i++)
        items[i] = x.items[i];
    return *this;
}

Vector& Vector::operator+=(const float x)
{
    for(int i = 0; i < Vector::VEC_SIZE; i++)
        items[i] += x;
    return *this;
}

Vector& Vector::operator-=(const float x)
{
    for(int i = 0; i < Vector::VEC_SIZE; i++)
        items[i] -= x;
    return *this;
}

Vector& Vector::operator*=(const float x)
{
    for(int i = 0; i < Vector::VEC_SIZE; i++)
        items[i] *= x;
    return *this;
}

Vector& Vector::operator/=(const float x)
{
    for(int i = 0; i < Vector::VEC_SIZE; i++)
        items[i] /= x;
    return *this;
}

Vector Vector::operator+(const float x) const
{
    Vector result = *this;
    result += x;
    return result;
}

Vector Vector::operator-(const float x) const
{
    Vector result = *this;
    result -= x;
    return result;
}

Vector Vector::operator*(const float x) const
{
    Vector result = *this;
    result *= x;
    return result;
}

Vector Vector::operator/(const float x) const
{
    Vector result = *this;
    result /= x;
    return result;
}

Vector operator+(const float x, const Vector& y)
{
    return y + x;
}

Vector operator-(const float x, const Vector& y)
{
    Vector result;
    for(int i = 0; i < Vector::VEC_SIZE; i++)
        result[i] = x - y.items[i];
    return result;
}

Vector operator*(const float x, const Vector& y)
{
    return y * x;
}

Vector operator/(const float x, const Vector& y)
{
    Vector result;
    for(int i = 0; i < Vector::VEC_SIZE; i++)
        result[i] = x / y.items[i];
    return result;
}

std::ostream& operator<<(std::ostream& output, const Vector& x)
{
    output << '[';
    for(int i = 0; i < Vector::VEC_SIZE; i++)
    {
        output << x.items[i];
        if(i < Vector::VEC_SIZE-1) output << ',';
    }
    output << ']';
    return output;
}
