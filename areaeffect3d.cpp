#include "areaeffect3d.h"

/*
    TODO:
    - connect add and remove methods directly to signals?
        - check if possible
*/

AreaEffect3D::AreaEffect3D(int max_affected) : Area3D() {
    affected.reserve(max_affected);
}

AreaEffect3D::~AreaEffect3D() {}

bool AreaEffect3D::has_affected_node(const Variant &node/*const Ref<PhysicsBody3D> &node*/) {
    return (affected.find(node) > 0);
}

bool AreaEffect3D::add_affected_node(Variant node/*const Ref<PhysicsBody3D> &node*/) {
    if (affected.size() < affected.get_capacity())
        affected.push_back(node);
}

bool AreaEffect3D::remove_affected_node(const Variant &node/*const Ref<PhysicsBody3D> &node*/) {
    affected.erase_multiple_unordered(node);
}

// should not resize to 0
void AreaEffect3D::clear_affected() {
    for (int i = affected.size() - 1; i >= 0; i--) {
        affected.remove_at_unordered(i);
    }
}


void AreaEffect3D::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("add", "id"), &AreaEffect3D::add_affected_node);
	ClassDB::bind_method(D_METHOD("remove", "id"), &AreaEffect3D::remove_affected_node);
	ClassDB::bind_method(D_METHOD("has", "id"), &AreaEffect3D::has_affected_node);
	ClassDB::bind_method(D_METHOD("clear_affected"), &AreaEffect3D::clear_affected);
}