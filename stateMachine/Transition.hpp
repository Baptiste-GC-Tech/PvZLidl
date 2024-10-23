#pragma once

#include <vector>
#include "nspContext.hpp"
#include "Condition.hpp"

/* Forward declarations */
class Entity<TState>;

// Template class, able to accept any gameActor state-set. Represents a reaction to being in AND changing of state
template <typename TState>
class Transition
{
protected:
    TState mTargetState;
    std::vector<Condition*> mConditions;

public:
    /* Transitional wonders *//**/
    void TryToChangeState(Entity<TState>* entity);
    void SetTargetState(TState target_state);
    void AddCondition(Condition* condition);
};
