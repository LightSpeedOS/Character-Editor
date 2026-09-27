#include "Includes.h"
#include "Logic.h"
#include "Struct.h"

using namespace std;


auto main() -> int
{

	Player player = {};
	Bot bot = {};
	vector<Weapon>weapons;

	player.name = "Jamaal";
	player.health = 100;
	player.damage = 20;
	player.level = 10;
	player.equippedWeapon = 3;

	bot.name = "Claude";
	bot.health = 1000;

	Weapon ak47;
	ak47.name = "AK-47";
	ak47.damage = 47;
	weapons.push_back(ak47);

	Weapon venator;
	venator.name = "Venator";
	venator.damage = 19;
	weapons.push_back(venator);

	Weapon bobcat;
	bobcat.name = "Bobcat";
	bobcat.damage = 32;
	weapons.push_back(bobcat);

	Weapon fist;
	fist.name = "Fist";
	fist.damage = 1;
	weapons.push_back(fist);

	int mainOption;

	while (true)
	{
		listPlayer(player, weapons);

		cout << "[1] Edit Name" << endl;
		cout << "[2] Edit Health" << endl;
		cout << "[3] Edit Damage" << endl;
		cout << "[4] Edit Level" << endl;
		cout << "[5] List Weapons" << endl;
		cout << "[6] Shooting Range" << endl;
		cout << "[7] Quit" << endl;

		space();
		cout << "> ";
		cin >> mainOption;

		if (input())
		{
			continue;
		}

		switch (mainOption)
		{
		case Name:
			editName(&player);
			break;

		case Health:
			editHealth(&player);
			break;

		case Damage:
			editDamage(&player, weapons);
			break;

		case Level:
			editLevel(&player);
			break;

		case List:
		{
			searchWeapon(weapons, player);
			break;
		}

		case Range:
			shootingRange(player, bot, weapons);
			break;

		case Quit:
			shutDown();
				break;

		default:
			invalid();
			break;
		}
	}
}