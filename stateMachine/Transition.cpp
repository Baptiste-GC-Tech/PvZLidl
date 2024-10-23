#include "Transition.hpp"
#include "gameActors/Entity<TState>.hpp"


/*
   Transitional wonders
*/
// Changes manually the state of an Entity<TState>
template <typename TState>
void Transition<TState>::SetTargetState(TState target_state)
{
    mTargetState = target_state;
}
// Adds a condition to be met in order to transition to the next state
template <typename TState>
void Transition<TState>::AddCondition(Condition* condition)
{
    mConditions.push_back(condition);
}
// Attempts to change the state of an Entity<TState>, if all conditions are met
template <typename TState>
void Transition<TState>::TryToChangeState(Entity<TState>* entity)
{
    int true_tests = 0;
    for (const auto &c : mConditions)
    {
        true_tests += c->Test(entity);
    }
    if (true_tests != 0 && true_tests == mConditions.size())
    {
        entity->setState(mTargetState);
    }
}
