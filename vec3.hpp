#ifndef vec3_H_
#define vec3_H_

#include <cassert>
#include <cmath>
#include <ostream>

class vec3
{
public:
    vec3() : m_pos{0.0, 0.0, 0.0} {}     
    vec3(double x, double y, double z): m_pos{x, y ,z} {} 

    double x() const { return m_pos[0]; }
    double y() const { return m_pos[1]; }
    double z() const { return m_pos[2]; }

    // Unary - operator
    vec3 operator-() const;
 
    // Binary assignment opeartors
    vec3& operator+=(const vec3& other);
    vec3& operator-=(const vec3& other);
    vec3& operator*=(const double factor);
    vec3 operator/=(const double factor);

    double operator[](int index) const;
    double& operator[](int index);

    double length() const;

public:
    double m_pos[3];

};

/* Utility functions */

// output
std::ostream& operator<<(std::ostream& out, const vec3& vec);

// math operations
vec3 operator+(const vec3& vec1, const vec3& vec2);
vec3 operator-(const vec3& vec1, const vec3& vec2);
vec3 operator*(const vec3& vec1, const vec3& vec2);

vec3 operator*(const vec3& vec, const double factor);
vec3 operator*(const double factor, const vec3& vec);

vec3 operator/(const double factor, const vec3& vec);

double dot(const vec3& vec1, const vec3& vec2);
vec3 cross(const vec3& vec1, const vec3& vec2);

vec3 normalize(const vec3& vec);

using point3 = vec3;
using color  = vec3;

#endif
