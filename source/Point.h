/**
 * @file Point.h
 * @brief Provides class representing point/vector
 * @author paul-the-creator
 * @date 2013
 */

#ifndef POINT_H
#define POINT_H

#include <cmath>

/**
 * @class Point
 * @brief template struct representing point or 2D vector
 * @author paul-the-creator
 * @date 2013
 */
template <class T>
struct Point
{
    /**
      * @brief constructors
      */
    Point() : x(0), y(0) { }
    Point(const T x, const T y) : x(x), y(y) { }
    Point(const Point& obj) : x(obj.x), y(obj.y) { }
    ~Point() { }
    /**
      * @brief Function returns vector length
      * @return float - length value
      */
    float getLength()
    {
        return sqrt(pow(x, 2) + pow(y, 2));
    }
    /**
      * @brief Function makes normalized vector
      * @return void
      */
    void normalize()
    {
        float length = this->getLength();
        x = x / length;
        y = y / length;
    }
    /**
      * @brief Function returns normalized vector
      * @return Point<T> - normalized vector coordinates
      */
    Point<T> normalized()
    {
        Point<T> normPoint(*this);
        normPoint.normalize();
        return normPoint;
    }


    /**
      * @brief Aritmetical operations
      */
    Point operator-() const
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
    //scalar product
    T operator*(const Point& obj)
    {
        float scalarProd = this->x * obj.y + this->y * obj.x;
        return scalarProd;
    }

    T x, y;
};

typedef Point<float> PointF;
typedef Point<int> PointI;

#endif // POINT_H
