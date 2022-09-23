/// =========================
/// ENTITY COMPONENT SYSTEM
/// =========================
/// Limitations:
///  - Assumes each GameObject will only have max 1 component of any type (this is because we're using a bitset to identify if a GameObject has a component)
///  - Component's owning GameObject cannot currently be changed after creation

#pragma once
#include <array>	// to store array of components and entities
#include <bitset>	// to check if an entity has a component
#include <iostream>	// to debug

// forward declarations
class GameObject;
class Component;

// max GameObjects allowed at any given time
constexpr std::size_t maxGameObjects = 1000;
// max components allowed to be on a component at any given time
constexpr std::size_t maxComponents = 32;

// typedef, each component type has an unsigned int id that we use to identify what type of component it is
using ComponentTypeID = std::size_t;

// typedef for array of bits
using ComponentBitset = std::bitset<maxComponents>;

// typedef for an array of components, capped to maxComponents
using ComponentList = std::array<Component*, maxComponents>;

/// <summary>
/// returns a unique ID which should be assigned to a component
/// </summary>
/// <returns>a unique ID for a component type</returns>
inline ComponentTypeID GetUniqueTypeID()	// for some reason, this needs to be inline, i don't know why...
{
	// static: so that it initialises to 0u then increases every time this function is called
	// initialise to unsigned int 0
	static ComponentTypeID lastID = 0u;
	return lastID++;
}

/// <summary>
/// Gets the ComponentTypeID assigned to a Component from the type fed in
/// </summary>
/// <typeparam name="T">Component to retrieve the ComponentTypeID of</typeparam>
/// <returns>The ComponentTypeID assigned to T, if it exists and if T inherits from Component</returns>
template<typename T>
ComponentTypeID GetComponentTypeID() noexcept
{
	// check that T inherits from Component
	static_assert(std::is_base_of<Component, T>::value, "GetComponentTypeID: Given type does not inherit from Component!");

	static const ComponentTypeID id = GetUniqueTypeID();
	return id;
}