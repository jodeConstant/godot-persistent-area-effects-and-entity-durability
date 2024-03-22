#ifndef DAMAGE_NEGATION_H
#define DAMAGE_NEGATION_H

#include "core/io/file_access.h"
#include "core/io/resource.h"
#include "core/io/resource_loader.h"

/*
    The point of making this a resource is the option to share the same data between multiple entities
*/

/*
    Damage reduction has 2 components, represented by x and y values of a Vector2

    Use DamageThreshold (DT, x value) as a flat damage block.
    The idea is that too small amounts of damage will have no effect at all. Armor would add to these values, acting as an extra coating

    Use damage resistance (DR, y value) as a a feature of an entity, describing their structure / constitution.
    The idea is that different characters, creatures and objects can withstand different damage types, 
    based on whether they are, for example, flexible or brittle, etc.
*/

class Durability : public Resource
{
private:
    GDCLASS(Durability, Resource);
    OBJ_SAVE_TYPE(Durability);

    Vector2 negations[6];

protected:
    static void _bind_methods();

public:
    /* 
        WARNING: do not set enum values explicitly!
        If new types are added, make sure to also add
            - getter and setter functions
            - a corresponding property (in .cpp file)
        UNBLOCKABLE should remain as the last, as it marks the end of the list
    */
    enum DamageType { Impact, Cut, Pierce, Electric, Heat, Chemical, 
        UNBLOCKABLE };

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


    float reduced_damage(float damage, DamageType type);

    Durability();
    Durability( float impact_t,   float impact_r, 
                float cut_t,      float cut_r, 
                float pierce_t,   float pierce_r, 
                float electric_t, float electric_r, 
                float heat_t,     float heat_r, 
                float chemical_t, float chemical_r);

};

VARIANT_ENUM_CAST(Durability::DamageType);

#endif