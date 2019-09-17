/*
 * HITTABLE_LIST
 * A list of hittable things
 *
 * Stefan Wong 2019
 */

#include "hittable_list.hpp"

hittable_list::hittable_list() {} 

hittable_list::hittable_list(hittable** l, int n)
{
    this->list = l;
    this->list_size = n;
}

hittable_list::~hittable_list()
{
    delete this->list;
}

bool hittable_list::hit(const ray& r, float t_min, float t_max, hit_record& rec) const
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

    // NOT EQUIVALENT
    //for(int i = 0; i < this->list_size; ++i)
    //{
    //    hit_anything = this->list[i]->hit(r, t_min, cur_closest, temp_rec);
    //    if(hit_anything)
    //    {
    //        cur_closest = temp_rec.t;
    //        rec = temp_rec;
    //    }
    //}
    
    return hit_anything;
}
