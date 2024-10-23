#pragma once

class Entity<TState>;

// ABSTRACT. Represents stuff to do when in a state, including entering, exiting, and stying in that state
class Action
{
public:
    virtual void Start(Entity<TState> * entity) = 0;
    virtual void Update(Entity<TState> * entity) = 0;
    virtual void End(Entity<TState> * entity) = 0;
};
