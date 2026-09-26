#pragma once

#include "Struct.h"
#include "Includes.h"

const char* healthColor(Player& player)
{
	if (player.health > 50) return green;
	if (player.health > 20) return yellow;
	if (player.health >= 0) return red;

	return brightRed;
}

void listPlayer(Player& player)
{
	clear();

	cout << "===== CHARACTER EDITOR =====" << endl;
	space();

	cout << "Name: " << player.name << endl;
	cout << "Health: " << healthColor(player) << player.health << reset << endl;
	cout << "Damage: " << player.damage << endl;
	cout << "Level: " << player.level << endl;
	space();
}

void editName(Player* player)
{
	string newName;
	const string nameSnapshot = player->name;

	while (true)
	{
		clear();

		cout << "Current Name: " << player->name << endl;
		space();

		cout << "New Name: ";
		cin >> newName;

		if (newName.empty())
		{
			clear();
			cout << "[!] Name cannot be empty" << endl;
			pause();
			break;
		}

		space();
		player->name = newName;
		cout << "[+] " << green << "Successfully " << reset << "Changed Name From " << nameSnapshot << " -> " << player->name << endl;
		getKey();
		break;
	}
}

void editHealth(Player* player)
{
	int newHealth;
	const int healthSnapshot = player->health;

	while (true)
	{
		clear();

		cout << "Current Health: " << player->health << endl;
		space();

		cout << "New Health: ";
		cin >> newHealth;

		if (input())
		{
			continue;
		}

		space();
		player->health = newHealth;
		cout << "[+] " << green << "Successfully " << reset << "Changed Health from " << healthSnapshot << " -> " << player->health << endl;
		getKey();
		break;
	}
}

void editDamage(Player* player)
{
	int newDamage;
	const int damageSnapshot = player->damage;

	while (true)
	{
		clear();

		cout << "Current Damage: " << player->damage << endl;
		space();

		cout << "New Damage: ";
		cin >> newDamage;

		if (input())
		{
			continue;
		}

		space();
		player->damage = newDamage;
		cout << "[+] " << green << "Successfully Changed Damage from " << damageSnapshot << " -> " << player->damage << endl;
		getKey();
		break;
	}
}

void editLevel(Player* player)
{
	int newLevel;
	const int levelSnapshot = player->level;
	while (true)
	{
		clear();

		cout << "Current Level: " << player->level << endl;
		space();

		cout << "New Level: ";
		cin >> newLevel;

		if (input())
		{
			continue;
		}

		space();
		player->level = newLevel;
		cout << "[+] " << green << "Successfully " << reset << "Changed Level From " << levelSnapshot << "-> " << player->level << endl;
		getKey();
		break;
	}
}