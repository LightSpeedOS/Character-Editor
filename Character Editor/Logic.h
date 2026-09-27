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

void listPlayer(Player& player, vector<Weapon>&weapons)
{
	clear();

	cout << "===== CHARACTER EDITOR =====" << endl;
	space();

	cout << "Name: " << player.name << endl;
	cout << "Health: " << healthColor(player) << player.health << reset << endl;
	cout << "Weapon: " << weapons[player.equippedWeapon].name << " (" << red << weapons[player.equippedWeapon].damage << reset << ")" << endl;
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

void editDamage(Player* player, vector<Weapon>& weapons)
{
	int newDamage;
	const int damageSnapshot = weapons[player->equippedWeapon].damage;

	while (true)
	{
		clear();

		cout << "Current Damage: " << weapons[player->equippedWeapon].damage << endl;
		space();

		cout << "New Damage: ";
		cin >> newDamage;

		if (input())
		{
			continue;
		}

		space();
		weapons[player->equippedWeapon].damage = newDamage;
		cout << "[+] " << green << "Successfully " << reset << "Changed Damage from " << damageSnapshot << " -> " << weapons[player->equippedWeapon].damage << endl;
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

string Search(vector<Weapon>& weapons)
{
	Weapon temp;

	while (true)
	{
		clear();

		for (size_t i = 0; i < weapons.size(); i++)
		{
			cout << "[ " << i << " ] " << weapons[i].name << " (" << green << weapons[i].damage << reset << ")" << endl;
			if (i < weapons.size() - 1) cout << "----------------" << endl;
		}

		space();
		cout << "Enter Weapon Name: ";
		getline(cin, temp.name);

		if (!temp.name.empty()) break;

		space();
		cout << "[!] Error, Input is empty" << endl;
		pause();
	}
	return temp.name;
}

Weapon* findWeapon(vector<Weapon>& weapons, string name)
{
	for (size_t i = 0; i < weapons.size(); i++)
	{
		if (weapons[i].name.find(name) != string::npos)
		{
			return &weapons[i];
		}
	}
	return nullptr;
}

int returnWeaponIndex(vector<Weapon>& weapons, string name)
{
	for (size_t i = 0; i < weapons.size(); i++)
	{
		if (weapons[i].name.find(name) != string::npos)
		{
			return i;
		}
	}
	return -1;
}

void searchWeapon(vector<Weapon>& weapons, Player& player)
{
	cin.ignore();
	string name = Search(weapons);

	Weapon* found = findWeapon(weapons, name);

	if (found == nullptr)
	{
		clear();
		cout << "[!] Weapon Not found!" << endl;
		getKey();

		int result = returnWeaponIndex(weapons, name);
		if (result != -1) int result = returnWeaponIndex(weapons, name);
		else player.equippedWeapon = 3;
	}

	else
	{
		clear();
		cout << "Weapon: " << found->name << endl;
		space();

		cout << "[+] Weapon " << green << "Found" << reset << endl;

		int result = returnWeaponIndex(weapons, name);
		player.equippedWeapon = result;
		getKey();
	}
}

void playerAttack(Player& player, Bot& bot, vector<Weapon>& weapons)
{
	clear();
	const int healthSnapshot = bot.health;
	bot.health -= weapons[player.equippedWeapon].damage;

	if (bot.health <= 0) bot.health = 0;

	cout << "===== Shooting Range =====" << endl;
	space();

	cout << player.name << " Strikes with " << weapons[player.equippedWeapon].name << " -> " << bot.name << ": " << healthSnapshot << " -> " << bot.health << " (" << red << "-" << weapons[player.equippedWeapon].damage << reset << ")" << endl;
	getKey();
}

bool isDead(const Bot& boss)
{
	return boss.health <= 0;
}

void editBot(Bot* bot)
{
	int editMenu;

	while (true)
	{
		clear();

		cout << "===== Bot Menu =====" << endl;
		space();

		cout << "[1] -> Edit Name" << endl;
		cout << "[2] -> Edit Health" << endl;
		cout << "[3] -> Return" << endl;
		space();

		cout << "> ";
		cin >> editMenu;

		if (input())
		{
			continue;
		}

		switch (editMenu)
		{
		case botName:
		{
			clear();
			const string nameSnapshot = bot->name;
			string newName;

			while (true)
			{

				cout << "New Bot Name: ";
				cin.ignore();
				getline(cin, newName);

				if (newName.empty())
				{
					space();
					cout << "[!] Name Cannot be empty" << endl;
					pause();
					break;

				}

				bot->name = newName;
				cout << "[+] " << green << "Successfully " << reset << "Changed Name From " << nameSnapshot << " -> " << bot->name << endl;
				getKey();
				return;
			}
		}

		case botHealth:
		{

			clear();
			const int healthSnapshot = bot->health;
			int newHealth;

			while (true)
			{

				cout << "New Bot Health: ";
				cin >> newHealth;

				if (input())
				{
					continue;
				}

				bot->health = newHealth;
				cout << "[+] " << green << "Successfully " << reset << "Changed Health From" << healthSnapshot << " -> " << bot->health << endl;
				getKey();
				return;
			}
		}

		case 3:
			clear();

			return;;
		}
	}
}


void shootingRange(Player& player, Bot& bot,vector<Weapon>& weapons)
{
	bool range = true;

	while (range)
	{
		clear();

		cout << "===== Shooting Range =====" << endl;
		space();

		cout << bot.name << "   " << bot.health << " HP" << endl;
		space();

		cout << "[H] Hit  [E] Edit  [R] Return" << endl;
		char key = _getch();

		switch (tolower(key))
		{
		case 'h':
			playerAttack(player, bot, weapons);
			if (isDead(bot))
			{
				clear();
				bot.health = 1000;

				cout << "[+] " << bot.name << " is " << red << "Dead!" << reset << endl;
				getKey();
				return;
			}
			break;

		case 'e':
			editBot(&bot);
			break;

		case 'r':
			range = false;
			break;

		default:
			invalid();
			while (_kbhit()) _getch();
			break;
		}
	}
}
