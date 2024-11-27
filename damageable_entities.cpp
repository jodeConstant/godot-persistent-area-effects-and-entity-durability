#include "damageable_entities.h"

#include "scene/scene_string_names.h"// same as in physics_body_3d.cpp, just in case

/*
	Extending all of the classes in the same way, since multiple inheritance doesn't go with Godot / GDscript
*/

float StaticDamageable3D::damage(float amount, int type) {
	float damage_received = (durability.is_valid() ? durability->reduced_damage(amount, (Durability::DamageType)(type & DMG_TYPE_MASK)) : amount);
	HP -= damage_received;
	if (HP <= 0) {
		// TODO: emit a signal here
	}

	return damage_received;
}

/*
	Calculates and returns the difference:
	- negative means not fully healed
	- 0 means exactly fully healed
	- positive means excessive / overheal (currently does nothing special, current HP is just set to max HP value)
*/
float StaticDamageable3D::heal(float amount) {
	HP += amount;
	amount = HP - HP_MAX_BASE;

	if (amount > 0)
		HP = HP_MAX_BASE;
		
	return amount;
}

void StaticDamageable3D::set_HP_max(float value) {
	if (value >= 1)
		HP_MAX_BASE = value;
}

float StaticDamageable3D::get_HP_max() {
	return HP_MAX_BASE;
}

void StaticDamageable3D::set_HP_current(float value) {
	HP = value;
}

float StaticDamageable3D::get_HP_current() {
	return HP;
}

Ref<Durability> StaticDamageable3D::get_durability() const {
	return durability;
}

void StaticDamageable3D::set_durability(const Ref<Durability> &p_durability) {
	if (p_durability == durability)
		return;
	durability = p_durability;
}


void StaticDamageable3D::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_HP_max", "value"), &StaticDamageable3D::set_HP_max);
	ClassDB::bind_method(D_METHOD("get_HP_max"), &StaticDamageable3D::get_HP_max);

	ClassDB::bind_method(D_METHOD("set_HP", "value"), &StaticDamageable3D::set_HP_current);
	ClassDB::bind_method(D_METHOD("get_HP"), &StaticDamageable3D::get_HP_current);

	ClassDB::bind_method(D_METHOD("damage", "amount", "type"), &StaticDamageable3D::damage);
	
	ClassDB::bind_method(D_METHOD("heal", "amount"), &StaticDamageable3D::heal);

	ClassDB::bind_method(D_METHOD("set_durability", "durability"), &StaticDamageable3D::set_durability);
	ClassDB::bind_method(D_METHOD("get_durability"), &StaticDamageable3D::get_durability);

	ADD_GROUP("Durability", "");
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "durability", PROPERTY_HINT_RESOURCE_TYPE, "Durability"), "set_durability", "get_durability");

	ADD_GROUP("Stats", "");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "hp max", PROPERTY_HINT_RANGE, "1,max float value"), "set_HP_max", "get_HP_max");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "hp current", PROPERTY_HINT_RANGE, "min float value,max float value"), "set_HP", "get_HP");
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


float AnimatableDamageable3D::damage(float amount, int type) {
	float damage_received = (durability.is_valid() ? durability->reduced_damage(amount, (Durability::DamageType)(type & DMG_TYPE_MASK)) : amount);
	HP -= damage_received;
	if (HP <= 0) {
		// TODO: emit a signal here
	}

	return damage_received;
}

/*
	Calculates and returns the difference:
	- negative means not fully healed
	- 0 means exactly fully healed
	- positive means excessive / overheal (currently does nothing special, current HP is just set to max HP value)
*/
float AnimatableDamageable3D::heal(float amount) {
	HP += amount;
	amount = HP - HP_MAX_BASE;

	if (amount > 0)
		HP = HP_MAX_BASE;
		
	return amount;
}

void AnimatableDamageable3D::set_HP_max(float value) {
	if (value >= 1)
		HP_MAX_BASE = value;
}

float AnimatableDamageable3D::get_HP_max() {
	return HP_MAX_BASE;
}

void AnimatableDamageable3D::set_HP_current(float value) {
	HP = value;
}

float AnimatableDamageable3D::get_HP_current() {
	return HP;
}

Ref<Durability> AnimatableDamageable3D::get_durability() const {
	return durability;
}

void AnimatableDamageable3D::set_durability(const Ref<Durability> &p_durability) {
	if (p_durability == durability)
		return;
	durability = p_durability;
}


void AnimatableDamageable3D::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_HP_max", "value"), &AnimatableDamageable3D::set_HP_max);
	ClassDB::bind_method(D_METHOD("get_HP_max"), &AnimatableDamageable3D::get_HP_max);

	ClassDB::bind_method(D_METHOD("set_HP", "value"), &AnimatableDamageable3D::set_HP_current);
	ClassDB::bind_method(D_METHOD("get_HP"), &AnimatableDamageable3D::get_HP_current);

	ClassDB::bind_method(D_METHOD("damage", "amount", "type"), &AnimatableDamageable3D::damage);
	
	ClassDB::bind_method(D_METHOD("heal", "amount"), &AnimatableDamageable3D::heal);

	ClassDB::bind_method(D_METHOD("set_durability", "durability"), &AnimatableDamageable3D::set_durability);
	ClassDB::bind_method(D_METHOD("get_durability"), &AnimatableDamageable3D::get_durability);

	ADD_GROUP("Durability", "");
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "durability", PROPERTY_HINT_RESOURCE_TYPE, "Durability"), "set_durability", "get_durability");

	ADD_GROUP("Stats", "");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "hp max", PROPERTY_HINT_RANGE, "1,max float value"), "set_HP_max", "get_HP_max");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "hp current", PROPERTY_HINT_RANGE, "min float value,max float value"), "set_HP", "get_HP");
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


