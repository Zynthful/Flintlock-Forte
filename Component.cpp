#include "Component.h"

Component::~Component()
{

}

void Component::Initialise()
{
}

void Component::Update(double deltaTime)
{
}

void Component::Render()
{
}

GameObject* Component::GetOwner()
{
    return owner;
}

void Component::SetOwner(GameObject* obj)
{
    owner = obj;
    // todo: actually make this work
    // i.e.
    // 1. remove component from original owner
    // 2. add this component to new owner
}
