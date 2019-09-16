/*
 * HITTABLE_LIST
 * A list of hittable things
 *
 * Stefan Wong 2019
 */

#ifndef __RT_HITTABLE_LIST
#define __RT_HITTABLE_LIST

#include "hittable.hpp"

/*
 * hittable_list
 *
 * List of things that can be hit
 */
class hittable_list : public hittable
{
    public:
        hittable** list;
        int list_size;

    public:
        hittable_list();
        ~hittable_list();
        hittable_list(hittable** l, int n);
        virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const;
};


#endif /*__RT_HITTABLE_LIST*/
