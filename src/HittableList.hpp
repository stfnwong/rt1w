/*
 * HITTABLE_LIST
 * A list of Hittable things
 *
 * Stefan Wong 2019
 */

#ifndef __RT_HITTABLE_LIST
#define __RT_HITTABLE_LIST

#include "Hittable.hpp"

/*
 * HittableList
 *
 * List of things that can be hit
 */
class HittableList : public Hittable
{
    public:
        Hittable** list;
        int list_size;

    public:
        HittableList();
        ~HittableList();
        HittableList(Hittable** l, int n);
        virtual bool hit(const Ray& r, float t_min, float t_max, hit_record& rec) const;
};


#endif /*__RT_HITTABLE_LIST*/
