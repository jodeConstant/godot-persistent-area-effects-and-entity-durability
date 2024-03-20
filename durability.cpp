#include "durability.h"

void Durability::set_impact_defense(const Vector2 &value) {
	negations[0] = value;
}

Vector2 Durability::get_impact_defense() {
	return negations[0];
}

void Durability::set_cut_defense(const Vector2 &value) {
	negations[1] = value;
}

Vector2 Durability::get_cut_defense() {
	return negations[1];
}

void Durability::set_pierce_defense(const Vector2 &value) {
	negations[2] = value;
}

Vector2 Durability::get_pierce_defense() {
	return negations[2];
}

void Durability::set_electric_defense(const Vector2 &value) {
	negations[3] = value;
}

Vector2 Durability::get_electric_defense() {
	return negations[3];
}

void Durability::set_heat_defense(const Vector2 &value) {
	negations[4] = value;
}

Vector2 Durability::get_heat_defense() {
	return negations[4];
}

void Durability::set_chemical_defense(const Vector2 &value) {
	negations[5] = value;
}

Vector2 Durability::get_chemical_defense() {
	return negations[5];
}

/*
Durability::Durability() : Resource() {
	negations[0] = Vector2(0, 0);
	negations[1] = Vector2(0, 0);
	negations[2] = Vector2(0, 0);
	negations[3] = Vector2(0, 0);
	negations[4] = Vector2(0, 0);
	negations[5] = Vector2(0, 0);
}

Durability::Durability( float impact_t,   float impact_r, 
				float cut_t,      float cut_r, 
				float pierce_t,   float pierce_r, 
				float electric_t, float electric_r, 
				float heat_t,     float heat_r, 
				float chemical_t, float chemical_r) : Resource()
{
	negations[0] = Vector2(impact_t,    impact_r);
	negations[1] = Vector2(cut_t,       cut_r);
	negations[2] = Vector2(pierce_t,    pierce_r);
	negations[3] = Vector2(electric_t,  electric_r);
	negations[4] = Vector2(heat_t,      heat_r);
	negations[5] = Vector2(chemical_t,  chemical_r);
}
*/

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

	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "impact_defense", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_EDITOR), "set_impact_defense", "get_impact_defense");
	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "cut_defense", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_EDITOR), "set_cut_defense", "get_cut_defense");
	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "pierce_defense", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_EDITOR), "set_pierce_defense", "get_pierce_defense");
	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "electric_defense", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_EDITOR), "set_electric_defense", "get_electric_defense");
	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "heat_defense", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_EDITOR), "set_heat_defense", "get_heat_defense");
	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "chemical_defense", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_EDITOR), "set_chemical_defense", "get_chemical_defense");
}