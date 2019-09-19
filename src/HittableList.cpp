/*
 * HITTABLE_LIST
 * A list of Hittable things
 *
 * Stefan Wong 2019
 */

#include "HittableList.hpp"

HittableList::HittableList() {} 

HittableList::HittableList(Hittable** l, int n)
{
    this->list = l;
    this->list_size = n;
}

HittableList::~HittableList()
{
    delete this->list;
}

bool HittableList::hit(const Ray& r, float t_min, float t_max, hit_record& rec) const
{
    hit_record temp_rec;
    bool hit_anything;
    double cur_closest;

    hit_anything = false;
    cur_closest = t_max;

    // walk along the list and see if we hit anything
    for(int i = 0; i < this->list_size; ++i)
    {
        if(this->list[i]->hit(r, t_min, cur_closest, temp_rec))
        {
            hit_anything = true;
            cur_closest = temp_rec.t;
            rec = temp_rec;
        }
    }

    return hit_anything;
}
