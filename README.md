# Overview

The purpose of this module is to add extended area effect options and entity durability resources:

- `AreaEffect3D`: a class derived from `Area3D` that can keep track of nodes it is in contact with
- `Durability`: a class derived from `Resource` that details an entity's resistance to specific damage types
- Classes derived from each of the 3 built-in classes that derive from `PhysicsBody3D`, each adding durability mechanics / functionalities:
  - `StaticDamageable3D` derived from `StaticBody3D`
  - `AnimatableDamageable3D` derived from `AnimatableBody3D`
  - `RigidBodyDamageable3D` derived from `RigidBody3D`
  - `Actor3D` derived from `CharacterBody3D`

## Details

### AreaEffect3D

`AreaEffect3D` stores references to nodes of following custom types:

- `StaticDamageable3D`
- `AnimatableDamageable3D`
- `Actor3D`

Types are checked when attempting to add to the array. Stored pointers are typed as `CollisionObject3D` (the type that is inherited by both `PhysicsBody3D` and `Area3D`).
The array of pointers is a `LocalVector`, which retains its allocated size, to avoid reallocation of memory on adding and removing pointers.

Curently has built-in functions to:

- damage all affected nodes
- heal all affected nodes
- get the affected node count
- retrieve one or all afected nodes

**NOTE:** Current version of retrieving all affected nodes is not very efficient, as it involves constructing a new array on each function call; better to implement often-used functions that are applied to all nodes in C++

### Durabilty

`Resource` sub-type that holds flat value and multiplicative reduction values per damage type, that can be adjusted in editor and saved to file(s) like any other `Resource`

Changing existing damage types should be easy, but requires rewriting several parts of the code, to extend internal array as well as to add getter and setter functions, properties and enums.

### Damageable types

As mentioned above, damageable types are:

- `StaticDamageable3D` derived from `StaticBody3D`
- `AnimatableDamageable3D` derived from `AnimatableBody3D`
- `RigidBodyDamageable3D` derived from `RigidBody3D`
- `Actor3D` derived from `CharacterBody3D`

All these types have the same added features, added separately, as multiple inheritance doesn't work well with Godot / GDscript. An alternative way to implement these features would be to add the needed data to `PhysicsBody3D`, but this would make **all** of the derived types "damageable".

Current features are:

- HP variables:

  - current HP
  - base maximum HP (derived maximum HP, after modifiers not yet implemented)

- `float damage(float amount, int type)` function, that (potentially) reduces HP, based on pre-reduction amount and type, and returns the amount of damage actually received
- `float heal(float amount)` function, that restores a specified amount of HP and returns a difference between maximum and current HP:

  - negative means not fully healed
  - 0 means exactly fully healed
  - positive means excessive / overheal (currently does nothing special, current HP is just set to max HP value)

## TODO / plans

- Test `AreaEffect3D` and damageables in practice
- Unify damaging and healing under HP (hit points / health) modification system, and add different types of HP restoration, that work on different types of entities.
- Implement / find / add support for a generic way to call functions on all of the nodes affected by an `AreaEffect3D`

## Compatibility

Made for Godot version 4.3 (updated used source from 4.2). Not tested with older versions, should work with 4.2, but will require correcting some of the included headers' paths. The contents should be placed in modules folder, see [Custom Godot modules in C++](https://docs.godotengine.org/en/stable/contributing/development/core_and_modules/custom_modules_in_cpp.html)

## Licenses

Contents of this repository are released under the terms of the MIT license, see [here](LICENSE.txt).

Godot game engine license can be found [here](https://godotengine.org/license/).
