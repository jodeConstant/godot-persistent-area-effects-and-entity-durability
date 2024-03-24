# Overview

The purpose of this module is to add extended area effect options and entity durability resources:
- A class derived from Area3D that can keep track of nodes it is in contact with
- A class derived from Resource that details an entity's resistance to specific damage types
  - Changing existing damage types should be easy, but requires rewriting parts of the class and re-compiling

The Durability resource class is not yet functional. Current issues:
- Durability resources are not saved, reverting to 0 values on reload
  - TODO: Write a special resource file save and load class(es) and functions
- `reduced_damage` function does not work, returns unmodified value
  - May be related to save and load issues

Made for version 4.2, not tested with other versions. The contents should be placed in modules folder, see [Custom Godot modules in C++] (https://docs.godotengine.org/en/stable/contributing/development/core_and_modules/custom_modules_in_cpp.html)
Godot license: https://godotengine.org/license/

Will document the features further soon...
