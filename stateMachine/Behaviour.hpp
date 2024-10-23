#pragma once

#include "nspContext.hpp"
#include <map>
#include <vector>

/* Forward delcarations */
class Action;
class Entity<TState>;
template <typename TState> class Transition;

// Template class, able to accept any gameActor state-set. Represents a reaction to being in AND changing of state
template <typename TState>
class Behaviour
{
private:
    std::map< TState, std::vector<Action*> > mActions;            // Contains an Action to perform when in a TState
    std::map< TState, std::vector<Transition<TState>*> > mTransitions;    // Contains a Transition to perform when entering/leaving a state

public:
    Behaviour();
    ~Behaviour();

    /* Current state triggerers *//**/
    void AllOnStateEnter(Entity<TState> *entity);
    void AllUpdate(Entity<TState> *entity);
    void AllOnStateExit(Entity<TState> *entity);

    /* Map fillers *//**/
    void AddAction(TState key, Action* value);
    void AddTransition(TState key, Transition<TState>* value);
};
