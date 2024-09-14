#include "damageable_entities.h"

#include "scene/scene_string_names.h"// same as in physics_body_3d.cpp, just in case


float StaticDamageable3D::hit(float amount, Durability::DamageType type) {
	float damage_received = (durability.is_valid() ? durability->reduced_damage(amount, type) : amount);
	HP -= damage_received;
	if (HP <= 0) {
		// TODO: emit a signal here
	}
}

float StaticDamageable3D::heal(float amount) {
	HP += amount;
	/*
		calculate and return the difference:
			0 is fully healed
			negative means not fully healed
			positive means overheal
		can use that for something later
	*/
	amount = HP - HP_MAX;
	return amount;
}

void StaticDamageable3D::set_HP_MAX(float value) {
	if (value >= 1)
		HP_MAX = value;
}

float StaticDamageable3D::get_HP_MAX() {
	return HP_MAX;
}

void StaticDamageable3D::set_HP(float value) {
	HP = value;
}

float StaticDamageable3D::get_HP() {
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
	ClassDB::bind_method(D_METHOD("set_HP_MAX", "value"), &StaticDamageable3D::set_HP_MAX);
	ClassDB::bind_method(D_METHOD("get_HP_MAX"), &StaticDamageable3D::get_HP_MAX);

	ClassDB::bind_method(D_METHOD("set_HP", "value"), &StaticDamageable3D::set_HP);
	ClassDB::bind_method(D_METHOD("get_HP"), &StaticDamageable3D::get_HP);

	ClassDB::bind_method(D_METHOD("hit", "amount", "type"), &StaticDamageable3D::hit);
	
	ClassDB::bind_method(D_METHOD("heal", "amount"), &StaticDamageable3D::heal);

	ClassDB::bind_method(D_METHOD("set_durability", "durability"), &StaticDamageable3D::set_durability);
	ClassDB::bind_method(D_METHOD("get_durability"), &StaticDamageable3D::get_durability);

	ADD_GROUP("Durability", "");
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "durability", PROPERTY_HINT_RESOURCE_TYPE, "Durability"), "set_durability", "get_durability");
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


float AnimatableDamageable3D::hit(float amount, Durability::DamageType type) {
	float damage_received = (durability.is_valid() ? durability->reduced_damage(amount, type) : amount);
	HP -= damage_received;
	if (HP <= 0) {
		// TODO: emit a signal here
	}
}

float AnimatableDamageable3D::heal(float amount) {
	HP += amount;
	/*
		calculate and return the difference:
			0 is fully healed
			negative means not fully healed
			positive means overheal
		can use that for something later
	*/
	amount = HP - HP_MAX;
	return amount;
}

void AnimatableDamageable3D::set_HP_MAX(float value) {
	if (value >= 1)
		HP_MAX = value;
}

float AnimatableDamageable3D::get_HP_MAX() {
	return HP_MAX;
}

void AnimatableDamageable3D::set_HP(float value) {
	HP = value;
}

float AnimatableDamageable3D::get_HP() {
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
	ClassDB::bind_method(D_METHOD("set_HP_MAX", "value"), &AnimatableDamageable3D::set_HP_MAX);
	ClassDB::bind_method(D_METHOD("get_HP_MAX"), &AnimatableDamageable3D::get_HP_MAX);

	ClassDB::bind_method(D_METHOD("set_HP", "value"), &AnimatableDamageable3D::set_HP);
	ClassDB::bind_method(D_METHOD("get_HP"), &AnimatableDamageable3D::get_HP);

	ClassDB::bind_method(D_METHOD("hit", "amount", "type"), &AnimatableDamageable3D::hit);
	
	ClassDB::bind_method(D_METHOD("heal", "amount"), &AnimatableDamageable3D::heal);

	ClassDB::bind_method(D_METHOD("set_durability", "durability"), &AnimatableDamageable3D::set_durability);
	ClassDB::bind_method(D_METHOD("get_durability"), &AnimatableDamageable3D::get_durability);

	ADD_GROUP("Durability", "");
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "durability", PROPERTY_HINT_RESOURCE_TYPE, "Durability"), "set_durability", "get_durability");
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


float Entity3D::hit(float amount, Durability::DamageType type) {
	float damage_received = (durability.is_valid() ? durability->reduced_damage(amount, type) : amount);
	HP -= damage_received;
	if (HP <= 0) {
		// TODO: emit a signal here
	}
}

float Entity3D::heal(float amount) {
	HP += amount;
	/*
		calculate and return the difference:
			0 is fully healed
			negative means not fully healed
			positive means overheal
		can use that for something later
	*/
	amount = HP - HP_MAX;
	return amount;
}

void Entity3D::set_HP_MAX(float value) {
	if (value >= 1)
		HP_MAX = value;
}

float Entity3D::get_HP_MAX() {
	return HP_MAX;
}

void Entity3D::set_HP(float value) {
	HP = value;
}

float Entity3D::get_HP() {
	return HP;
}

Ref<Durability> Entity3D::get_durability() const {
	return durability;
}

void Entity3D::set_durability(const Ref<Durability> &p_durability) {
	if (p_durability == durability)
		return;
	durability = p_durability;
}

void Entity3D::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_HP_MAX", "value"), &Entity3D::set_HP_MAX);
	ClassDB::bind_method(D_METHOD("get_HP_MAX"), &Entity3D::get_HP_MAX);

	ClassDB::bind_method(D_METHOD("set_HP", "value"), &Entity3D::set_HP);
	ClassDB::bind_method(D_METHOD("get_HP"), &Entity3D::get_HP);

	ClassDB::bind_method(D_METHOD("hit", "amount", "type"), &Entity3D::hit);
	
	ClassDB::bind_method(D_METHOD("heal", "amount"), &Entity3D::heal);

	ClassDB::bind_method(D_METHOD("set_durability", "durability"), &Entity3D::set_durability);
	ClassDB::bind_method(D_METHOD("get_durability"), &Entity3D::get_durability);

	ADD_GROUP("Durability", "");
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "durability", PROPERTY_HINT_RESOURCE_TYPE, "Durability"), "set_durability", "get_durability");
}