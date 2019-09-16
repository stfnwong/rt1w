/*
 * SPHERE
 * Definition of a sphere in terms of a hittable
 *
 * Stefan Wong 2019
 */

#include "sphere.hpp"


sphere::sphere(vec3 cen, float r) : center(cen), radius(r) {} 

bool sphere::hit(const ray& r, float t_min, float t_max, hit_record& rec) const
{
    vec3 oc;
    float a, b, c, disc;
    float temp;

    oc = r.origin() - center;
    a = dot(r.direction(), r.direction());
    b = dot(oc, r.direction());
    c = dot(oc, oc) - radius * radius;
    disc = b * b - a * c;

    // later on, think about factoring out the duplicate branch
    if(disc > 0)
    {
        // check negative sign root
        temp = (-b - sqrt(b*b - a*c)) / a;
        if(temp > t_min && temp < t_max)
        {
            rec.t = temp;
            rec.p = r.point_at_parameter(rec.t);
            rec.normal = (rec.p - center) / radius;
            return true;
        }
        // check postive sign root
        temp = (-b + sqrt(b*b - a*c)) / a;
        if(temp > t_min && temp < t_max)
        {
            rec.t = temp;
            rec.p = r.point_at_parameter(rec.t);
            rec.normal = (rec.p - center) / radius;
            return true;
        }
    }

    return false;
}
