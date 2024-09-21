#ifndef AREAEFFECT3D_H
#define AREAEFFECT3D_H

#include "../../scene/3d/physics/area_3d.h"
#include "../../scene/3d/physics/physics_body_3d.h"
#include "core/templates/pooled_list.h"
#include "core/templates/local_vector.h"

/*
    TODO:
    - make nodes list typed?
        - add functionality to guarantee clearing pointers to nodes that will be de-loaded
*/

class AreaEffect3D : public Area3D
{
    private:
        GDCLASS(AreaEffect3D, Area3D);
        
        //pooled array: reserve on construction, (probably) never call clear() method
        LocalVector<Variant, uint32_t, false, true> affected;
    
    protected:
	    static void _bind_methods();
    
    public:
        AreaEffect3D(int max_affected);
        AreaEffect3D() : AreaEffect3D(20) {};
        ~AreaEffect3D();

        bool has_affected_node(const Variant &node/*const Ref<PhysicsBody3D> &node*/);
        bool add_affected_node(Variant node/*const Ref<PhysicsBody3D> &node*/);
        bool remove_affected_node(const Variant &node/*const Ref<PhysicsBody3D> &node*/);
        void clear_affected();
};

#endif