/*
 * COLOR
 * Different coloring methods for spheres
 *
 * Stefan Wong 2019
 */

#ifndef __RT_COLOR_HPP
#define __RT_COLOR_HPP

#include "ray.hpp"
#include "hittable.hpp"


vec3 color_normal(const ray& r, hittable* world);

vec3 color_diffuse(const ray& r, hittable* world);

vec3 color_metal(const ray& t, hittable* world, int depth);


#endif /*__RT_COLOR_HPP*/
