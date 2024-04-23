#ifndef ENTITY_RESOURCE_MANAGER_H
#define ENTITY_RESOURCE_MANAGER_H

#include "core/io/resource_loader.h"
#include "core/io/resource_saver.h"
#include "core/io/resource.h"
#include "durability.h"

class EntityResourceLoader : public ResourceFormatLoader
{
private:
	GDCLASS(EntityResourceLoader, ResourceFormatLoader);
    
public:
	virtual /*RES*/Ref<Durability> load(const String &p_path, const String &p_original_path, Error *r_error = NULL);
	virtual void get_recognized_extensions(List<String> *r_extensions) const;
	virtual bool handles_type(const String &p_type) const;
	virtual String get_resource_type(const String &p_path) const;
};

class ResourceFormatSaverJson : public ResourceFormatSaver {
	GDCLASS(ResourceFormatSaverJson, ResourceFormatSaver);
public:
	virtual Error save(const String &p_path, const /*RES*/Ref<Durability> &p_resource, uint32_t p_flags = 0);
	virtual bool recognize(const /*RES*/Ref<Durability> &p_resource) const;
	virtual void get_recognized_extensions(const /*RES*/Ref<Durability> &p_resource, List<String> *r_extensions) const;
};

#endif