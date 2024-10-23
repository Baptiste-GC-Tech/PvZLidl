#include "Behaviour.hpp"
//#include "IdleAction.hpp"

#include "../gameActors/Entity.hpp"
#include "Transition.hpp"

/*
   Constru & Destru
*/
//
template <typename TState>
Behaviour<TState>::Behaviour() { /* Does nothing */ }
template <typename TState>
Behaviour<TState>::~Behaviour()
{
    for (auto it : mTransitions)
    {
        for (int i = 0; i < it.second.size(); ++i)
        {
            delete it.second[i];
        }
    }

    for (auto it : mActions)
    {
        for (int i = 0; i < it.second.size(); ++i)
        {
            delete it.second[i];
        }
    }
}


/*
   Current state triggerers
*/
// Calls all of the initialization Actions of the current state of an Entity<TState>
template <typename TState>
void Behaviour<TState>::AllOnStateEnter(Entity<TState>* entity)
{
    for (const auto& a : mActions[entity->getState()])
    {
        a->Start(entity);
    }
}
// Calls all of the routines (Action and Transition attempt) of the current state of an Entity<TState>
template <typename TState>
void Behaviour<TState>::AllUpdate(Entity<TState>* entity)
{
    for (const auto& a : mActions[entity->getState()])
    {
        a->Update(entity);
    }

    for (const auto& a : mTransitions[entity->getState()])
    {
        a->Try(entity);
    }
}
// Calls all of the de-initialization Actions of the current state of an Entity<TState>
template <typename TState>
void Behaviour<TState>::AllOnStateExit(Entity<TState>* entity)
{
    for (const auto & a : mActions[entity->getState()])
    {
        a->End(entity);
    }
}


/*
   Map fillers
*/
// Adds a Transition for a state
template <typename TState>
void Behaviour<TState>::AddTransition(TState key, Transition<TState>* value)
{
    mTransitions[key].push_back(value);
}
// Adds an Action for a state
template <typename TState>
void Behaviour<TState>::AddAction(TState key, Action* value)
{
    mActions[key].push_back(value);
}