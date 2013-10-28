#ifndef POINT_H
#define POINT_H

#include <cmath>

//class representing point or 2D vector
template <class T>
struct Point
{
    Point() : x(0), y(0) { }
    Point(const T x, const T y) : x(x), y(y) { }
    Point(const Point& obj) : x(obj.x), y(obj.y) { }
    ~Point() { }

    //counting vector length
    float getLength()
    {
        return sqrt(pow(x, 2) + pow(y, 2));
    }

    //normalizing vector
    void normalize()
    {
        float length = this->getLength();
        x = x / length;
        y = y / length;
    }

    //return normalized vector
    Point<T> normalized()
    {
        Point<T> normPoint(*this);
        normPoint.normalize();
        return normPoint;
    }

    //
    //arithmetical operations
    //
    Point operator-()
    {
        return Point(-this->x, -this->y);
    }

    Point& operator=(const Point& obj)
    {
        this->x = obj.x;
        this->y = obj.y;
        return *this;
    }

    void operator+=(const Point& obj)
    {
        this->x += obj.x;
        this->y += obj.y;
    }

    void operator-=(const Point& obj)
    {
        this->x -= obj.x;
        this->y -= obj.y;
    }

    Point operator+(const Point& obj)
    {
        Point result(this->x + obj.x, this->y + obj.y);
        return result;
    }

    Point operator-(const Point& obj)
    {
        Point result(this->x - obj.x, this->y - obj.y);
        return result;
    }

    Point& operator*(const T value)
    {
        this->x *= value;
        this->y *= value;
        return *this;
    }

    T x, y;
};

typedef Point<float> PointF;
typedef Point<int> PointI;

#endif // POINT_H