float RigidBodyDamageable3D::damage(float amount, int type) {
	float damage_received = (durability.is_valid() ? durability->reduced_damage(amount, (Durability::DamageType)(type & DMG_TYPE_MASK)) : amount);
	HP -= damage_received;
	if (HP <= 0) {
		// TODO: emit a signal here
	}

	return damage_received;
}

/*
	Calculates and returns the difference:
	- negative means not fully healed
	- 0 means exactly fully healed
	- positive means excessive / overheal (currently does nothing special, current HP is just set to max HP value)
*/
float RigidBodyDamageable3D::heal(float amount) {
	HP += amount;
	amount = HP - HP_MAX_BASE;

	if (amount > 0)
		HP = HP_MAX_BASE;
		
	return amount;
}

void RigidBodyDamageable3D::set_HP_max(float value) {
	if (value >= 1)
		HP_MAX_BASE = value;
}

float RigidBodyDamageable3D::get_HP_max() {
	return HP_MAX_BASE;
}

void RigidBodyDamageable3D::set_HP_current(float value) {
	HP = value;
}

float RigidBodyDamageable3D::get_HP_current() {
	return HP;
}

Ref<Durability> RigidBodyDamageable3D::get_durability() const {
	return durability;
}

void RigidBodyDamageable3D::set_durability(const Ref<Durability> &p_durability) {
	if (p_durability == durability)
		return;
	durability = p_durability;
}

void RigidBodyDamageable3D::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_HP_max", "value"), &RigidBodyDamageable3D::set_HP_max);
	ClassDB::bind_method(D_METHOD("get_HP_max"), &RigidBodyDamageable3D::get_HP_max);

	ClassDB::bind_method(D_METHOD("set_HP", "value"), &RigidBodyDamageable3D::set_HP_current);
	ClassDB::bind_method(D_METHOD("get_HP"), &RigidBodyDamageable3D::get_HP_current);

	ClassDB::bind_method(D_METHOD("damage", "amount", "type"), &RigidBodyDamageable3D::damage);
	
	ClassDB::bind_method(D_METHOD("heal", "amount"), &RigidBodyDamageable3D::heal);

	ClassDB::bind_method(D_METHOD("set_durability", "durability"), &RigidBodyDamageable3D::set_durability);
	ClassDB::bind_method(D_METHOD("get_durability"), &RigidBodyDamageable3D::get_durability);

	ADD_GROUP("Durability", "");
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "durability", PROPERTY_HINT_RESOURCE_TYPE, "Durability"), "set_durability", "get_durability");

	ADD_GROUP("Stats", "");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "hp max", PROPERTY_HINT_RANGE, "1,max float value"), "set_HP_max", "get_HP_max");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "hp current", PROPERTY_HINT_RANGE, "min float value,max float value"), "set_HP", "get_HP");

}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


float Actor3D::damage(float amount, int type) {
	float damage_received = (durability.is_valid() ? durability->reduced_damage(amount, (Durability::DamageType)(type & DMG_TYPE_MASK)) : amount);
	HP -= damage_received;
	if (HP <= 0) {
		// TODO: emit a signal here
	}

	return damage_received;
}

/*
	Calculates and returns the difference:
	- negative means not fully healed
	- 0 means exactly fully healed
	- positive means excessive / overheal (currently does nothing special, current HP is just set to max HP value)
*/
float Actor3D::heal(float amount) {
	HP += amount;
	amount = HP - HP_MAX_BASE;

	if (amount > 0)
		HP = HP_MAX_BASE;
		
	return amount;
}

void Actor3D::set_HP_max(float value) {
	if (value >= 1)
		HP_MAX_BASE = value;
}

float Actor3D::get_HP_max() {
	return HP_MAX_BASE;
}

void Actor3D::set_HP_current(float value) {
	HP = value;
}

float Actor3D::get_HP_current() {
	return HP;
}

Ref<Durability> Actor3D::get_durability() const {
	return durability;
}

void Actor3D::set_durability(const Ref<Durability> &p_durability) {
	if (p_durability == durability)
		return;
	durability = p_durability;
}

void Actor3D::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_HP_max", "value"), &Actor3D::set_HP_max);
	ClassDB::bind_method(D_METHOD("get_HP_max"), &Actor3D::get_HP_max);

	ClassDB::bind_method(D_METHOD("set_HP", "value"), &Actor3D::set_HP_current);
	ClassDB::bind_method(D_METHOD("get_HP"), &Actor3D::get_HP_current);

	ClassDB::bind_method(D_METHOD("damage", "amount", "type"), &Actor3D::damage);
	
	ClassDB::bind_method(D_METHOD("heal", "amount"), &Actor3D::heal);

	ClassDB::bind_method(D_METHOD("set_durability", "durability"), &Actor3D::set_durability);
	ClassDB::bind_method(D_METHOD("get_durability"), &Actor3D::get_durability);

	ADD_GROUP("Durability", "");
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "durability", PROPERTY_HINT_RESOURCE_TYPE, "Durability"), "set_durability", "get_durability");

	ADD_GROUP("Stats", "");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "hp max", PROPERTY_HINT_RANGE, "1,max float value"), "set_HP_max", "get_HP_max");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "hp current", PROPERTY_HINT_RANGE, "min float value,max float value"), "set_HP", "get_HP");

}