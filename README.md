# Overview

The purpose of this module is to add extended area effect options and entity durability resources:

- `AreaEffect3D`: a class derived from `Area3D` that can keep track of nodes it is in contact with
- `Durability`: a class derived from `Resource` that details an entity's resistance to specific damage types
  - Changing existing damage types should be easy, but requires rewriting several parts of the code, to extend internal array as well as to add getter and setter functions, properties and enums.
- Classes derived from each of the 3 built-in classes that derive from `PhysicsBody3D`, each adding durability mechanics / functionalities:
  - `StaticDamageable3D` derived from `StaticBody3D`
  - `AnimatableDamageable3D` derived from `AnimatableBody3D`
  - `Actor3D` derived from `CharacterBody3D`

## Details

*To be added*

## TODO / plans

- Test `AreaEffect3D` and damageables in practice

Made for Godot version 4.3 (updated used source from 4.2). Not tested with older versions, should work with 4.2, but will require correcting some of the included headers' paths. The contents should be placed in modules folder, see [Custom Godot modules in C++](https://docs.godotengine.org/en/stable/contributing/development/core_and_modules/custom_modules_in_cpp.html)

## Licenses

Contents of this repository are released under the terms of the MIT license, see [here](LICENSE.txt).

Godot game engine license can be found [here](https://godotengine.org/license/).
