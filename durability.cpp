#include "durability.h"

void Durability::set_impact_defense(const Vector2 &value) {
	//impact_negation = value;
	negations[0] = value;
}

Vector2 Durability::get_impact_defense() {
	//return impact_negation;
	return negations[0];
}

void Durability::set_cut_defense(const Vector2 &value) {
	//cut_negation = value;
	negations[1] = value;
}

Vector2 Durability::get_cut_defense() {
	//return cut_negation;
	return negations[1];
}

void Durability::set_pierce_defense(const Vector2 &value) {
	//pierce_negation = value;
	negations[2] = value;
}

Vector2 Durability::get_pierce_defense() {
	//return pierce_negation;
	return negations[2];
}

void Durability::set_electric_defense(const Vector2 &value) {
	//electric_negation = value;
	negations[3] = value;
}

Vector2 Durability::get_electric_defense() {
	//return electric_negation;
	return negations[3];
}

void Durability::set_heat_defense(const Vector2 &value) {
	//heat_negation = value;
	negations[4] = value;
}

Vector2 Durability::get_heat_defense() {
	//return heat_negation;
	return negations[4];
}

void Durability::set_chemical_defense(const Vector2 &value) {
	//chemical_negation = value;
	negations[5] = value;
}

Vector2 Durability::get_chemical_defense() {
	//return chemical_negation;
	return negations[5];
}

float Durability::reduced_damage(float damage, DamageType type) {
	if ((type > 0) && (type < NUMBER_OF_DMG_TYPES)) {
		damage -= negations[type].x;
		damage -= damage * negations[type].y;
	}
	// Optional TODO: switch statement for special reduction formulas

	return damage;
}

Durability::Durability() : Resource() {}


void Durability::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_impact_defense", "value"), &Durability::set_impact_defense);
    ClassDB::bind_method(D_METHOD("get_impact_defense"), &Durability::get_impact_defense);

    ClassDB::bind_method(D_METHOD("set_cut_defense", "value"), &Durability::set_cut_defense);
    ClassDB::bind_method(D_METHOD("get_cut_defense"), &Durability::get_cut_defense);

    ClassDB::bind_method(D_METHOD("set_pierce_defense", "value"), &Durability::set_pierce_defense);
    ClassDB::bind_method(D_METHOD("get_pierce_defense"), &Durability::get_pierce_defense);

    ClassDB::bind_method(D_METHOD("set_electric_defense", "value"), &Durability::set_electric_defense);
    ClassDB::bind_method(D_METHOD("get_electric_defense"), &Durability::get_electric_defense);

    ClassDB::bind_method(D_METHOD("set_heat_defense", "value"), &Durability::set_heat_defense);
    ClassDB::bind_method(D_METHOD("get_heat_defense"), &Durability::get_heat_defense);

    ClassDB::bind_method(D_METHOD("set_chemical_defense", "value"), &Durability::set_chemical_defense);
    ClassDB::bind_method(D_METHOD("get_chemical_defense"), &Durability::get_chemical_defense);
    
    ClassDB::bind_method(D_METHOD("reduced_damage", "damage", "type"), &Durability::reduced_damage);

    ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "impact_defense", PROPERTY_HINT_NONE, ""), "set_impact_defense", "get_impact_defense");
    ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "cut_defense", PROPERTY_HINT_NONE, ""), "set_cut_defense", "get_cut_defense");
    ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "pierce_defense", PROPERTY_HINT_NONE, ""), "set_pierce_defense", "get_pierce_defense");
    ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "electric_defense", PROPERTY_HINT_NONE, ""), "set_electric_defense", "get_electric_defense");
    ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "heat_defense", PROPERTY_HINT_NONE, ""), "set_heat_defense", "get_heat_defense");
    ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "chemical_defense", PROPERTY_HINT_NONE, ""), "set_chemical_defense", "get_chemical_defense");

    BIND_ENUM_CONSTANT(Impact);
    BIND_ENUM_CONSTANT(Cut);
    BIND_ENUM_CONSTANT(Pierce);
    BIND_ENUM_CONSTANT(Electric);
    BIND_ENUM_CONSTANT(Heat);
    BIND_ENUM_CONSTANT(Chemical);
    BIND_ENUM_CONSTANT(NONE);
}