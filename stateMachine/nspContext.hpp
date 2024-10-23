#pragma once

// Knows about all states for any given Entity<TState>
namespace Context
{
	// States of Plant entities
	enum class PlantState
	{
		UNKNOWN = 0,
		Idle,
		Shoot,
		Cooldown,
		Reload,
	};

	// States of Zombie entities
	enum class ZombieState
	{
		UNKNOWN = 0,
		Walk,
		Attack,
		Cooldown,
	};

	// States of Projectil entities
	enum class ProjectilState
	{
		UNKNOWN = 0,
		Travel,
		Hit,
	};
};
