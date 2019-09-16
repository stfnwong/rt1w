/*
 * VEC3
 * A simple vec3 class
 *
 * Stefan Wong 2019
 */

#ifndef __RT_VEC3_HPP
#define __RT_VEC3_HPP

#include <cmath>
#include <cstdlib>
#include <iostream>

/*
 * vec3
 * 3-dimensional vector structure
 */
struct vec3
{
    float   e[3];

    public:
        vec3();
        vec3(float e0, float e1, float e2);

        void make_unit_vector(void);

        // getters
        float x(void) const;
        float y(void) const;
        float z(void) const;
        float r(void) const;
        float g(void) const;
        float b(void) const;
        float length(void) const;
        float squared_length(void) const;

        // operators
        const vec3& operator+(void) const;
        vec3 operator-(void) const;
        float operator[](int i) const;
        float& operator[](int i);

        // assignment arithmetic 
        vec3& operator+=(const vec3& that);
        vec3& operator-=(const vec3& that);
        vec3& operator*=(const vec3& that);
        vec3& operator/=(const vec3& that);
        vec3& operator*=(const float t);
        vec3& operator/=(const float t);
};


// arithmetic with two vectors
vec3 operator+(const vec3& v1, const vec3& v2);
vec3 operator-(const vec3& v1, const vec3& v2);
vec3 operator*(const vec3& v1, const vec3& v2);
vec3 operator/(const vec3& v1, const vec3& v2);
// arithmetic with a float
vec3 operator+(float t, const vec3& v2);
vec3 operator-(float t, const vec3& v2);
vec3 operator*(float t, const vec3& v2);
vec3 operator*(const vec3& v1, float t);
vec3 operator/(float t, const vec3& v2);
vec3 operator/(const vec3& v1, float t);

// get a unit vector
vec3 unit_vector(vec3 v);

// other math
float dot(const vec3& v1, const vec3& v2);
vec3 cross(const vec3& v1, const vec3& v2);


#endif /*__RT_VEC3_HPP*/
