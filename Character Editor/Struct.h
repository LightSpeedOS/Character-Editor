#pragma once

enum mainMenu
{
	Name = 1,
	Health,
	Damage,
	Level,
	Range,
	Quit
};

struct Player
{
	string name;
	int health;
	int damage;
	int level;
};