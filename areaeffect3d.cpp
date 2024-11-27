#include "areaeffect3d.h"
#include "damageable_entities.h"


/*
    TODO:
    - connect add and remove methods directly to signals?
        - check if possible
*/

AreaEffect3D::AreaEffect3D(int max_affected) : Area3D() {
    affected.reserve(max_affected);
    stored_types.resize_zeroed(max_affected);
}

AreaEffect3D::~AreaEffect3D() {
    affected.clear();// may be unnecessary
}


bool AreaEffect3D::has_affected_node(Node3D* const node) {
    CollisionObject3D *c_obj = Object::cast_to<CollisionObject3D>(node);
    //DamageableRef r(Object::cast_to<CollisionObject3D>(node));

    if (c_obj == nullptr)
        return false;

    return (affected.find(c_obj) > 0);
}

/*
    NOTE: currently a signal needs to be connected to this in-editor
*/
bool AreaEffect3D::add_affected_node(Node3D* const node) {
    if (affected.size() < affected.get_capacity())
    {
        CollisionObject3D *c_obj = Object::cast_to<CollisionObject3D>(node);

        if (c_obj == nullptr)
            return false;
        else {
            uint8_t type;
            if (Object::cast_to<Actor3D>(c_obj))
                type = 3;
            else if (Object::cast_to<AnimatableDamageable3D>(c_obj))
                type = 2;
            else if (Object::cast_to<StaticDamageable3D>(c_obj))
                type = 1;
            else
                return false;

            // only if one of the conditions is met:
            stored_types.set(affected.size(), type);
            affected.push_back(c_obj);
            return true;
        }
    }
    return false;
}

/*
    NOTE: currently a signal needs to be connected to this in-editor
*/
bool AreaEffect3D::remove_affected_node(Node3D* const node) {
    CollisionObject3D *c_obj = Object::cast_to<CollisionObject3D>(node);

    if (c_obj == nullptr)
        return false;

    affected.erase_multiple_unordered(c_obj);
    return true;
}

// should not resize to 0
void AreaEffect3D::clear_affected() {
    for (int i = affected.size() - 1; i >= 0; i--) {
        affected.remove_at_unordered(i);
    }
}

uint64_t AreaEffect3D::get_affected_count() const {
    return (uint64_t)affected.size();
}

CollisionObject3D *AreaEffect3D::get_affected(int idx) const {
    return ((idx >= 0) && ((uint32_t)idx < affected.size())) ? affected[idx] : nullptr;
}

/*
    Based on Node's get_children function
*/
TypedArray<CollisionObject3D> AreaEffect3D::get_all_affected() const {
	ERR_THREAD_GUARD_V(TypedArray<CollisionObject3D>());//not sure if this is needed, but it is used in Node's get_children function
	TypedArray<CollisionObject3D> arr;
	int s = affected.size();
	arr.resize(s);
	for (int i = 0; i < s; i++) {
		arr[i] = affected[i];
	}

	return arr;
}

void AreaEffect3D::damage_all(float amount, int type) {
    uint32_t s = affected.size();
    for (size_t i = 0; i < s; i++)
    {
        // pointers are checked to be one of the following types on entry
        switch (stored_types[i])
        {
        case 1:
            reinterpret_cast<StaticDamageable3D*>(affected[i])->damage(amount, type);
            break;
        case 2:
            reinterpret_cast<AnimatableDamageable3D*>(affected[i])->damage(amount, type);
            break;
        case 3:
            reinterpret_cast<Actor3D*>(affected[i])->damage(amount, type);
            break;
        }
    }
}

void AreaEffect3D::heal_all(float amount) {
    uint32_t s = affected.size();
    for (size_t i = 0; i < s; i++)
    {
        // pointers are checked to be one of the following types on entry
        switch (stored_types[i])
        {
        case 1:
            reinterpret_cast<StaticDamageable3D*>(affected[i])->heal(amount);
            break;
        case 2:
            reinterpret_cast<AnimatableDamageable3D*>(affected[i])->heal(amount);
            break;
        case 3:
            reinterpret_cast<Actor3D*>(affected[i])->heal(amount);
            break;
        }
    }
}

void AreaEffect3D::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("add_affected", "id"), &AreaEffect3D::add_affected_node);
	ClassDB::bind_method(D_METHOD("remove_affected", "id"), &AreaEffect3D::remove_affected_node);
	ClassDB::bind_method(D_METHOD("is_affected", "id"), &AreaEffect3D::has_affected_node);
	ClassDB::bind_method(D_METHOD("clear_affected"), &AreaEffect3D::clear_affected);
    
	ClassDB::bind_method(D_METHOD("damage_all", "amount" "type"), &AreaEffect3D::damage_all);
	ClassDB::bind_method(D_METHOD("heal_all", "amount"), &AreaEffect3D::heal_all);
    
	ClassDB::bind_method(D_METHOD("get_affected_count"), &AreaEffect3D::get_affected_count);
	ClassDB::bind_method(D_METHOD("get_affected", "idx"), &AreaEffect3D::get_affected);
	ClassDB::bind_method(D_METHOD("get_all_affected"), &AreaEffect3D::get_all_affected);
}