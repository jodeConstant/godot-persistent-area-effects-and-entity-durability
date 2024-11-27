#ifndef AREAEFFECT3D_H
#define AREAEFFECT3D_H

#include "../../scene/3d/physics/area_3d.h"
#include "../../scene/3d/physics/physics_body_3d.h"
#include "core/templates/pooled_list.h"
#include "core/templates/local_vector.h"

class AreaEffect3D : public Area3D
{
    private:
        GDCLASS(AreaEffect3D, Area3D);
        
        //pooled array: reserve on construction, (probably) never call clear() method
        LocalVector<CollisionObject3D *, uint32_t, false, true> affected;
        PackedByteArray stored_types;
    
    protected:
	    static void _bind_methods();
    
    public:
        AreaEffect3D(int max_affected);
        AreaEffect3D() : AreaEffect3D(16) {};
        ~AreaEffect3D();

        bool has_affected_node(Node3D* const node);
        bool add_affected_node(Node3D* const node);
        bool remove_affected_node(Node3D* const node);
        void clear_affected();

        void damage_all(float amount, int type);
        void heal_all(float amount);

        uint64_t get_affected_count() const;
        CollisionObject3D *get_affected(int idx) const;
        TypedArray<CollisionObject3D> get_all_affected() const;
};

#endif