#include "vec3.hpp"

/* Member Function definitions start here */

vec3 vec3::operator-() const
{
    return {-m_pos[0], -m_pos[1], -m_pos[2]};
}

vec3& vec3::operator+=(const vec3& other)
{
    m_pos[0] += other.m_pos[0];
    m_pos[1] += other.m_pos[1];
    m_pos[2] += other.m_pos[2];
    return *this;
}

vec3& vec3:: operator-=(const vec3& other)
{
    *this += -other;
    return *this;
}

vec3& vec3::operator*=(const double factor)
{
    m_pos[0] *= factor;
    m_pos[1] *= factor;
    m_pos[2] *= factor;

    return *this;
}

vec3 vec3::operator/=(const double factor)
{
    *this *= 1/factor;
    return *this;
}

double vec3::operator[](int index) const
{
    assert(index < 0 || index > 2);

    return m_pos[index];
}

double& vec3::operator[](int index)
{
    assert(index < 0 || index > 2);

    return m_pos[index];
}


double vec3::length() const
{
    double length_squared = (m_pos[0] * m_pos[0]
                           + m_pos[1] * m_pos[1]
                           + m_pos[2] * m_pos[2]);

    return sqrt(length_squared);
}

/* Utility Function definitions start here */

std::ostream& operator<<(std::ostream& out, const vec3& vec)
{
    out << "X: " << vec.m_pos[0] << " Y: " << vec.m_pos[1] << " Z: " << vec.m_pos[2];
    return out;
}

vec3 operator+(const vec3& vec1, const vec3& vec2)
{
    return {vec1.m_pos[0] + vec2.m_pos[0],
            vec1.m_pos[1] + vec2.m_pos[1],
            vec1.m_pos[2] + vec2.m_pos[2]
    };
}

vec3 operator-(const vec3& vec1, const vec3& vec2)
{
    return {vec1.m_pos[0] - vec2.m_pos[0],
            vec1.m_pos[1] - vec2.m_pos[1],
            vec1.m_pos[2] - vec2.m_pos[2]
    };

}

vec3 operator*(const vec3& vec1, const vec3& vec2)
{
    return {vec1.m_pos[0] * vec2.m_pos[0],
            vec1.m_pos[1] * vec2.m_pos[1],
            vec1.m_pos[2] * vec2.m_pos[2]
    };
}

vec3 operator*(const vec3& vec, const double factor)
{
    return {vec.m_pos[0] * factor,
            vec.m_pos[1] * factor,
            vec.m_pos[2] * factor
    };
}

vec3 operator*(const double factor, const vec3& vec)
{
    return (vec * factor);
}

vec3 operator/(const vec3& vec, const double factor)
{
    return vec * (1/factor);
}

double dot(const vec3& vec1, const vec3& vec2)
{
      return {vec1.m_pos[0] * vec2.m_pos[0]
            + vec1.m_pos[1] * vec2.m_pos[1]
            + vec1.m_pos[2] * vec2.m_pos[2]
    };
}

vec3 cross(const vec3& vec1, const vec3& vec2)
{
    return {(vec1.m_pos[1] * vec2.m_pos[2]) - (vec1.m_pos[2] * vec2.m_pos[1]),
            (vec1.m_pos[2] * vec2.m_pos[0]) - (vec1.m_pos[0] * vec2.m_pos[2]),
            (vec1.m_pos[0] * vec2.m_pos[1]) - (vec1.m_pos[1] * vec2.m_pos[0])
    };
}

vec3 normalize(const vec3& vec)
{
    return vec / vec.length();
}
