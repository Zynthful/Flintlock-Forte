#pragma once
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

// forward declarations
class Component;
class GameObject;

// component id is size_t
using ComponentID = std::size_t;

// get the next id for a type of component
// inline: put into place wherever we use it
inline ComponentID GetComponentTypeID()
{
	static ComponentID lastID = 0;
	return lastID++;	// get next id
}

template <typename T> inline ComponentID GetComponentTypeID() noexcept
{
	static ComponentID typeID = GetComponentTypeID();	// generate new lastID and use that for our type ID
	return typeID;
}

// max components that an entity can hold
constexpr std::size_t maxComponents = 32;

// if we need to find out if in an entity has a selection of componeents, we'll be able to compare whether it has it or not
// i.e. we can generate a bitset, pass it in, and if it matches the signature of the entities, we'll know we have all the components we need
using ComponentBitSet = std::bitset<maxComponents>;

// array of component pointers at a length of maxComponents
using ComponentArray = std::array<Component*, maxComponents>;