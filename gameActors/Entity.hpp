#pragma once

#include <string>
#include "SFML/Graphics/CircleShape.hpp"

#define DEFAULT_POS sf::Vector2f(0.0f, 0.0f)
#define DEFAULT_RADIUS 20.0f
#define DEFAULT_COLOR sf::Color::Green
#define DEFAULT_NAME "Entity<TState>"
// TODO: default state ?


template <typename TState>
class Entity
{
private:
	sf::CircleShape mCircleShape;
	std::string mName;
	TState mState;

public:
	Entity<TState>(sf::Vector2f ARGpos = DEFAULT_POS, float ARGgradius = DEFAULT_RADIUS, sf::Color ARGcolor = DEFAULT_COLOR, std::string ARGname = DEFAULT_NAME);
	~Entity<TState>();

	/* Getters & Setters *//**/
	sf::CircleShape GetCircleShape();
	std::string GetName();
	TState GetState();
};