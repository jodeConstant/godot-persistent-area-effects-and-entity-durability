/* register_types.cpp */

#include "register_types.h"

#include "core/object/class_db.h"
#include "areaeffect3d.h"
#include "durability.h"
#include "entityresourceloader.h"

void initialize_entityeffects_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
			return;
	}
	ClassDB::register_class<AreaEffect3D>();
	ClassDB::register_class<Durability>();
	ClassDB::register_class<EntityResourceLoader>();
}

void uninitialize_entityeffects_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
			return;
	}
   // Nothing to do here in this example.
}