#pragma once

class Entity<TState>;

class Condition 
{
public:
    virtual bool Test(Entity<TState> * entity) = 0;
};
