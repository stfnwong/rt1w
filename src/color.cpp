/*
 * COLOR
 * Different coloring methods for spheres
 *
 * Stefan Wong 2019
 */

#include "color.hpp"
#include "sphere.hpp"

vec3 color_normal(const ray& r, hittable* world)
{
    float t;
    vec3 unit_direction;
    hit_record rec;

    if(world->hit(r, 0.0001, MAXFLOAT, rec))
    {
        return 0.5 * vec3(
                rec.normal.x() + 1,
                rec.normal.y() + 1,
                rec.normal.z() + 1
        );
    }
    else
    {
        unit_direction = unit_vector(r.direction());
        t = 0.5 * (unit_direction.y() + 1.0);
        return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
    }
}


vec3 color_diffuse(const ray& r, hittable* world)
{
    float t;
    vec3 target;
    vec3 unit_direction;
    hit_record rec;

    if(world->hit(r, 0.0001, MAXFLOAT, rec))
    {
        target = rec.p + rec.normal + random_in_unit_sphere();
        return 0.5 * color_diffuse(ray(rec.p, target - rec.p), world);
    }
    else
    {
        unit_direction = unit_vector(r.direction());
        t = 0.5 * (unit_direction.y() + 1.0);
        return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
    }
}


