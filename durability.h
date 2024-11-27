#ifndef DAMAGE_NEGATION_H
#define DAMAGE_NEGATION_H

#include "core/io/resource.h"
#include "core/math/vector2.h"
#include "core/io/resource_loader.h"
#include "core/io/file_access.h"
#include "core/variant/variant_parser.h"

/*
    The point of making this a resource is the option to share the same data between multiple entities
*/

/*
    Damage reduction has 2 components, represented by x and y values of a Vector2

    Use Damage Threshold (DT, x value) as a flat damage block.
    The idea is that too small amounts of damage will have no effect at all. Armor would add to these values, acting as an extra coating

    Use Damage Resistance (DR, y value) as a a feature of an entity, describing their structure / constitution.
    The idea is that different characters, creatures and objects can withstand different damage types, 
    based on whether they are, for example, flexible or brittle, etc.
*/

#define DMG_TYPE_MASK 0b1111// max 16 types
#define HALF_DAMAGE_THRESHOLD 100.0f

class Durability : public Resource
{
private:
    GDCLASS(Durability, Resource);

protected:
    static void _bind_methods();

public:
    /* 
        NOTE: types correspond to [array index - 1] (or just array index, if NONE is removed or movet to end?)
        If new types are added, make sure to also add
            - getter and setter functions
            - a corresponding properties (in .cpp files)
    */
    enum DamageType : int { DMG_TYPE_NONE, Impact, Cut, Pierce, Electric, Heat, Chemical, 
        DMG_TYPE_ENUM_END };// keep this is last enum

    void set_impact_defense(const Vector2 &value);
    Vector2 get_impact_defense();

    void set_cut_defense(const Vector2 &value);
    Vector2 get_cut_defense();
    
    void set_pierce_defense(const Vector2 &value);
    Vector2 get_pierce_defense();
    
    void set_electric_defense(const Vector2 &value);
    Vector2 get_electric_defense();
    
    void set_heat_defense(const Vector2 &value);
    Vector2 get_heat_defense();
    
    void set_chemical_defense(const Vector2 &value);
    Vector2 get_chemical_defense();

    float reduced_damage(float damage, int type);

    Durability();

private:
    Vector2 negations[DMG_TYPE_ENUM_END - 1];

};

VARIANT_ENUM_CAST(Durability::DamageType);

#endif