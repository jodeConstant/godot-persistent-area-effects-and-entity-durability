#ifndef AREAEFFECT3D_H
#define AREAEFFECT3D_H

#include "../../scene/3d/physics/area_3d.h"
#include "../../scene/3d/physics/physics_body_3d.h"

/*
    TODO:
    - make nodes list typed?
        - add functionality to guarantee clearing pointers to nodes that will be de-loaded
*/

class AreaEffect3D : public Area3D
{
    private:
        GDCLASS(AreaEffect3D, Area3D);
        
        Vector</*Ref<PhysicsBody3D>*/Variant> affected;
        int64_t a_length;
        int64_t first_free_slot;
    
    protected:
	    static void _bind_methods();
    
    public:
        AreaEffect3D();
        ~AreaEffect3D();

        bool has_node(Variant node);
        bool add_node(Variant node);
        bool remove_node(Variant node);
        void clear_affected();
};

#endif