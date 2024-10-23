#include "Entity<TState>.hpp"

/*
   Constru & Destru
*/
//
template <typename TState>
Entity<TState><TState>::Entity<TState>(sf::Vector2f ARGpos, float ARGgradius, sf::Color ARGcolor, std::string ARGname)
{
	mCircleShape.setPosition(ARGpos);
	mCircleShape.setRadius(ARGgradius);
	mCircleShape.setFillColor(ARGcolor);
	mName = ARGname;
}
//
template <typename TState>
Entity<TState><TState>::~Entity<TState>() { /* Does nothing */ }

/*
   Getters & Setters
*/
//
template <typename TState>
sf::CircleShape Entity<TState><TState>::GetCircleShape() { return mCircleShape; }
//
template <typename TState>
std::string Entity<TState><TState>::GetName() { return mName; }
//
template <typename TState>
TState Entity<TState><TState>::GetState() { return mState; }