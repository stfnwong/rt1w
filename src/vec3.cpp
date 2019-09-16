/*
 * VEC3
 * A simple vec3 class
 *
 * Stefan Wong 2019
 */


#include "vec3.hpp"


vec3::vec3()
{
    for(int i = 0; i < 3; ++i)
        this->e[i] = 0;
}

vec3::vec3(float e0, float e1, float e2)
{
    this->e[0] = e0;
    this->e[1] = e1;
    this->e[2] = e2;
}


/*
 * make_unit_vector()
 */
void vec3::make_unit_vector(void) 
{
    float k;
    
    k = 1.0f / sqrt(this->e[0] * this->e[0] +
                    this->e[1] * this->e[1] +
                    this->e[2] * this->e[2]
    );
    this->e[0] *= k;
    this->e[1] *= k;
    this->e[2] *= k;
}


// ==== getters ==== //
float vec3::x(void) const
{
    return this->e[0];
}

float vec3::y(void) const
{
    return this->e[1];
}

float vec3::z(void) const
{
    return this->e[2];
}

float vec3::r(void) const
{
    return this->e[0];
}

float vec3::g(void) const
{
    return this->e[1];
}

float vec3::b(void) const
{
    return this->e[2];
}

float vec3::length(void) const
{
    return sqrt(
            this->e[0] * this->e[0] +  
            this->e[1] * this->e[1] + 
            this->e[2] * this->e[2]  
    );
}

float vec3::squared_length(void) const
{
    return (this->e[0] * this->e[0] + 
            this->e[1] * this->e[1] + 
            this->e[2] * this->e[2]
   );
}

// ==== operators ==== //
const vec3& vec3::operator+(void) const
{
    return *this;
}

vec3 vec3::operator-(void) const
{
    return vec3(-this->e[0], -this->e[1], -this->e[2]);
}

float vec3::operator[](int i) const
{
    return this->e[i];
}

float& vec3::operator[](int i)
{
    return this->e[i];
}


/*
 * +=
 */
vec3& vec3::operator+=(const vec3& that)
{
    this->e[0] += that.e[0];
    this->e[1] += that.e[1];
    this->e[2] += that.e[2];

    return *this;
}

/*
 * -=
 */
vec3& vec3::operator-=(const vec3& that)
{
    this->e[0] -= that.e[0];
    this->e[1] -= that.e[1];
    this->e[2] -= that.e[2];

    return *this;
}

/*
 * *=
 */
vec3& vec3::operator*=(const vec3& that)
{
    this->e[0] *= that.e[0];
    this->e[1] *= that.e[1];
    this->e[2] *= that.e[2];

    return *this;
}

/*
 * /=
 */
vec3& vec3::operator/=(const vec3& that)
{
    this->e[0] /= that.e[0];
    this->e[1] /= that.e[1];
    this->e[2] /= that.e[2];

    return *this;
}

// ==== Assignment operators with a float and a vec3
vec3& vec3::operator*=(const float t)
{
    this->e[0] *= t;
    this->e[1] *= t;
    this->e[2] *= t;

    return *this;
}

vec3& vec3::operator/=(const float t)
{
    float k = 1.0 / t;

    this->e[0] *= k;
    this->e[1] *= k;
    this->e[2] *= k;

    return *this;
}

// comparison operators


// ==== Standalone arithemtic operations ==== //

// ==== Arithmetic with two vectors ==== //
vec3 operator+(const vec3& v1, const vec3& v2)
{
    return vec3(
            v1.e[0] + v2.e[0],
            v1.e[1] + v2.e[1],
            v1.e[2] + v2.e[2]
    );
}

vec3 operator-(const vec3& v1, const vec3& v2)
{
    return vec3(
            v1.e[0] - v2.e[0],
            v1.e[1] - v2.e[1],
            v1.e[2] - v2.e[2]
    );
}

vec3 operator*(const vec3& v1, const vec3& v2)
{
    return vec3(
            v1.e[0] * v2.e[0],
            v1.e[1] * v2.e[1],
            v1.e[2] * v2.e[2]
    );
}

vec3 operator/(const vec3& v1, const vec3& v2)
{
    return vec3(
            v1.e[0] / v2.e[0],
            v1.e[1] / v2.e[1],
            v1.e[2] / v2.e[2]
    );
}

// ==== Arithmetic with a float and a vector ==== //
vec3 operator+(float t, const vec3& v)
{
    return vec3(
            t + v.e[0],
            t + v.e[1],
            t + v.e[2]
    );
}

vec3 operator-(float t, const vec3& v)
{
    return vec3(
            t - v.e[0],
            t - v.e[1],
            t - v.e[2]
    );
}

vec3 operator*(float t, const vec3& v)
{
    return vec3(
            t * v.e[0],
            t * v.e[1],
            t * v.e[2]
    );
}

vec3 operator*(const vec3& v, float t)
{
    return vec3(
            v.e[0] * t,
            v.e[1] * t,
            v.e[2] * t
    );
}

vec3 operator/(float t, const vec3& v)
{
    return vec3(
            t / v.e[0],
            t / v.e[1],
            t / v.e[2]
    );
}

vec3 operator/(const vec3& v, float t)
{
    return vec3(
            v.e[0] / t,
            v.e[1] / t,
            v.e[2] / t
    );
}


/*
 * unit_vector()
 */
vec3 unit_vector(vec3 v)
{
    return v / v.length();
}

/*
 * dot()
 */
float dot(const vec3& v1, const vec3& v2)
{
    return (v1.e[0] * v2.e[0] +
            v1.e[1] * v2.e[1] + 
            v1.e[2] * v2.e[2]
   );
}


/*
 * cross()
 */
vec3 cross(const vec3& v1, const vec3& v2)
{
    return vec3(
            (v1.e[1] * v2.e[2]  - v1.e[2] * v2.e[1]),
            (-(v1.e[0] * v2.e[2]) - v1.e[2] * v2.e[0]),
            (v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0])
    );
}
