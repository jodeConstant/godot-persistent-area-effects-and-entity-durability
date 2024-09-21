#ifndef DAMAGEABLE_ENTITIES
#define DAMAGEABLE_ENTITIES

#include "../../scene/3d/physics/static_body_3d.h"
#include "../../scene/3d/physics/animatable_body_3d.h"
#include "../../scene/3d/physics/character_body_3d.h"
#include "durability.h"

class StaticDamageable3D : public StaticBody3D {
    
private:
    GDCLASS(StaticDamageable3D, StaticBody3D)
	
	float HP_MAX;
	float HP;

	Ref<Durability> durability;

protected:
    static void _bind_methods();

public:
	float hit(float amount, Durability::DamageType type);
	float heal(float amount);

    void set_HP_max(float value);
    float get_HP_max();

    void set_HP_current(float value);
    float get_HP_current();
	
	Ref<Durability> get_durability() const;
	void set_durability(const Ref<Durability> &durability_resource);
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class AnimatableDamageable3D : public AnimatableBody3D {
    
private:
    GDCLASS(AnimatableDamageable3D, AnimatableBody3D)
	
	float HP_MAX;
	float HP;

	Ref<Durability> durability;

protected:
    static void _bind_methods();

public:
	float hit(float amount, Durability::DamageType type);
	float heal(float amount);

    void set_HP_max(float value);
    float get_HP_max();

    void set_HP_current(float value);
    float get_HP_current();
	
	Ref<Durability> get_durability() const;
	void set_durability(const Ref<Durability> &durability_resource);
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class Actor3D : public CharacterBody3D {
    
private:
    GDCLASS(Actor3D, CharacterBody3D)
	
	float HP_MAX_BASE;
	float HP_MAX_DERIVED;// with modifiers, to be implemented
	float HP;

	Ref<Durability> durability;

protected:
    static void _bind_methods();

public:
	float hit(float amount, Durability::DamageType type);
	float heal(float amount);

    void set_HP_max(float value);
    float get_HP_max();

    void set_HP_current(float value);
    float get_HP_current();
	
	Ref<Durability> get_durability() const;
	void set_durability(const Ref<Durability> &durability_resource);
};

#endif