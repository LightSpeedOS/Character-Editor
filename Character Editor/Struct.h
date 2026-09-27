#pragma once

enum mainMenu
{
	Name = 1,
	Health,
	Damage,
	Level,
	List,
	Range,
	Quit
};

enum EditMenu
{
	botName = 1,
	botHealth,
};

struct Player
{
	string name;
	int health;
	int damage;
	int level;
	int equippedWeapon;
};

struct Bot
{
	string name;
	int health;
};

struct Weapon
{
	string name;
	int damage;
};