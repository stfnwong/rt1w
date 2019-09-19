/*
 * RAY
 * Ray class
 *
 * Stefan Wong 2019
 */

#ifndef __RT_RAY_HPP
#define __RT_RAY_HPP

#include "vec3.hpp"

/*
 * Ray
 * Ray structure
 */
struct Ray
{
    vec3 A;
    vec3 B;

    public:
        Ray();
        Ray(const vec3& a, const vec3& b);
        
        vec3 origin(void) const;
        vec3 direction(void) const;
        vec3 point_at_parameter(float t) const;
};


#endif /*__RT_RAY_HPP*/
