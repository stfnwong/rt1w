/*
 * RAY
 * Ray class
 *
 * Stefan Wong 2019
 */

#include "Ray.hpp"


Ray::Ray() : A(0.0, 0.0, 0.0), B(0.0, 0.0, 0.0) {} 

Ray::Ray(const vec3& a, const vec3& b)
{
    this->A = a;
    this->B = b;
}


/*
 * origin()
 */
vec3 Ray::origin(void) const
{
    return this->A;
}

/*
 * direction()
 */
vec3 Ray::direction(void) const
{
    return this->B;
}

/*
 * point_at_parameter()
 */
vec3 Ray::point_at_parameter(float t) const
{
    return this->A + t * this->B;
}

