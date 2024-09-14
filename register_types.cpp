/* register_types.cpp */

#include "register_types.h"

#include "core/object/class_db.h"
#include "areaeffect3d.h"
#include "durability.h"
#include "damageable_entities.h"

void initialize_entityeffects_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
			return;
	}
	ClassDB::register_class<AreaEffect3D>();
	ClassDB::register_class<Durability>();

	ClassDB::register_class<StaticDamageable3D>();
	ClassDB::register_class<AnimatableDamageable3D>();
	ClassDB::register_class<Entity3D>();
}

void uninitialize_entityeffects_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
			return;
	}
   // The example / template had nothing to do here.
}