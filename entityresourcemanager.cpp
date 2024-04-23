#include "entityresourcemanager.h"
#include "durability.h"

#include "scene/resources/resource_format_text.h"

// ===================================================================
// ============================= LOADING =============================
// ===================================================================

/*RES*/Ref<Durability> EntityResourceLoader::load(const String &p_path, const String &p_original_path, Error *r_error) {
Ref<Durability> ent = memnew(Durability);
	if (r_error) {
			*r_error = OK;
	}
	Error err = ent->load_file(p_path);
	return ent;
}

void EntityResourceLoader::get_recognized_extensions(List<String> *r_extensions) const {
	if (!r_extensions->find("ent")) {
			r_extensions->push_back("ent");
	}
}

String EntityResourceLoader::get_resource_type(const String &p_path) const {
	return "Resource";
}

bool EntityResourceLoader::handles_type(const String &p_type) const {
	return ClassDB::is_parent_class(p_type, "Resource");
}

// ===================================================================
// ============================= SAVING ==============================
// ===================================================================

Error ResourceFormatSaverJson::save(const String &p_path, const /*RES*/Ref<Durability> &p_resource, uint32_t p_flags) {
	Ref<Durability> ent = memnew(Durability);
	Error error = ent->save_file(p_path, p_resource);
	return error;
}

bool ResourceFormatSaverJson::recognize(const /*RES*/Ref<Durability> &p_resource) const {
	return Object::cast_to<Durability>(*p_resource) != NULL;
}

void ResourceFormatSaverJson::get_recognized_extensions(const /*RES*/Ref<Durability> &p_resource, List<String> *r_extensions) const {
	if (Object::cast_to<Durability>(*p_resource)) {
			r_extensions->push_back("ent");
	}
}