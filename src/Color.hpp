/*
 * COLOR
 * Different coloring methods for spheres
 *
 * Stefan Wong 2019
 */

#ifndef __RT_COLOR_HPP
#define __RT_COLOR_HPP

#include "Ray.hpp"
#include "Hittable.hpp"


vec3 color_normal(const Ray& r, Hittable* world);

vec3 color_diffuse(const Ray& r, Hittable* world);

vec3 color_metal(const Ray& t, Hittable* world, int depth);


#endif /*__RT_COLOR_HPP*/
