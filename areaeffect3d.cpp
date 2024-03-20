#include "modules/entityeffects/areaeffect3d.h"

/*
    TODO:
    - connect add and remove methods directly to signals?
        - check if possible
*/

AreaEffect3D::AreaEffect3D() : Area3D(), a_length(20), first_free_slot(0) {
	affected.resize(a_length);
    for (int64_t i = 0; i < a_length; i++)
    {
        affected.set(i, NULL);
    }
    
}

AreaEffect3D::~AreaEffect3D() {}

bool AreaEffect3D::has_node(Variant node) {
    for (int64_t i = 0; i < first_free_slot; i++) {
        if (affected[i] == node) return true;
    }
    return false;
}

bool AreaEffect3D::add_node(Variant node) {
    if ((first_free_slot < a_length) && (!has_node(node))) {
        //affected[first_free_slot] = node;
        affected.set(first_free_slot, node);
        first_free_slot++;
        return true;
    }
    else
        return false;
}

bool AreaEffect3D::remove_node(Variant node) {
    int64_t i = 0, found_at = -1, limit = a_length;
    for (i = 0; i < limit; i++) {
        if (affected[i] == node) {
            found_at = i;
            break;
        }
    }
    if (found_at > -1) {
        limit--;
        first_free_slot--;
        for (i = found_at + 1; i < a_length; i++) {
            //affected[i - 1] = affected[i];
            affected.set(i - 1, affected[i]);
        }
        //affected.set(i - 1, NULL);
    }
    return found_at;
}

void AreaEffect3D::clear_affected() {
    for (int64_t i = 0; i < a_length; i++) {
        //affected[i] = 0;
        affected.set(i, NULL);
    }
    first_free_slot = 0;
}


void AreaEffect3D::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("add", "id"), &AreaEffect3D::add_node);
	ClassDB::bind_method(D_METHOD("remove", "id"), &AreaEffect3D::remove_node);
	ClassDB::bind_method(D_METHOD("has", "id"), &AreaEffect3D::has_node);
	ClassDB::bind_method(D_METHOD("clear_affected"), &AreaEffect3D::clear_affected);
}